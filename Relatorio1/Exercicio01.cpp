#include <stdio.h>
#include <math.h>

template < typename T >
void Bhaskara ( const T a , const T b , const T c , T *x1 , T *x2 )
{
	T delta = pow ( b , 2 ) - 4 * a * c ;

	*x1 = ( ( -b ) + sqrt ( delta ) ) / ( 2 * a ) ;
	*x2 = ( ( -b ) - sqrt ( delta ) ) / ( 2 * a ) ;
}

template < typename T >
void Fatorado ( const T a , const T b , const T c , T * x1 , T * x2 )
{
	T delta = pow ( b , 2 ) - 4 * a * c ;

	*x1 = ( -2 * c ) / ( ( -b ) + sqrt ( delta ) ) ;
	*x2 = c / ( a * *x1 ) ;
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