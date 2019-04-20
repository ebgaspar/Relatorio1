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

void Matrix::operator=( const Matrix &B )
{
	int L = this->_l , C = this->_c ;

	for ( int i = 0 ; i < L ; ++i )
	{
		memcpy( this->_M [ i ] , B._M[ i ] , ( C * ( sizeof( int ) ) ) ) ;
	}

}

Matrix Matrix::operator*( const Matrix &B )
{
	if ( this->_c != B.getRowsSize( ) )
	{
		return Matrix() ;
	}

	const int l = this->_l , c = B.getColsSize( ) , lc = B.getRowsSize( ) ;
	int i , j , k , sum ;

	Matrix *C = new Matrix( ) ;
	C->Init( l, c ) ;

	for ( i = 0 ; i < l ; ++i )
	{
		for ( j = 0 ; j < c ; ++j )
		{
			for ( sum = 0 , k = 0; k < lc ; ++k )
			{
				sum += ( this->_M [ i ][ k ] * B._M [ k ][ j ] ) ;
			}

			C->_M [ i ][ j ] = sum ;
			sum = 0 ;
		}
	}

	return *C ;
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

void Matrix::matrixBlockMultiply( int **B, int **C , const int n )
{
	int blockSize = 2 ;// block;
	int **A = this->_M ;

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

void Matrix::Gauss( void )
{
	int i , j , k ;
	int n = this->_l ;
	int **A = this->_M ;
	float  c , x [ 10 ] , sum = 0.0 ;

	/* loop for the generation of upper triangular matrix*/
	for ( j = 1 ; j <= n ; j++ ) 
	{
		for ( i = 1 ; i <= n ; i++ )
		{
			if ( i > j )
			{
				c = A [ i ][ j ] / A [ j ][ j ] ;

				for ( k = 1 ; k <= n + 1 ; k++ )
				{
					A [ i ][ k ] = A [ i ][ k ] - c * A [ j ][ k ] ;
				}
			}
		}
	}
	x [ n ] = A [ n ][ n + 1 ] / A [ n ][ n ] ;

	/* this loop is for backward substitution*/
	for ( i = n - 1; i >= 1; i-- )
	{
		sum = 0 ;

		for ( j = i + 1 ; j <= n ; j++ )
		{
			sum = sum + A [ i ][ j ] * x [ j ] ;
		}

		x [ i ] = ( A [ i ][ n + 1 ] - sum ) / A [ i ][ i ] ;
	}
	printf( "\nThe solution is: \n" );
	for ( i = 1; i <= n; i++ )
	{
		printf( "\nx%d=%f\t" , i , x [ i ] ); /* x1, x2, x3 are the required solutions*/
	}
}
