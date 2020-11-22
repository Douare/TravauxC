#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "graphe.h"
using namespace std;

int main(){
	//map<int,vector<pair<int,int>>> m;
	int n =2;
	Graphe<int,int> *monGraphe = new Graphe<int,int>();
	monGraphe->ajouterSommet(n);
	/*
	//map<int,vector<pair<int,int>>> m;
	Graphe<int,int> g ();
	pair <int,int> p (3,200);
	g.ajouterSommet(2);
	g.ajouterSommet(3);
	g.ajouterArete(2,p);
	//g.supprimerSommet(3);
	//cout<<g<<endl;
*/
}

