# include <stdlib.h>
# include <assert.h>
# include "vector.hpp"

using namespace std ; 

Vector :: Vector ( ) {
}

Vector :: Vector ( unsigned int const _size ) {
	(*this).size = _size;
	(*this).element = new float[_size]();
}

Vector :: Vector ( const Vector & v ) { 
	(*this).size = v.size;
	(*this).element = new float[size];
	for (unsigned int i=0; i<v.size; i++){
		(*this).element[i]=v.element[i];
	}
}


Vector :: ~Vector () { 
}


void Vector :: init_alea () { 
  for ( unsigned int i = 0 ; i < size ; i++ ) {	
    element[ i ] = drand48 () ; 
  }					
}

//Redéfinition des opérateurs ////////////////////////////////////////////////////////:
float& Vector :: operator [] ( unsigned int const i ) { 
	assert (i<(*this).size);
	return (*this).element[i];
}


float const & Vector :: operator [] ( unsigned int const i ) const { 
	assert (i<(*this).size);
	return (*this).element[i];
}


std :: ostream & operator << ( std :: ostream& ost , Vector const &v ) { 
	ost<<"[";
	for (unsigned int i=0; i<v.size; i++){
		if(i==0){
			ost<<v.element[0];
		}else{
			ost<<","<<v.element[i];
		}
	}
	ost<<"]\n";
  return ost ; 
}


Vector & Vector :: operator = ( Vector const & v ) { 
	delete[](*this).element;
	(*this).size = v.size;
	(*this).element = new float[size];
	for (unsigned int i=0; i<v.size; i++){
		(*this).element[i]=v.element[i];
	}
	return ( * this ) ; 
}


Vector Vector :: operator + ( Vector const & v ) const { 
	assert ((*this).size==v.size);
	Vector w ((*this).size);
	for (unsigned int i=0; i<v.size; i++){
		w.element[i]=v.element[i]+(*this).element[i];
	}
  return w ;
}


Vector Vector :: operator - ( Vector const & v ) const { 
	assert ((*this).size==v.size);
	Vector w ((*this).size);
	for (unsigned int i=0; i<v.size; i++){
		w.element[i]=(*this).element[i]-v.element[i];
	}
  return w ;
}


Vector Vector :: operator * ( float const a ) const { 
	Vector w ((*this).size);
	for (unsigned int i=0; i<(*this).size; i++){
		cout<<i;
		w.element[i]=(*this).element[i]*a;
	}
  return w ;
}


float Vector :: operator | ( Vector const & v ) const { 
  	float scalaire=0;
	for (unsigned int i=0; i<v.size; i++){
		scalaire+=(*this).element[i]*v.element[i];
	}
  return scalaire ;
}


bool Vector :: operator == ( Vector const & v ) const { 
	for (unsigned int i=0; i<v.size; i++){
		if((*this).element[i]!=v.element[i]){
			return false;
		}
	}
  return true;
}


Vector operator * ( float const a , Vector const & v ) { 
  return v*a ;
}



