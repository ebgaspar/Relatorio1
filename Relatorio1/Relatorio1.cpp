// Relatorio1.cpp
//
#include <stdio.h>
#include <stdlib.h>

#include "Exercicio01.h"
#include "Exercicio02.h"





int main( )
{
	//Exercicio01( ) ;

	//Exercicio02( ) ;

	int _Toeplitz [ ] =
	{
		1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10  ,
		2 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9  ,
		3 , 2 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8  ,
		4 , 3 , 2 , 1 , 2 , 3 , 4 , 5 , 6 , 7  ,
		5 , 4 , 3 , 2 , 1 , 2 , 3 , 4 , 5 , 6  ,
		6 , 5 , 4 , 3 , 2 , 1 , 2 , 3 , 4 , 5  ,
		7 , 6 , 5 , 4 , 3 , 2 , 1 , 2 , 3 , 4  ,
		8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 2 , 3  ,
		9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 2  ,
		10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1
	} ;

	int _tridiag [ ] =
	{
		4 , 8 , 7 , 9 , 4 , 3 , 9 , 4 , 8 , 3 ,
		2 , 4 , 8 , 7 , 9 , 7 , 3 , 8 , 6 , 7 ,
		6 , 2 , 4 , 8 , 7 , 9 , 8 , 7 , 6 , 7 ,
		3 , 6 , 2 , 4 , 8 , 7 , 9 , 4 , 5 , 1 ,
		5 , 3 , 6 , 2 , 4 , 8 , 7 , 9 , 5 , 3 ,
		3 , 5 , 3 , 6 , 2 , 4 , 8 , 7 , 9 , 7 ,
		1 , 3 , 5 , 3 , 6 , 2 , 4 , 8 , 7 , 9 ,
		7 , 1 , 3 , 5 , 3 , 6 , 2 , 4 , 8 , 7 ,
		2 , 7 , 1 , 3 , 5 , 3 , 6 , 2 , 4 , 8 ,
		3 , 2 , 7 , 1 , 3 , 5 , 3 , 6 , 2 , 4
	} ;

	int _triLow [ ] =
	{
		9 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
		3 , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
		8 , 8 , 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
		7 , 6 , 9 , 9 , 0 , 0 , 0 , 0 , 0 , 0 ,
		6 , 5 , 9 , 6 , 7 , 0 , 0 , 0 , 0 , 0 ,
		4 , 5 , 4 , 5 , 2 , 9 , 0 , 0 , 0 , 0 ,
		5 , 5 , 5 , 6 , 4 , 6 , 3 , 0 , 0 , 0 ,
		1 , 2 , 6 , 1 , 1 , 3 , 9 , 7 , 0 , 0 ,
		3 , 9 , 9 , 5 , 3 , 7 , 3 , 5 , 4 , 0 ,
		3 , 3 , 2 , 8 , 2 , 1 , 2 , 2 , 9 , 9
	} ;

	int _triUpper [ ] =
	{
		7 , 2 , 4 , 6 , 5 , 6 , 4 , 6 , 3 , 8 ,
		0 , 7 , 8 , 5 , 6 , 2 , 4 , 4 , 1 , 3 ,
		0 , 0 , 3 , 3 , 1 , 8 , 6 , 1 , 8 , 2 ,
		0 , 0 , 0 , 9 , 5 , 6 , 2 , 3 , 4 , 3 ,
		0 , 0 , 0 , 0 , 6 , 2 , 5 , 6 , 1 , 5 ,
		0 , 0 , 0 , 0 , 0 , 7 , 4 , 7 , 3 , 8 ,
		0 , 0 , 0 , 0 , 0 , 0 , 8 , 8 , 2 , 4 ,
		0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 5 , 2 ,
		0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 3 ,
		0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 8
	} ;

	Matrix<int> Toeplitz , TriUpper , TriLow , TriDiag ;
	TriUpper.Init( 10 , 10 , _triUpper ) ;
	TriLow.Init( 10 , 10 , _triLow ) ;
	TriDiag.Init( 10 , 10 , _tridiag ) ;
	Toeplitz.Init( 10 , 10 , _Toeplitz ) ;

	const char *filename = "d:/Matriz2.txt" ;
	const char *toeplitz = "d:/toeplitz.txt" ;

	Matrix<int> A , C ;

	A.Init( 10, 10 ) ;
	A.fillRandomMatrix( ) ;

	C.Init( 10 , 10 ) ;
	C.fillWithZeros( ) ;

	//clock_t tStart ;
	//double timeElapsed = 0.0 ;

	//for ( int i = 0 ; i < 100 ; ++i )
	//{
	//	tStart = clock( );
	//	A.multiply( Toeplitz , C ) ;
	//	timeElapsed += ( double ) ( clock( ) - tStart ) / ( CLOCKS_PER_SEC ) ;
	//	C.printMatrix( toeplitz ) ;
	//}

	//fprintf( stdout , "Tempo: %f" , timeElapsed ) ;

	//C.fillWithZeros( ) ;
	//A.multiply( TriDiag , C ) ;
	//C.printMatrix( filename ) ;

	//C.fillWithZeros( ) ;
	//A.multiply( TriUpper , C ) ;
	//C.printMatrix( filename ) ;

	//C.fillWithZeros( ) ;
	//A.multiply( TriLow , C ) ;
	//C.printMatrix( filename ) ;

	float gaussTeste [ ] = { 1 , 1 , 1 , 9 , 2, -3 , 4 , 13 , 3 , 4 , 5 , 40 } ;

	Matrix<float> gauss;
	gauss.Init( 3 , 4 , gaussTeste ) ;
	int SIZE = gauss.getRowsSize( ) ;
	float *solution = new float [ SIZE ] ;

	gauss.Gauss( solution ) ;

	for ( int i = 0 ; i < SIZE ; ++i )
	{
		fprintf( stdout , "%f " , solution [ i ] ) ;
	}

	delete [ ] solution ;

	fprintf( stdout , "\n" ) ;

	Matrix<float> gaussJordan ;
	gaussJordan.Init( 3 , 4 , gaussTeste ) ;
	SIZE = gaussJordan.getRowsSize( ) ;
	solution = new float [ SIZE ] ;

	gauss.Gauss( solution ) ;

	for ( int i = 0 ; i < SIZE ; ++i )
	{
		fprintf( stdout , "%f " , solution [ i ] ) ;
	}

	delete [ ] solution ;

	Matrix<float> F ;
	F.Init( 5, 5 ) ;
	F.toeplitz( ) ;

	F.printMatrix( "toeplitz.txt" , "w" ) ;

	return 0;
}

