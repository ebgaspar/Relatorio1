// Relatorio1.cpp
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Matriz.h"
#include "Exercicio01.h"

#define filename "d:/Exercicio02.txt"

/*
void matrixBlockMultiply( const int A [ ][ 4 ] , const int B [ ][ 4 ] , int C [ ][ 4 ] , const int n )
{
	int bi = 0 ;
	int bj = 0 ;
	int bk = 0 ;
	int i = 0 ;
	int j = 0 ;
	int k = 0 ;
	int blockSize = 2 ;// block;

	for ( bi = 0 ; bi < n ; bi += blockSize )
	{
		for ( bj = 0 ; bj < n ; bj += blockSize )
		{
			for ( bk = 0 ; bk < n ; bk += blockSize )
			{
				for ( i = 0 ; i < blockSize ; i++ )
				{
					for ( j = 0 ; j < blockSize ; j++ )
					{
						for ( k = 0 ; k < blockSize ; k++ )
						{
							C [ bi + i ][ bj + j ] += A [ bi + i ][ bk + k ] * B [ bk + k ][ bj + j ];
						}
					}
				}
			}
		}
	}

}
void matrixBlockMultiply( const int A [ ][ 4 ] , const int B [ ][ 4 ] , int C [ ][ 4 ] , const int l, const int c )
{
	int N = l ;
	int blocksize = 2 ;

	for ( int jj = 0; jj < N; jj += blocksize )
	{
		for ( int kk = 0; kk < N; kk += blocksize )
		{
			for ( int i = 0; i < N; i++ )
			{
				for ( int j = jj; j < ( ( jj + blocksize ) > N ? N : ( jj + blocksize ) ); j++ )
				{
					int sum = 0;
					for ( int k = kk; k < ( ( kk + blocksize ) > N ? N : ( kk + blocksize ) ); k++ )
					{
						sum += A [ i ][ k ] * B [ k ][ j ];
					}
					C [ i ][ j ] += sum;
				}
			}
		}
	}

}
*/


int main( )
{
	//Exercicio01( ) ;
	//const int m = 4 , n = 4 ;
	//int A [ m ][ n ] = { { 2 ,3 ,-1 ,2 }, { 0, 4, -3 ,5 }, { 1, 2, 1, 3 }, { 0, 4, 1, 0 } } ;
	//int B [ m ][ n ] = { { 2, -3, 4, 11 }, { 7, 6, 1, 2 }, { 2, -5, 5, 8 }, { 7, 2, -3, -4 } } ;
	//int C [ m ][ n ] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } } ;
	//matrixMuliply( A , B , C , m , n ) ;
	//memset( C , 0 , m * n * ( sizeof( int ) ) ) ;
	//matrixBlockMultiply( A , B , C , m ) ;
	//memset( C , 0 , m * n * ( sizeof( int ) ) ) ;
	//matrixBlockMultiply( A , B , C , m , n ) ;

	Matrix A , B ;
	A.Init( 4 , 4 ) ;
	A.fillRandomMatrix( ) ;

	B.Init( 4 , 4 ) ;
	B.fillRandomMatrix( ) ;

	Matrix C ;
	C.Init( 4 , 4 ) ;
	C.fillWithZeros( ) ;

	C = A * B ;

	A.printMatrix( filename , "w" ) ;
	B.printMatrix( filename ) ;
	C.printMatrix( filename ) ;

	C.fillWithZeros( ) ;
	A.matrixBlockMultiply( B.data( ) , C.data( ) , 4 ) ;
	C.printMatrix( filename ) ;

	return 0;
}

