#pragma once
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>


template < typename T >
class Matrix
{
private:
	T **_M {} ;
	int _l , _c ;

private:
	inline T rand_lim( T min , T max )
    {
        auto seed = std::chrono::high_resolution_clock::now( ).time_since_epoch( ).count( ) ;
        std::mt19937 mt_rand(seed);

        return ( min + static_cast <T> ( mt_rand( ) ) /( static_cast <T> ( RAND_MAX / ( max - min ) ) ) ) ;
	}

public:
	Matrix( ) { this->_M = nullptr ; this->_l = this->_c = 0 ; }
	~Matrix( ) ;
	void Init( const int l , const int c ) ;
	void Init( const int l , const int c , T [ ] ) ;

	inline int getRowsSize( void ) const { return this->_l ; }
	inline int getColsSize( void ) const { return this->_c ; }
	inline T **data( void ) { return this->_M ; }
	inline bool isEmpty( ) { return ( this->_M == nullptr ) ? true : false ; }

	void printMatrix( const char * , const char * = "a" ) ;

	bool operator==( const Matrix<T> & ) ;
	void operator=( const Matrix<T> & ) ;
	//Matrix operator*( const Matrix & ) ;

	void upperTriangular( void ) ;
	void lowerTriangular( void ) ;
	void triDiagonal( void ) ;
	void toeplitz( void ) ;
	void vandermonde( void ) ;
	void identity( void ) ;

	bool fillRandomMatrix( void ) ;
	bool fillWithZeros( void ) ;

	bool multiply( const Matrix<T> & , Matrix<T> & ) ;
	void matrixBlockMultiply( Matrix<T> & , Matrix<T> & , const int, const int = 2 ) ;
	void matrixBlockMultiply2( Matrix<T> & , Matrix<T> & , const int, const int = 2  ) ;

	void Gauss( T * solution ) ;
	void GaussJordan( T * solution ) ;

};

template <typename T >
Matrix<T>::~Matrix( )
{
    {
        for ( int i = 0 ; i < this->_l ; ++i )
        {
            delete [ ] this->_M [ i ] ;
        }

        delete [ ] this->_M ;
    }
}

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
template < typename  T >
void Matrix<T>::printMatrix( const char *nome , const char *modo )
{
    int i , j ;

    std::ios::openmode _mode ;

    !strcmp( modo , "w" ) ? _mode = ( std::ios::out | std::ios::trunc ) : _mode = ( std::ios::out | std::ios::app );

    std::ofstream file;
    file.open( nome , _mode );

    if ( !file.is_open() )
    {
        fprintf( stderr, "Nao abriu arquivo.\n" ) ;
    }

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
	T **M = this->_M ;

	srand( static_cast< unsigned int >( time( 0 ) ) ) ;
	int a00 = rand_lim( 0 , 15 ) ;


	for ( int k = 0 ; k < L ; ++k )
    {
        for ( int i = 0 ; i < L ; ++i )
        {
            for ( int j = 0 ; j < L ; j++ )
            {
                if ( abs( i - j ) == k )
                {
                    M[ i ][ j ] = ( T ) k + 1 ;
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

template < typename T >
void Matrix<T>::identity( void )
{
    T **M = this->_M ;
    int L = this->_l ;
    int C = this->_c ;

    for ( int i = 0 ; i < L ; ++i )
    {
        for ( int j = 0 ; j < C ; ++j )
        {
            M[ i ][ j ] = ( i== j)? 1 : 0 ;
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
	T sum ;

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
void Matrix<T>::matrixBlockMultiply( Matrix<T> & _B , Matrix<T> & _C , const int n , const int blockSize )
{
	T **A = this->_M ;
	T **B = _B.data( ) ;
	T **C = _C.data( ) ;

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
void Matrix<T>::matrixBlockMultiply2( Matrix<T> & _B , Matrix<T> & _C , const int n , const int blockSize )
{
	int N = n ;
	T **A = this->_M ;
	T **B = _B.data( ) ;
	T **C = _C.data( ) ;

	for ( int bi = 0; bi < N; bi += blockSize )
	{
		for ( int bj = 0; bj < N; bj += blockSize )
		{
			for ( int i = 0; i < N; i++ )
			{
				for ( int j = bi; j < ( ( bi + blockSize ) > N ? N : ( bi + blockSize ) ); j++ )
				{
					T sum = 0;
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
/*void Matrix<T>::Gauss( int *solution )
{

	int **M = this->_M ;
	int L = this->_l ;
	int C = this->_c ;

	for ( int i = 0; i < L - 1; ++i )
	{
		//Partial Pivoting
		for ( int k = i + 1; k < L; ++k )
		{
			//If diagonal element(absolute value) is smaller than any of the terms below it
			if ( fabs( M [ i ][ i ] ) < fabs( M [ k ][ i ] ) )
			{
				//Swap the rows
				for ( int j = 0; j < C; ++j )
				{
					int aux;
					aux = M [ i ][ j ];
					M [ i ][ j ] = M [ k ][ j ];
					M [ k ][ j ] = aux;
				}
			}
		}

		//Begin Gauss Elimination
		for ( int k = i + 1; k < L; k++ )
		{
			int  term = M [ k ][ i ] / M [ i ][ i ];
			for ( int j = 0; j < C; j++ )
			{
				M [ k ][ j ] = M [ k ][ j ] - term * M [ i ][ j ];
			}
		}

	}
	//Begin Back-substitution
	for ( int i = L - 1; i >= 0; --i )
	{
		solution [ i ] = M [ i ][ C - 1 ];
		for ( int j = i + 1; j < C - 1; j++ )
		{
			solution [ i ] = solution [ i ] - M [ i ][ j ] * solution [ j ];
		}
		solution [ i ] = solution [ i ] / M [ i ][ i ];
	}

}*/
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