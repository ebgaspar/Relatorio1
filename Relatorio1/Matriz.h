#pragma once
#include <stdio.h>
#include <math.h>

class Matrix
{
private:
	int **_M {} ;
	int _l , _c ;
public:
	Matrix( ) { this->_M = nullptr ; this->_l = this->_c = 0 ; }
	~Matrix( ) ;
	void Init( int l , int c ) ;

	inline int getRowsSize( void ) const { return this->_l ; }
	inline int getColsSize( void ) const { return this->_c ; }
	inline int **data( void ) { return this->_M ; }

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

	inline bool isEmpty( void ) { return ( this->_M == nullptr ) ? true : false ; }

	void printMatrix( const char *nome , const char * mode = "a" )
	{
		int i , j ;

		FILE *file = fopen( nome , mode ) ;

		for ( i = 0 ; i < this->_l ; ++i )
		{
			for ( j = 0 ; j < this->_c ; ++j )
			{
				fprintf( file , "%d ," , this->_M [ i ][ j ] ) ;
			}
			fprintf( file , "\n" ) ;
		}

		fprintf( file , "\n" ) ;

		fclose( file ) ;
	}
	
	bool operator==( const Matrix & ) ;
	void operator=( const Matrix & ) ;
	Matrix operator*( const Matrix & ) ;

	bool fillRandomMatrix( void ) ;
	bool fillWithZeros( void ) ;

	bool multiply( const Matrix &, Matrix & ) ;
	void matrixBlockMultiply( Matrix& , Matrix& , const int ) ;
	void matrixBlockMultiply2( Matrix & , Matrix & , const int ) ;

	void Gauss( int *solution ) ;
	void GaussJordan( int *solution ) ;
};