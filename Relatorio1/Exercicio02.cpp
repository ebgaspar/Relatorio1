#include "Exercicio02.h"

template <typename T>
void Calcula( const int nTimes , Matrix<T> &A, Matrix<T> &B , Matrix<T> &C , const char *baseName ) ;

void Exercicio02( const int nTimes , const int dim )
{

    Matrix<float> A , B ;
    A.Init( dim , dim ) ;
    A.fillRandomMatrix( );

    B.Init( dim , dim ) ;
    B.fillRandomMatrix( );

    Matrix<float> C ;
    C.Init( dim , dim ) ;

    Calcula( nTimes , A, B , C , "Exercicio_2_saida_mul_matrix-teste.csv") ;

    Matrix<float> &triUpper = B ;
    triUpper.upperTriangular( 1 , 15 );
//    triUpper.printMatrix( "triupper.txt" ) ;
    Calcula( nTimes , A, triUpper , C , "Exercicio_2triUpper_saida_mul_matrix-teste.csv") ;

	Matrix<float> &triLower = B ;
    triLower.lowerTriangular( 1 , 15 );
//    triLower.printMatrix( "trilower.txt" ) ;
    Calcula( nTimes , A, triLower , C , "Exercicio_2triLower_saida_mul_matrix-teste.csv") ;

    Matrix<float> &toeplitz = B ;
    toeplitz.toeplitz( 1 , 15 );
//    toeplitz.printMatrix( "toeplitz.txt" ) ;
    Calcula( nTimes , A, toeplitz , C , "Exercicio_2toeplitz_saida_mul_matrix-teste.csv") ;

	Matrix<float> &triDiag = B ;
    triDiag.triDiagonal( 1 , 15 );
//    triDiag.printMatrix( "tridiag.txt" ) ;
    Calcula( nTimes , A, triDiag , C , "Exercicio_2triDiag_saida_mul_matrix-teste.csv") ;

	int nDim = 64;

	Matrix< long double > vA , vC;
	vA.Init ( nDim , nDim ) ;
	vC.Init ( nDim , nDim ) ;
	vA.fillRandomMatrix ( 1.2 , 5.0 ) ;
	vC.fillWithZeros ( ) ;

    Matrix<long double> vandermonde ;
	vandermonde.Init( nDim , nDim ) ;
    vandermonde.vandermonde( .2 ) ;
    Calcula( nTimes , vA, vandermonde , vC , "Exercicio_2vandermonde_saida_mul_matrix-O2-Windows.csv") ;
    vandermonde.printMatrix( "vandermont.txt", "w" ) ;
	vC.printMatrix ( "vanderResult.txt" , "w" );
	vA.printMatrix ( "AResult.txt" , "w" );
}

template <typename T>
void Calcula( const int nTimes , Matrix<T> &A, Matrix<T> &B , Matrix<T> &C , const char *baseName )
{
	double mNormal = 0.0 , mBloco = 0.0 ;
	int dim = A.getRowsSize( ) ;

	std::ofstream file;
	file.open( baseName , std::ios::out | std::ios::trunc );

	if ( !file.is_open( ) )
	{
		fprintf( stderr , "Nao abriu arquivo.\n" );
	}
    file << "dim ; blockSize ; Normal ; Bloco\n" ;

	clock_t tStart ;
	double timeElapsed = 0.0 ;
    fprintf( stdout, "%s\n", baseName ) ;
	fprintf( stdout , "\tInicio - Multiplicacao normal : \033[1;5;31;40m%dx \033[m\n" , nTimes ) ;

	for ( int i = 0 ; i < nTimes ; ++i )
	{
		tStart = clock( );
		A.multiply( B , C ) ;
		timeElapsed += ( double ) ( clock( ) - tStart ) / ( CLOCKS_PER_SEC ) ;
		fprintf( stdout , "\t\t%d\r" , i ) ;
	}
	fprintf( stdout , "\t\tNORMAL MULT - Time :\t%.6fs\n" , timeElapsed / nTimes ) ;

	mNormal = timeElapsed / nTimes;
	timeElapsed = 0.0 ;
	for ( int i = 4 ; i <= dim ; i *= 2 )
	{
		timeElapsed = 0 ;
		fprintf( stdout , "\tInicio - Multiplicacao com Bloco : \033[1;5;31;40m%dx \033[m\n" , nTimes ) ;
		for ( int j = 0 ; j < nTimes ; ++j )
		{
			C.fillWithZeros ( );
			tStart = clock( );
			A.matrixBlockMultiply( B , C , dim , i ) ;
			timeElapsed += ( double ) ( clock( ) - tStart ) / CLOCKS_PER_SEC ;
			fprintf( stdout , "\t\t%d\r" , i ) ;
		}
		fprintf( stdout , "\t\tBLOCK MULT - Time :\t%.6fs\n" , timeElapsed / nTimes );
		mBloco = timeElapsed / nTimes ;
		file << dim << " ; " << i << " ; " << std::fixed << std::setprecision( 4 ) << mNormal << " ; " << mBloco << std::endl ;
	}

	file.close( );

	fprintf( stdout , "Multiplicacao comum :\t%.5f\nMultiplicacao Bloco :\t%.5f\n" , mNormal , mBloco ) ;
}





//const int m = 4 , n = 4 ;
//int A [ m ][ n ] = { { 2 ,3 ,-1 ,2 }, { 0, 4, -3 ,5 }, { 1, 2, 1, 3 }, { 0, 4, 1, 0 } } ;
//int B [ m ][ n ] = { { 2, -3, 4, 11 }, { 7, 6, 1, 2 }, { 2, -5, 5, 8 }, { 7, 2, -3, -4 } } ;
//int C [ m ][ n ] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } } ;
//matrixMuliply( A , B , C , m , n ) ;
//memset( C , 0 , m * n * ( sizeof( int ) ) ) ;
//matrixBlockMultiply( A , B , C , m ) ;
//memset( C , 0 , m * n * ( sizeof( int ) ) ) ;
//matrixBlockMultiply( A , B , C , m , n ) ;
