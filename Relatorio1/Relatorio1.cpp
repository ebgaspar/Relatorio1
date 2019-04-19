// Relatorio1.cpp
//
#include <stdio.h>
#include <stdlib.h>

#include "Exercicio01.h"

//void matrixMuliply ( void )
//{
//	const int m = 4 , n = 4 , p = 4 ;
//	int k , sum ;
//	int A [ m ][ n ] = { { 2 ,3 ,-1 ,2 }, { 0, 4, -3 ,5 }, { 1, 2, 1, 3 }, { 0, 4, 1, 0 } } ;
//	int B [ m ][ n ] = { { 2, -3, 4, 11 }, { 7, 6, 1, 2 }, { 2, -5, 5, 8 }, { 7, 2, -3, -4 } } ;
//	int C [ m ][ n ] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } } ;
//
//	//if ( n != p )
//	//{
//	//	fprintf( stdout, "Dimensoes diferentes\n" );
//	//	return ;
//	//}
//
//	int i , j ;
//	for ( i = 0; i < m; ++i )
//	{
//		for ( j = 0; j < n; ++j )
//		{
//			for ( sum = 0 , k = 0; k < p; ++k )
//			{
//				sum += ( A [ i ][ k ] * B [ k ][ j ] ) ;
//			}
//
//			C [ i ][ j ] = sum ;
//			sum = 0 ;
//		}
//	}
//
//}

void matrixBlockMultiply ( int n , int **A , int **B , int **C )
{
	int bi = 0;
	int bj = 0;
	int bk = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int blockSize = 5;// block;

	for ( bi = 0; bi < n; bi += blockSize )
	{
		for ( bj = 0; bj < n; bj += blockSize )
		{
			for ( bk = 0; bk < n; bk += blockSize )
			{
				for ( i = 0; i < blockSize; i++ )
				{
					for ( j = 0; j < blockSize; j++ )
					{
						for ( k = 0; k < blockSize; k++ )
						{
							C [ bi + i ][ bj + j ] += A [ bi + i ][ bk + k ] * B [ bk + k ][ bj + j ];
						}
					}
				}
			}
		}
	}
}

struct _Matriz
{
	int **M ;
	int l , c ;

	void Constroi ( const int l , const int c )
	{
		int size = ( sizeof ( int * ) * l ) + ( sizeof ( int ) * c * l ) ;
		M = ( int ** ) malloc ( size );
		this->l = l ;
		this->c = c ;
	}

	void Destroi ( void )
	{
		free ( this->M ) ;
	}

	void imprimeMatriz ( const char *nome )
	{
		int i , j ;

		FILE *file = fopen ( nome , "a" ) ;

		for ( i = 0 ; i < m ; ++i )
		{
			for ( j = 0 ; j < n ; ++j )
			{
				fprintf ( file , "%d ," , M [ i ][ j ] ) ;
			}
			fprintf ( file , "\n" ) ;
		}

		fprintf ( file , "\n" ) ;

		fclose ( file ) ;
	}

	Matriz Multiplica ( Matriz B )
	{
		//	const int m = 4 , n = 4 , p = 4 ;
//	int k , sum ;
//	int A [ m ][ n ] = { { 2 ,3 ,-1 ,2 }, { 0, 4, -3 ,5 }, { 1, 2, 1, 3 }, { 0, 4, 1, 0 } } ;
//	int B [ m ][ n ] = { { 2, -3, 4, 11 }, { 7, 6, 1, 2 }, { 2, -5, 5, 8 }, { 7, 2, -3, -4 } } ;
//	int C [ m ][ n ] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } } ;
//
		Matriz C ;
		C.Constroi ( this->c , B. ) ;

//	//if ( n != p )
//	//{
//	//	fprintf( stdout, "Dimensoes diferentes\n" );
//	//	return ;
//	//}
//
//	int i , j ;
//	for ( i = 0; i < m; ++i )
//	{
//		for ( j = 0; j < n; ++j )
//		{
//			for ( sum = 0 , k = 0; k < p; ++k )
//			{
//				sum += ( A [ i ][ k ] * B [ k ][ j ] ) ;
//			}
//
//			C [ i ][ j ] = sum ;
//			sum = 0 ;
//		}
//	}
	}
} ;

typedef struct _Matriz Matriz ;

int main ( )
{
	Exercicio01 ( ) ;

	int m = 4 , int n = 4 ;

	Matriz A , B , C ;
	A.Constroi ( 4 , 4 ) ;
	B.Constroi ( 4 , 4 ) ;
	C.Constroi ( 4 , 4 ) ;


	matrixMuliply ( ) ;


	return 0;
}

