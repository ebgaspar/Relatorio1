#include <math.h>
#include <stdio.h>
#include <string.h>
#include <typeinfo>

//template < typename T >
//T _delta ( const T a , const T b , const T c )
//{
//	return ( pow ( b , 2 ) - ( 4 * a * c ) );
//}
//
template < typename T >
inline bool isZero ( T x )
{
	const T epsilon = 0.00000000001;
	return std::abs ( x - 0 ) <= epsilon * std::abs ( x );
}

template < typename T >
void Bhaskara ( const T a , const T b , const T c , T *x1 , T *x2 )
{
	T bQuad = pow ( b , 2.0 ) ;
	T delta = bQuad - ( 4 * a * c ) ;
	T raizQ = sqrt ( delta ) ;

	*x1 = ( ( -b ) + raizQ ) / ( 2 * a ) ;
	*x2 = ( ( -b ) - raizQ ) / ( 2 * a ) ;
}

template < typename T >
void Fatorado ( const T a , const T b , const T c , T * x1 , T * x2 )
{
	T bQuad = pow ( b , 2.0 );
	T delta =  bQuad - ( 4 * a * c ) ;
	T raizQ = sqrt ( delta ) ;

	*x1 = ( -2 * c ) / ( ( b ) + raizQ ) ;

	if ( isZero( *x1 ) )
	{
		*x2 = NAN;
		return;
	}
		*x2 = c / ( a * *x1 );
	
}

//bool isZero ( float x )
//{
//	const float epsilon = 0.0000000001f;
//	return std::abs ( x - 0 ) <= epsilon * std::abs ( x );
//}
//
//bool isZero ( double x )
//{
//	const double epsilon = 0.00000000000000001;
//	return std::abs ( x - 0 ) <= epsilon * std::abs ( x );
//}
//
//void Bhaskara ( const int a , const int b , const int c , int *x1 , int *x2 )
//{
//	int delta = pow ( b , 2 ) - ( 4 * a * c ) ;
//	
//	*x1 = ( ( -b ) + sqrt ( delta ) ) / ( 2 * a ) ;
//	*x2 = ( ( -b ) - sqrt ( delta ) ) / ( 2 * a ) ;
//}
//void Fatorado ( const int a , const int b , const int c , int * x1 , int * x2 )
//{
//	int delta = pow ( b , 2 ) - ( 4 * a * c ) ;
//	int res = ( -2 * c ) / ( ( b ) +sqrt ( delta ) );
//	*x1 = res;
//
//	if ( res == 0 )
//	{
//		*x2 = NAN;
//	}
//	else
//	{
//		*x2 = c / ( a * res );
//	}
//	
//}
//
//void Bhaskara ( const float a , const float b , const float c , float *x1 , float *x2 )
//{
//	float delta = pow ( b , 2 ) - ( 4 * a * c );
//
//	*x1 = ( ( -b ) + sqrt ( delta ) ) / ( 2.0f * a );
//	*x2 = ( ( -b ) - sqrt ( delta ) ) / ( 2.0f * a );
//}
//void Fatorado ( const float a , const float b , const float c , float *x1 , float *x2 )
//{
//	float delta = pow ( b , 2 ) - ( 4.0f * a * c );
//	float res = ( -2.0f * c ) / ( ( b ) +sqrt ( delta ) );
//	*x1 = res;
//
//	if ( isZero( res ) )
//	{
//		*x2 = NAN;
//	}
//	else
//	{
//		*x2 = c / ( a * res );
//	}
//
//}
//
//void Bhaskara ( const double a , const double b , const double c , double *x1 , double *x2 )
//{
//	double delta = pow ( b , 2 ) - ( 4 * a * c );
//
//	*x1 = ( ( -b ) + sqrt ( delta ) ) / ( 2 * a );
//	*x2 = ( ( -b ) - sqrt ( delta ) ) / ( 2 * a );
//}
//
//
//void Fatorado ( const double a , const double b , const double c , double *x1 , double *x2 )
//{
//	double delta = pow ( b , 2 ) - ( 4 * a * c );
//	double res = ( -2 * c ) / ( ( b ) +sqrt ( delta ) );
//	*x1 = res;
//
//	if ( isZero( res ) )
//	{
//		*x2 = NAN;
//	}
//	else
//	{
//		*x2 = c / ( a * res );
//	}
//
//}

void Exercicio01 ( void )
{
	FILE *file = fopen ( "Exercicio01.txt" , "w" ) ;

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
	fflush ( file );

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
	fflush ( file );

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
	fflush ( file );
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
	fflush ( file );

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
	fflush ( file );

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

	fflush ( file );
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
	fflush ( file );

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
	fflush ( file );

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

	fflush ( file );
	fclose ( file ) ;
}