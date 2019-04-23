#include "Exercicio02.h"


void Exercicio02( const int nTimes , const int dim )
{
	char baseName [ 50 ] = { "Exercicio_2_saida_mul_matrix.csv" } ;
	double mNormal = 0.0 , mBloco = 0.0 ;

	std::ofstream file;
	file.open( baseName , std::ios::out | std::ios::app );

	if ( !file.is_open( ) )
	{
		fprintf( stderr , "Nao abriu arquivo.\n" );
	}

	Matrix<float> A , B ;
	A.Init( dim , dim ) ;
	A.fillRandomMatrix( ) ;

	B.Init( dim , dim ) ;
	B.fillRandomMatrix( ) ;

	Matrix<float> C ;
	C.Init( dim , dim ) ;

	clock_t tStart ;
	double timeElapsed = 0.0 ;

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
		C.fillWithZeros( ) ;
		timeElapsed = 0 ;
		fprintf( stdout , "\tInicio - Multiplicacao com Bloco : \033[1;5;31;40m%dx \033[m\n" , nTimes ) ;
		for ( int j = 0 ; j < nTimes ; ++j )
		{
			tStart = clock( );
			A.matrixBlockMultiply( B , C , dim , i ) ;
			timeElapsed += ( double ) ( clock( ) - tStart ) / CLOCKS_PER_SEC ;
			fprintf( stdout , "\t\t%d\r" , i ) ;
			C.fillWithZeros( ) ;
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
