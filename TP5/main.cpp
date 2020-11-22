#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "graphe.hpp"


int main(){
	map<int,vector<pair<int,int>>> m;
	Graphe g (m);
	pair <int,int> p (3,200);
	g.ajouterSommet(2);
	g.ajouterSommet(3);
	g.ajouterArete(2,p);
	//g.supprimerSommet(3);
	cout<<g<<endl;
}

