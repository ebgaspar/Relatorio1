#include "Exercicio02.h"


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

void Calcular( const int , const int , double * , double * ) ;

void Exercicio02( void )
{
	int nTeste = 50 ;
	int nTimes = 100 ;
	int dim = 200 ;
	double mN = 0.0 , mB = 0.0 ;
	for ( int i = 0 ; i < nTeste ; ++i )
	{
		double tmp1 , tmp2 ;
		fprintf( stdout , "Matriz tamanho : %dx%d\t Teste:\t \033[1;5;32;40m %d de %d \033[m\n" , dim , dim , i , nTeste ) ;

		Calcular( dim , nTimes , &tmp1 , &tmp2 ) ;

		mN += tmp1 ;
		mB += tmp2 ;
	}

	fprintf( stdout , "Multiplicacao comum :\t%.5f\nMultiplicacao Bloco :\t%.5f\n" , mN / nTeste , mB / nTeste ) ;
}

void Calcular( const int matrixSize, const int nTimes, double *mNormal, double *mBloco )
{
	//const int m = 4 , n = 4 ;
	//int A [ m ][ n ] = { { 2 ,3 ,-1 ,2 }, { 0, 4, -3 ,5 }, { 1, 2, 1, 3 }, { 0, 4, 1, 0 } } ;
	//int B [ m ][ n ] = { { 2, -3, 4, 11 }, { 7, 6, 1, 2 }, { 2, -5, 5, 8 }, { 7, 2, -3, -4 } } ;
	//int C [ m ][ n ] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } } ;
	//matrixMuliply( A , B , C , m , n ) ;
	//memset( C , 0 , m * n * ( sizeof( int ) ) ) ;
	//matrixBlockMultiply( A , B , C , m ) ;
	//memset( C , 0 , m * n * ( sizeof( int ) ) ) ;
	//matrixBlockMultiply( A , B , C , m , n ) ;

	Matrix<int> A , B ;
	A.Init( matrixSize , matrixSize ) ;
	A.fillRandomMatrix( ) ;

	B.Init( matrixSize , matrixSize ) ;
	B.fillRandomMatrix( ) ;

	Matrix<int> C ;
	C.Init( matrixSize , matrixSize ) ;

	clock_t tStart ;
	double timeElapsed = 0.0 ;

	fprintf( stdout , "\tInicio - Multiplicacao normal : \033[1;5;31;40m%dx \033[m\n", nTimes ) ;
	for ( int i = 0 ; i < nTimes ; ++i )
	{
		tStart = clock( );
		A.multiply( B , C ) ;
		timeElapsed += ( double ) ( clock( ) - tStart ) / ( CLOCKS_PER_SEC ) ;
		fprintf( stdout , "\t\t%d\r" , i ) ;
	}
	fprintf( stdout , "\t\tNORMAL MULT - Time :\t%.6fs\n" , timeElapsed ) ;
	
	*mNormal = timeElapsed ;
	timeElapsed = 0.0 ;
	C.fillWithZeros( ) ;

	fprintf( stdout , "\tInicio - Multiplicacao com Bloco : \033[1;5;31;40m%dx \033[m\n" , nTimes ) ;
	for ( int i = 0 ; i < nTimes ; ++i )
	{
		tStart = clock( );
		A.matrixBlockMultiply2( B , C , matrixSize ) ;
		timeElapsed += ( double ) ( clock( ) - tStart ) / CLOCKS_PER_SEC ;
		fprintf( stdout , "\t\t%d\r" , i ) ;
		C.fillWithZeros( ) ;
	}
	fprintf( stdout , "\t\tBLOCK MULT - Time :\t%.6fs\n" , timeElapsed );
	*mBloco = timeElapsed ;
}