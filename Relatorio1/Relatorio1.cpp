// Relatorio1.cpp
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Matriz.h"
#include "Exercicio01.h"

#define filename "d:/Exercicio02.txt"

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
	int s = 2 ;
	int sum ;

	for ( int jj = 0; jj < N; jj += s )
	{
		for ( int kk = 0; kk < N; kk += s )
		{
			for ( int i = 0; i < N; i++ )
			{
				for ( int j = jj; j < ( ( jj + s ) > N ? N : ( jj + s ) ); j++ )
				{
					sum = 0;
					for ( int k = kk; k < ( ( kk + s ) > N ? N : ( kk + s ) ); k++ )
					{
						sum += A [ i ][ k ] * B [ k ][ j ];
					}
					C [ i ][ j ] += sum;
				}
			}
		}
	}

}

//struct _Matriz
//{
//	int **M = NULL ;
//	int l , c ;
//
//	void Constroi( const int l , const int c )
//	{
//		this->M = ( int ** ) malloc( l * sizeof( int * ) );
//		for ( int i = 0; i < l; i++ )
//		{
//			this->M [ i ] = ( int * ) malloc( c * sizeof( int ) ) ;
//		}
//
//		this->l = l ;
//		this->c = c ;
//	}
//
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
//	void Destroi( void )
//	{
//		if ( !this->Vazia( ) )
//			free( this->M ) ;
//	}
//
//	int Vazia( )
//	{
//		return ( this->M == NULL ) ? 1 : 0 ;
//	}
//
//	void imprimeMatriz( const char *nome )
//	{
//		int i , j ;
//
//		FILE *file = fopen( nome , "a" ) ;
//
//		for ( i = 0 ; i < this->l ; ++i )
//		{
//			for ( j = 0 ; j < this->c ; ++j )
//			{
//				fprintf( file , "%d ," , this->M [ i ][ j ] ) ;
//			}
//			fprintf( file , "\n" ) ;
//		}
//
//		fprintf( file , "\n" ) ;
//
//		fclose( file ) ;
//	}
//
//	struct _Matriz Multiplica( const struct _Matriz B )
//	{
//
//		struct _Matriz C ;
//
//		if ( this->c != B.l )
//		{
//			fprintf( stderr , "Dimensoes diferentes\n" );
//			return C ;
//		}
//
//		C.Constroi( this->c , B.l ) ;
//
//		const int l = this->l , c = B.c , lc = B.l ;
//		int i , j , k , sum ;
//
//		for ( i = 0 ; i < l ; ++i )
//		{
//			for ( j = 0 ; j < c ; ++j )
//			{
//				for ( sum = 0 , k = 0; k < lc ; ++k )
//				{
//					sum += ( this->M [ i ][ k ] * B.M [ k ][ j ] ) ;
//				}
//
//				C.M [ i ][ j ] = sum ;
//				sum = 0 ;
//			}
//		}
//
//		return C ;
//	}
//
//} ;
//typedef struct _Matriz Matriz ;

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

