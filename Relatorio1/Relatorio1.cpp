// Relatorio1.cpp : Defines the entry point for the console application.
//
#include <math.h>
#include <stdio.h>

#include <fstream>
#include <iostream>

#define TOLERANCE 0.00000000000001

template < typename T >
void Bhaskara ( const T a , const T b , const T c , T *x1 , T *x2 )
{
	T delta = pow ( b , 2 ) - 4 * a *c ;

	*x1 = ( ( -b ) + sqrt ( delta ) ) / ( 2 * a ) ;
	*x2 = ( ( -b ) - sqrt ( delta ) ) / ( 2 * a ) ;
}

template < typename T >
void Fatorado ( const T a , const T b , const T c , T *x1 , T *x2 )
{
	T delta = pow ( b , 2 ) - 4 * a *c ;

	*x1 = ( -2 * c ) / ( ( -b ) + sqrt ( delta ) ) ;
	*x2 = c / ( a * *x1 ) ;
}

void printMatrix ( const int *M[], const int , const int ) ;

void matrixMuliply ( void )
{
	const int m = 4 , n = 4 , p = 4 ;
	int k , sum = 0 ;
	int *A[] = { { 2 ,3 ,-1 ,2 }, { 0, 4, -3 ,5 }, { 1, 2, 1, 3 }, { 0, 4, 1, 0 } } ;
	int *B[] = { { 2, -3, 4, 11 }, { 7, 6, 1, 2 }, { 2, -5, 5, 8 }, { 7, 2, -3, -4 } } ;
	int *C[] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } } ;

	//if ( n != p )
	//{
	//	fprintf( stdout, "Dimensoes diferentes\n" );
	//	return ;
	//}

	int i , j ;
	for ( i = 0; i < m; ++i )
	{
		for ( j = 0; j < n; ++j )
		{
			for ( k = 0; k < p; ++k )
			{
				sum += ( A[ i ][ k ] * B[ k ][ j ] ) ;
			}

			C[ i ][ j ] = sum ;
			sum = 0 ;
		}
	}

	printMatrix ( A , m , n ) ;
	printMatrix ( B , m , n ) ;
	printMatrix ( C , m , n ) ;

}

void matrixBlockMultiply ( int n , double** a , double** b , double** c )
{
	int bi = 0;
	int bj = 0;
	int bk = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int blockSize = 5;// block;

	for ( bi = 0; bi < n; bi += blockSize )
		for ( bj = 0; bj < n; bj += blockSize )
			for ( bk = 0; bk < n; bk += blockSize )
				for ( i = 0; i < blockSize; i++ )
					for ( j = 0; j < blockSize; j++ )
						for ( k = 0; k < blockSize; k++ )
							c[ bi + i ][ bj + j ] += a[ bi + i ][ bk + k ] * b[ bk + k ][ bj + j ];
}

void Exercicio01 ( void )
{
	FILE *file = fopen ( "d:/Exercicio01.txt" , "w" ) ;

	int iA , iB , iC , iX1 , iX2 ;

	iA = 1 ;
	iB = pow ( -10 , 5 ) ;
	iC = 1 ;

	fprintf ( file , "LETRA A\n" ) ;
	fprintf ( file , "#############\tINTEGER\t#############\n" ) ;

	//iBhaskara( iA , iB , iC , &iX1 , &iX2 ) ;
	Bhaskara ( iA , iB , iC , &iX1 , &iX2 ) ;
	fprintf ( file , "Bhaskara:\t%d\t%d\n" , iX1 , iX2 ) ;

	//iFatorado( iA , iB , iC , &iX1 , &iX2 ) ;
	Fatorado ( iA , iB , iC , &iX1 , &iX2 ) ;
	fprintf ( file , "Fatorado:\t%d\t%d\n" , iX1 , iX2 ) ;

	float fA , fB , fC , fX1 , fX2 ;

	fA = 1.0f ;
	fB = pow ( -10 , 5 ) ;
	fC = 1.0f ;

	fprintf ( file , "\n#############\tFLOAT\t#############\n" ) ;

	//fBhaskara( fA , fB , fC, &fX1 , &fX2 ) ;
	Bhaskara ( fA , fB , fC , &fX1 , &fX2 ) ;
	fprintf ( file , "Bhaskara:\t%f\t%f\n" , fX1 , fX2 ) ;

	//fFatorado( fA , fB , fC , &fX1 , &fX2 ) ;
	Fatorado ( fA , fB , fC , &fX1 , &fX2 ) ;
	fprintf ( file , "Fatorado:\t%f\t%f\n" , fX1 , fX2 ) ;

	double dA , dB , dC , dX1 , dX2 ;

	dA = 1.0 ;
	dB = pow ( -10 , 5 ) ;
	dC = 1.0 ;

	fprintf ( file , "\n#############\tDOUBLE\t#############\n" ) ;

	//dBhaskara( dA , dB , dC , &dX1 , &dX2 ) ;
	Bhaskara ( dA , dB , dC , &dX1 , &dX2 ) ;
	fprintf ( file , "Bhaskara:\t%f\t%f\n" , dX1 , dX2 ) ;

	//dFatorado( dA , dB , dC , &dX1 , &dX2 ) ;
	Fatorado ( dA , dB , dC , &dX1 , &dX2 ) ;
	fprintf ( file , "Fatorado:\t%f\t%f\n" , dX1 , dX2 ) ;

	// #################################

	iA = 1 ;
	iB = -4 ;
	iC = 3.999999 ;

	fprintf ( file , "\nLETRA B\n" ) ;
	fprintf ( file , "#############\tINTEGER\t#############\n" ) ;

	//iBhaskara( iA , iB , iC , &iX1 , &iX2 ) ;
	Bhaskara ( iA , iB , iC , &iX1 , &iX2 ) ;
	fprintf ( file , "Bhaskara:\t%d\t%d\n" , iX1 , iX2 ) ;

	//iFatorado( iA , iB , iC , &iX1 , &iX2 ) ;
	Fatorado ( iA , iB , iC , &iX1 , &iX2 ) ;
	fprintf ( file , "Fatorado:\t%d\t%d\n" , iX1 , iX2 ) ;

	fA = 1.0f ;
	fB = -4.0f ;
	fC = 3.999999f ;

	fprintf ( file , "\n#############\tFLOAT\t#############\n" ) ;

	//fBhaskara( fA , fB , fC , &fX1 , &fX2 ) ;
	Bhaskara ( fA , fB , fC , &fX1 , &fX2 ) ;
	fprintf ( file , "Bhaskara:\t%f\t%f\n" , fX1 , fX2 ) ;

	//fFatorado( fA , fB , fC , &fX1 , &fX2 ) ;
	Fatorado ( fA , fB , fC , &fX1 , &fX2 ) ;
	fprintf ( file , "Fatorado:\t%f\t%f\n" , fX1 , fX2 ) ;

	dA = 1.0 ;
	dB = -4.0 ;
	dC = 3.999999 ;

	fprintf ( file , "\n#############\tDOUBLE\t#############\n" ) ;

	//dBhaskara( dA , dB , dC , &dX1 , &dX2 ) ;
	Bhaskara ( dA , dB , dC , &dX1 , &dX2 ) ;
	fprintf ( file , "Bhaskara:\t%f\t%f\n" , dX1 , dX2 ) ;

	//dFatorado( dA , dB , dC , &dX1 , &dX2 ) ;
	Fatorado ( dA , dB , dC , &dX1 , &dX2 ) ;
	fprintf ( file , "Fatorado:\t%f\t%f\n" , dX1 , dX2 ) ;


	// #################################

	iA = 6 ;
	iB = 5 ;
	iC = -4 ;

	fprintf ( file , "\nLETRA C\n" ) ;
	fprintf ( file , "#############\tINTEGER\t#############\n" ) ;

	//iBhaskara( iA , iB , iC , &iX1 , &iX2 ) ;
	Bhaskara ( iA , iB , iC , &iX1 , &iX2 ) ;
	fprintf ( file , "Bhaskara:\t%d\t%d\n" , iX1 , iX2 ) ;

	//iFatorado( iA , iB , iC , &iX1 , &iX2 ) ;
	Fatorado ( iA , iB , iC , &iX1 , &iX2 ) ;
	fprintf ( file , "Fatorado:\t%d\t%d\n" , iX1 , iX2 ) ;

	fA = 6.0f ;
	fB = 5.0f ;
	fC = -4.0f ;

	fprintf ( file , "\n#############\tFLOAT\t#############\n" ) ;

	//fBhaskara( fA , fB , fC , &fX1 , &fX2 ) ;
	Bhaskara ( fA , fB , fC , &fX1 , &fX2 ) ;
	fprintf ( file , "Bhaskara:\t%f\t%f\n" , fX1 , fX2 ) ;

	//fFatorado( fA , fB , fC , &fX1 , &fX2 ) ;
	Fatorado ( fA , fB , fC , &fX1 , &fX2 ) ;
	fprintf ( file , "Fatorado:\t%f\t%f\n" , fX1 , fX2 ) ;

	dA = 6.0 ;
	dB = 5.0 ;
	dC = -4.0 ;

	fprintf ( file , "\n#############\tDOUBLE\t#############\n" ) ;

	//dBhaskara( dA , dB , dC , &dX1 , &dX2 ) ;
	Bhaskara ( dA , dB , dC , &dX1 , &dX2 ) ;
	fprintf ( file , "Bhaskara:\t%f\t%f\n" , dX1 , dX2 ) ;

	//dFatorado( dA , dB , dC , &dX1 , &dX2 ) ;
	Fatorado ( dA , dB , dC , &dX1 , &dX2 ) ;
	fprintf ( file , "Fatorado:\t%f\t%f\n" , dX1 , dX2 ) ;


	fclose ( file ) ;
}



int main ( )
{
	Exercicio01 ( ) ;



	return 0;
}

void printMatrix ( const int *M[] , const int m , const int n )
{
	int i , j ;

	FILE *file = fopen ( "d:/Exercicio02.txt" , "a" ) ;

	for ( i = 0 ; i < m ; ++i )
	{
		for ( j = 0 ; j < n ; ++j )
		{
			fprintf ( file , "%d ," , M[ i ][ j ] ) ;
		}
		fputc ( 10 , file ) ;
	}

	fclose ( file ) ;
}
