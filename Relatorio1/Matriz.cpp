#include "Matriz.h"

#include <time.h>
#include <stdlib.h>
#include <String.h>

int rand_lim( int limit )
{
	int divisor = RAND_MAX / ( limit + 1 );
	int res;

	do
	{
		res = rand( ) / divisor;
	} while ( res > limit );

	return res ;
}

Matrix::~Matrix( )
{
	for ( int i = 0 ; i < this->_l ; ++i )
	{
		delete [ ] this->_M [ i ] ;
	}

	delete [ ] this->_M ;
}

void Matrix::Init( int l , int c )
{
	this->_l = l ;
	this->_c = c ;

	this->_M = new int *[ l ] ;

	for ( int i = 0 ; i < l ; ++i )
	{
		this->_M [ i ] = new int [ c ] ;
	}
}

bool Matrix::operator==( const Matrix &B )
{
	return ( this->_l == B.getRowsSize( ) && this->_c == B.getColsSize( ) ) ;
}

void Matrix::operator=( const Matrix & B )
{
	int L = this->_l , C = this->_c ;

	for ( int i = 0 ; i < L ; ++i )
	{
		memcpy( this->_M [ i ] , B._M [ i ] , ( C * ( sizeof( int ) ) ) ) ;
	}

}

Matrix Matrix::operator*( const Matrix & B )
{
	if ( this->_c != B.getRowsSize( ) )
	{
		return Matrix( ) ;
	}

	const int l = this->_l , c = B.getColsSize( ) , lc = B.getRowsSize( ) ;
	int  sum ;

	Matrix *C = new Matrix( ) ;
	C->Init( l , c ) ;

	for ( int i = 0 ; i < l ; ++i )
	{
		for ( int j = 0 ; j < c ; ++j )
		{
			sum = 0 ;
			for ( int k = 0; k < lc ; ++k )
			{
				sum += ( this->_M [ i ][ k ] * B._M [ k ][ j ] ) ;
			}

			C->_M [ i ][ j ] = sum ;
		}
	}

	return *C ;
}

bool Matrix::multiply( const Matrix & B , Matrix & C )
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


bool Matrix::fillRandomMatrix( void )
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
			this->_M [ i ][ j ] = rand_lim( 15 ) ;
		}
	}

	return true ;
}

bool Matrix::fillWithZeros( void )
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

void Matrix::matrixBlockMultiply( Matrix & _B , Matrix & _C , const int n )
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

void Matrix::matrixBlockMultiply2( Matrix & _B , Matrix & _C , const int n )
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

//void gaussEliminationLS( int L , int C , int **M , int *solution )
void Matrix::Gauss( int *solution )
{

	int **M = this->_M ;
	int L = this->_l ;
	int C = this->_c ;

	int i , j , k;

	for ( i = 0; i < L - 1; ++i )
	{
		//Partial Pivoting
		for ( k = i + 1; k < L; ++k )
		{
			//If diagonal element(absolute value) is smaller than any of the terms below it
			if ( fabs( M [ i ][ i ] ) < fabs( M [ k ][ i ] ) )
			{
				//Swap the rows
				for ( j = 0; j < C; ++j )
				{
					int aux;
					aux = M [ i ][ j ];
					M [ i ][ j ] = M [ k ][ j ];
					M [ k ][ j ] = aux;
				}
			}
		}

		//Begin Gauss Elimination
		for ( k = i + 1; k < L; k++ )
		{
			int  term = M [ k ][ i ] / M [ i ][ i ];
			for ( j = 0; j < C; j++ )
			{
				M [ k ][ j ] = M [ k ][ j ] - term * M [ i ][ j ];
			}
		}

	}
	//Begin Back-substitution
	for ( i = L - 1; i >= 0; --i )
	{
		solution [ i ] = M [ i ][ C - 1 ];
		for ( j = i + 1; j < C - 1; j++ )
		{
			solution [ i ] = solution [ i ] - M [ i ][ j ] * solution [ j ];
		}
		solution [ i ] = solution [ i ] / M [ i ][ i ];
	}

}

void Matrix::GaussJordan( int *solution )
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