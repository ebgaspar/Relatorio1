#pragma once
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include <iostream>
#include <fstream>
#include <iomanip>

template < typename T >
class Matrix
{
private:
	T **_M {} ;
	int _l , _c ;

private:
	inline T rand_lim( T min , T max )
	{
		T scale = rand( ) / ( T ) RAND_MAX;
		return min + scale * ( max - min );
	}

public:
	Matrix( ) { this->_M = nullptr ; this->_l = this->_c = 0 ; }
	~Matrix( )
	{
		{
			for ( int i = 0 ; i < this->_l ; ++i )
			{
				delete [ ] this->_M [ i ] ;
			}

			delete [ ] this->_M ;
		}
	}
	void Init( const int l , const int c ) ;
	void Init( const int l , const int c , T [ ] ) ;

	inline int getRowsSize( void ) const { return this->_l ; }
	inline int getColsSize( void ) const { return this->_c ; }
	inline int **data( void ) { return this->_M ; }

	//	void Constroi( const int l , const int c , int mat[ ][ 4 ] )
	//	{
	//		int size = ( sizeof( int * ) * l ) + ( sizeof( int ) * c * l ) ;
	//		this->M = ( int ** ) malloc( size );
	//		this->l = l ;
	//		this->c = c ;
	//
	//		//for ( int i = 0 ; i < l ; i++ )
	//		//{
	//		//	memcpy( this->M [ i ] , mat [ i ] , ( c * sizeof( int ) ) ) ;
	//		//}
	//
	//		for ( int i = 0 ; i < l ; ++i )
	//		{
	//			for ( int j = 0 ; j < c ; ++j )
	//			{
	//				M [ i ][ j ] = mat [ i ][ j ] ;
	//			}
	//		}
	//	}
	//

	inline bool isEmpty( void ) { return ( this->_M == nullptr ) ? true : false ; }

	void printMatrix( const char *nome , const char *modo = 'a' )
	{
		int i , j ;

		int _mode ;

		( *modo == 'w' ) ? _mode = ( std::ios::out | std::ios::trunc ) : _mode = ( std::ios::out | std::ios::app );

		std::ofstream file;
		file.open( nome , _mode );

		for ( i = 0 ; i < this->_l ; ++i )
		{
			for ( j = 0 ; j < this->_c ; ++j )
			{
				file << std::fixed << std::setprecision( 2 ) << this->_M [ i ][ j ] << " ," ;
			}
			file << std::endl ;
		}
		file.seekp( -3 , std::ios::cur ) ;
		file << std::endl ;

		file.close( );
	}

	bool operator==( const Matrix<T> & ) ;
	void operator=( const Matrix<T> & ) ;
	//Matrix operator*( const Matrix & ) ;

	void upperTriangular( void ) ;
	void lowerTriangular( void ) ;
	void triDiagonal( void ) ;
	void toeplitz( void ) ;
	void vandermonde( void ) ;

	bool fillRandomMatrix( void ) ;
	bool fillWithZeros( void ) ;

	bool multiply( const Matrix<T> & , Matrix<T> & ) ;
	void matrixBlockMultiply( Matrix<T> & , Matrix<T> & , const int ) ;
	void matrixBlockMultiply2( Matrix<T> & , Matrix<T> & , const int ) ;

	void Gauss( T * solution ) ;
	void GaussJordan( T * solution ) ;

};


template <typename T >
void Matrix<T>::Init( const int l , const int c )
{
	this->_l = l ;
	this->_c = c ;

	this->_M = new T * [ l ] ;

	for ( int i = 0 ; i < l ; ++i )
	{
		this->_M [ i ] = new T [ c ] ;
	}
}

template <typename T >
void Matrix<T>::Init( const int l , const int c , T B [ ] )
{
	this->_l = l ;
	this->_c = c ;
	this->_M = new T * [ l ] ;

	for ( int i = 0 ; i < l ; ++i )
	{
		this->_M [ i ] = new T [ c ] ;
		for ( int j = 0 ; j < c ; ++j )
		{
			this->_M [ i ][ j ] = B [ ( i * c ) + j ] ;
		}
	}
}

template <typename T >
bool Matrix<T>::operator==( const Matrix<T> & B )
{
	return ( this->_l == B.getRowsSize( ) && this->_c == B.getColsSize( ) ) ;
}

template <typename T >
void Matrix<T>::operator=( const Matrix<T> & B )
{
	int L = this->_l , C = this->_c ;

	for ( int i = 0 ; i < L ; ++i )
	{
		memcpy( this->_M [ i ] , B._M [ i ] , ( C * ( sizeof( int ) ) ) ) ;
	}

}

//template <typename T >
//Matrix<T> Matrix<T>::operator*( const Matrix<T> &B )
//{
//	if ( this->_c != B.getRowsSize( ) )
//	{
//		return Matrix<T>( ) ;
//	}
//
//	const int l = this->_l , c = B.getColsSize( ) , lc = B.getRowsSize( ) ;
//	int  sum ;
//
//	Matrix *C = new Matrix<T>( ) ;
//	C->Init( l , c ) ;
//
//	for ( int i = 0 ; i < l ; ++i )
//	{
//		for ( int j = 0 ; j < c ; ++j )
//		{
//			sum = 0 ;
//			for ( int k = 0; k < lc ; ++k )
//			{
//				sum += ( this->_M [ i ][ k ] * B._M [ k ][ j ] ) ;
//			}
//
//			C->_M [ i ][ j ] = sum ;
//		}
//	}
//
//	return *C ;
//}

template <typename T >
void Matrix<T>::upperTriangular( void )
{
	int C = this->_c ;
	int L = this->_l ;
	int **M = this->_M ;

	srand( static_cast< unsigned int >( time( 0 ) ) ) ;

	for ( int i = 0 ; i < L ; ++i )
	{
		for ( int j = 0 ; j < C ; j++ )
		{
			( i == j || i < j ) ? M [ i ][ j ] = rand_lim( 15 ) : M [ i ][ j ] = 0 ;
		}
	}
}

template <typename T >
void Matrix<T>::lowerTriangular( void )
{
	int C = this->_c ;
	int L = this->_l ;
	int **M = this->_M ;

	srand( static_cast< unsigned int >( time( 0 ) ) ) ;

	for ( int i = 0 ; i < L ; ++i )
	{
		for ( int j = 0 ; j < C ; j++ )
		{
			( i == j || i > j ) ? M [ i ][ j ] = rand_lim( 15 ) : M [ i ][ j ] = 0 ;
		}
	}
}

template <typename T >
void Matrix<T>::triDiagonal( void )
{
	int C = this->_c ;
	int L = this->_l ;
	int **M = this->_M ;

	srand( static_cast< unsigned int >( time( 0 ) ) ) ;

	for ( int i = 0 ; i < L ; ++i )
	{
		for ( int j = 0 ; j < C ; j++ )
		{
			( i == j || i == j + 1 || i + 1 == j ) ? M [ i ][ j ] = rand_lim( 15 ) : M [ i ][ j ] = 0 ;
		}
	}
}

template <typename T >
void Matrix<T>::toeplitz( void )
{
	int C = this->_c ;
	int L = this->_l ;
	int **M = this->_M ;

	srand( static_cast< unsigned int >( time( 0 ) ) ) ;
	int a00 = rand_lim( 15 ) ;

	for ( int i = 0 ; i < L ; ++i )
	{
		for ( int j = 0 ; j < C ; j++ )
		{
			if ( i == j )
			{
				M [ i ][ j ] = a00 ;
			}
			else
			{
				if ( i < j )
				{
					M [ i ][ j ] = a00 - j - i ;
				}
				else
				{
					M [ i ][ j ] = a00 + j + i ;
				}
			}
		}
	}
}

template <typename T >
void Matrix<T>::vandermonde( void )
{
	int C = this->_c ;
	int L = this->_l ;
	int **M = this->_M ;

	int *array = new int [ L ] ;
	for ( int i = 0 ; i < L ; ++i )
		array [ i ] = i + 1 ;

	for ( int i = 0 ; i < L ; ++i )
	{
		for ( int j = 0 ; j < C ; ++j )
		{
			M [ i ][ j ] = ( int ) pow( array [ i ] , ( L - j - 1 ) );
		}
	}
}

template <typename T >
bool Matrix<T>::fillRandomMatrix( void )
{
	if ( this->isEmpty( ) )
	{
		return false ;
	}

	srand( static_cast< unsigned int >( time( 0 ) ) ) ;

	for ( int i = 0 ; i < this->_l ; ++i )
	{
		for ( int j = 0 ; j < this->_c ; ++j )
		{
			//this->_M [ i ][ j ] = ( rand( ) % 15 ) + 1 ;
			this->_M [ i ][ j ] = rand_lim( ( T ) 1 , ( T ) 15 ) ;
		}
	}

	return true ;
}

template <typename T >
bool Matrix<T>::fillWithZeros( void )
{
	if ( this->isEmpty( ) )
	{
		return false ;
	}
	int L = this->_l , C = this->_c ;

	for ( int i = 0 ; i < L ; ++i )
	{
		memset( this->_M [ i ] , 0 , ( C * ( sizeof( int ) ) ) ) ;
	}

	return true ;
}

template <typename T >
bool Matrix<T>::multiply( const Matrix<T> & B , Matrix<T> & C )
{
	if ( this->_c != B.getRowsSize( ) )
	{
		return false ;
	}

	const int l = this->_l , c = B.getColsSize( ) , lc = B.getRowsSize( ) ;
	int sum ;

	for ( int i = 0 ; i < l ; ++i )
	{
		for ( int j = 0 ; j < c ; ++j )
		{
			sum = 0 ;
			for ( int k = 0; k < lc ; ++k )
			{
				sum += ( this->_M [ i ][ k ] * B._M [ k ][ j ] ) ;
			}

			C._M [ i ][ j ] = sum ;
		}
	}

	return true ;
}

template <typename T >
void Matrix<T>::matrixBlockMultiply( Matrix<T> & _B , Matrix<T> & _C , const int n )
{
	int blockSize = n / 2 ;// block;
	int **A = this->_M ;
	int **B = _B.data( ) ;
	int **C = _C.data( ) ;

	for ( int bi = 0 ; bi < n ; bi += blockSize )
	{
		for ( int bj = 0 ; bj < n ; bj += blockSize )
		{
			for ( int bk = 0 ; bk < n ; bk += blockSize )
			{
				for ( int i = 0 ; i < blockSize ; i++ )
				{
					for ( int j = 0 ; j < blockSize ; j++ )
					{
						for ( int k = 0 ; k < blockSize ; k++ )
						{
							C [ bi + i ][ bj + j ] += A [ bi + i ][ bk + k ] * B [ bk + k ][ bj + j ];
						}

					}
				}
			}
		}
	}

}

template <typename T >
void Matrix<T>::matrixBlockMultiply2( Matrix<T> & _B , Matrix<T> & _C , const int n )
{
	int N = n ;
	int blockSize = n / 2 ;
	int **A = this->_M ;
	int **B = _B.data( ) ;
	int **C = _C.data( ) ;

	for ( int bi = 0; bi < N; bi += blockSize )
	{
		for ( int bj = 0; bj < N; bj += blockSize )
		{
			for ( int i = 0; i < N; i++ )
			{
				for ( int j = bi; j < ( ( bi + blockSize ) > N ? N : ( bi + blockSize ) ); j++ )
				{
					int sum = 0;
					for ( int k = bj; k < ( ( bj + blockSize ) > N ? N : ( bj + blockSize ) ); k++ )
					{
						sum += A [ i ][ k ] * B [ k ][ j ];
					}
					C [ i ][ j ] += sum;
				}
			}
		}
	}

}

template <typename T >
//void Matrix<T>::Gauss( int *solution )
//{
//
//	int **M = this->_M ;
//	int L = this->_l ;
//	int C = this->_c ;
//
//	for ( int i = 0; i < L - 1; ++i )
//	{
//		//Partial Pivoting
//		for ( int k = i + 1; k < L; ++k )
//		{
//			//If diagonal element(absolute value) is smaller than any of the terms below it
//			if ( fabs( M [ i ][ i ] ) < fabs( M [ k ][ i ] ) )
//			{
//				//Swap the rows
//				for ( int j = 0; j < C; ++j )
//				{
//					int aux;
//					aux = M [ i ][ j ];
//					M [ i ][ j ] = M [ k ][ j ];
//					M [ k ][ j ] = aux;
//				}
//			}
//		}
//
//		//Begin Gauss Elimination
//		for ( int k = i + 1; k < L; k++ )
//		{
//			int  term = M [ k ][ i ] / M [ i ][ i ];
//			for ( int j = 0; j < C; j++ )
//			{
//				M [ k ][ j ] = M [ k ][ j ] - term * M [ i ][ j ];
//			}
//		}
//
//	}
//	//Begin Back-substitution
//	for ( int i = L - 1; i >= 0; --i )
//	{
//		solution [ i ] = M [ i ][ C - 1 ];
//		for ( int j = i + 1; j < C - 1; j++ )
//		{
//			solution [ i ] = solution [ i ] - M [ i ][ j ] * solution [ j ];
//		}
//		solution [ i ] = solution [ i ] / M [ i ][ i ];
//	}
//
//}
void Matrix<T>::Gauss( T * solution )
{
	T **M = this->_M ;
	int L = this->_l ;
	int C = this->_c ;

	T elem ; // numero para zerar o valor da parte inferior

	// Gera triangular superior
	for ( int j = 0; j < L ; j++ )
	{
		for ( int i = 0; i < L ; i++ )
		{
			if ( i > j )
			{
				elem = M [ i ][ j ] / M [ j ][ j ];
				for ( int k = 0; k <= L ; k++ )
				{
					M [ i ][ k ] -= elem * M [ j ][ k ];
				}
			}
		}
	}
	solution [ L - 1 ] = M [ L - 1 ][ L ] / M [ L - 1 ][ L - 1 ];

	// retirna resolvendo
	T soma ;
	for ( int i = L - 2 ; i >= 0 ; i-- )
	{
		soma = 0;
		for ( int j = i + 1 ; j < L ; j++ )
		{
			soma += M [ i ][ j ] * solution [ j ];
		}
		solution [ i ] = ( M [ i ][ L ] - soma ) / M [ i ][ i ];
	}

}

template <typename T >
void Matrix<T>::GaussJordan( T * solution )
{
	int **A = this->_M ;
	int N = this->_l ;

	for ( int j = 0 ; j < N ; ++j )
	{
		for ( int i = 0 ; i < N ; ++i )
		{
			if ( i != j )
			{
				int c = A [ i ][ j ] / A [ j ][ j ] ;
				for ( int k = 0 ; k <= N ; ++k )
				{
					A [ i ][ k ] -= c * A [ j ][ k ] ;
				}
			}
		}
	}

	for ( int i = 0 ; i < N ; ++i )
	{
		solution [ i ] = A [ i ][ N ] / A [ i ][ i ] ;
	}
}