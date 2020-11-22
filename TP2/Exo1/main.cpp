#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>


void printVecteur(std::vector<int> v){
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); i++){
		std::cout << *i << ' ';
	}
	std::cout << '\n';
}

int occurencePremierEle(std::vector<int>::const_iterator deb, std::vector<int>::const_iterator fin){
	int occ=0;
	int val=*deb;
	while( deb!= fin && *deb==val){
		occ++;
		deb++;
	}
	return occ;

}

int eleMajoritaire(std::vector<int>::const_iterator deb, std::vector<int>::const_iterator fin){
	int ele=*deb;
	int occMax=0;
	while(deb!=fin){
		int occ= occurencePremierEle(deb,fin);
		if(occ>occMax){
			occMax=occ;
			ele=*deb;
		}
		deb=deb+occ;
	}
	return ele;
}


int main(){

	std::vector<int>v(6, 1);
	v[3]=5;
	v[4]=2;
	v[5]=2;
	//v=[1,1,1,5,2,2]
	std::vector<int> &v1=v;
	std::vector<int>::iterator deb = v.begin();
	std::vector<int>::iterator fin = v.end();
	std::sort(deb,fin);
	printVecteur(v1);
	std::cout << eleMajoritaire(deb, fin) << '\n';


	return 0;
	
}

