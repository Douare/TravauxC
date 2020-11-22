# include <iostream>
# include <stdlib.h>  // drand48

# include <assert.h>

# undef NDEBUG

# include "matrix.hpp"

using namespace std ; 


Matrix :: Matrix() {
}					


Matrix :: Matrix ( unsigned int const _line_nbr , unsigned int const _column_nbr ) {
	(*this).line_nbr = _line_nbr;
	(*this).column_nbr = _column_nbr;
	(*this).element = new float[_line_nbr*_column_nbr]();
} 


Matrix :: Matrix ( Matrix const & m ) { 
	(*this).line_nbr = m.line_nbr;
	(*this).column_nbr = m.column_nbr;
	unsigned int size =line_nbr*column_nbr;
	(*this).element = new float[size];
	for (unsigned int i=0; i<size; i++){
		(*this).element[i]=m.element[i];
	}
} 

Matrix :: ~ Matrix () {
  delete [] element ; // works with NULL
}


void Matrix :: init_alea () { 
	for ( unsigned int i = 0 ; i < line_nbr*column_nbr ; i++ ) {	
		element[ i ] = drand48 () ; 
  }		
}


void Matrix :: init ( float const * coefficients ) { 
	for ( unsigned int i = 0 ; i < line_nbr*column_nbr ; i++ ) {	
		element[i] = coefficients[i] ; 
  }		
}


void Matrix :: set_identity () { //////////////////////////////////////à tester
	for ( unsigned int i = 0 ; i < line_nbr*column_nbr ; i++ ) {	
		element[i]=0;
	}
	for ( unsigned int i = 0 ; i < line_nbr ; i++ ) {
		for ( unsigned int j = 0 ; j < column_nbr ; j++ ) {
			element [i * column_nbr + j] = 1;
		}
	}
}


std :: ostream & operator << ( std :: ostream & ost , Matrix const & m ) { 
	for ( unsigned int i = 0 ; i < m.line_nbr ; i++ ) {
		ost<<"| ";
		for ( unsigned int j = 0 ; j < m.column_nbr ; j++ ) {	
			ost<<m.element[i]<<" ";
		}
	ost<<"|\n";
	}	
	ost<<"\n";	
  return ost ; 
}


Matrix & Matrix :: operator = ( Matrix const & m ) { 
}


Matrix Matrix :: operator + ( Matrix const & m ) const { 
}


Matrix Matrix :: operator - ( Matrix const & m ) const { 
}


Matrix Matrix :: operator * ( Matrix const & m ) const { 
}


Vector Matrix :: operator * ( Vector const & v ) const { 
}


Matrix Matrix :: operator * ( const float a ) const { 
}


Matrix operator * ( float const a ,
		    Matrix const & m ) {
  return m * a ; 
}


Matrix & Matrix :: operator += ( Matrix const & m ) { 
}


Matrix & Matrix :: operator *= ( Matrix const & m ) { 
}


bool Matrix :: operator == ( Matrix const & m ) const { 
  return false ;
}


Vector Matrix :: extract_ligne ( unsigned int const l ,
				 unsigned int const c1 ,
				 unsigned int const c2 ) const { 
  return * ( Vector * ) NULL ;
}


Vector Matrix :: extract_col ( unsigned int const l1 ,
			       unsigned int const l2 ,
			       unsigned int const c ) const { 
  return * ( Vector * ) NULL ;
} 


Matrix Matrix :: extract_triangular_lower_diag_one () const { 
  return * ( Matrix * ) NULL ;
}


Matrix Matrix :: extract_triangular_upper_diag () const { 
  return * ( Matrix * ) NULL ;
}


Matrix Matrix :: extract_diagonal () const { 
  return * ( Matrix * ) NULL ;
}

