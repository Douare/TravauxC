# include "graphe.hpp"
using namespace std ; 


Graphe::Graphe(){
}
Graphe::~Graphe(){
}

Graphe::Graphe(map <int,vector<pair<int, int>>> g){
	(*this).graphe = g;
}
/////////////////////////////////////////////////////////////////////////////////////////////////


bool Graphe::estClef(int n){
	for ( map<int,vector<pair<int, int>>>::iterator i = graphe.begin(); i != graphe.end(); i++){
		if(n==(i->first)){
			return true;

		}
	}
	return false;
}

bool Graphe::estVoisin(int clef, int n){ //vrai si le 1er ele de pair est dans le vector de clef
	vector<pair<int,int>> v = graphe[clef];
	for(int i=0; i<v.size(); i++){
		if(v[i].first==n){
			return true;
		}
	}
	return false;
}

void Graphe::ajouterSommet(int clef){
	if(!estClef(clef)){
		vector<pair<int,int>> v;
		(*this).graphe.insert(std::make_pair(clef,v));
	}
}

void Graphe::ajouterArete(int clef, pair<int, int> sommet){
	if(estClef(sommet.first) && estClef(clef) && !estVoisin(clef,sommet.first)){
		vector<pair<int,int>> &v = graphe[clef];
		v.push_back(sommet);
	}
}

void Graphe::supprimerSommet(int n){
	for ( map<int,vector<pair<int, int>>>::iterator i = graphe.begin(); i != graphe.end(); i++){
		if(i->first==n){
			graphe.erase(i);
		}else{
			supprimerArete(i->first,n);
		}
	}

}

void Graphe::supprimerArete(int a, int b){
	if(estVoisin(a,b)){
		vector<pair<int,int>> &v = graphe[a];
		for(int i =0; i<v.size(); i++){
			if(v[i].first==b){
				v.erase(v.begin()+i);
			}
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////

map <int,vector<pair<int, int>>> Graphe::getGraphe(){
	return (*this).graphe;
}

map <int,vector<pair<int, int>>> Graphe::getGraphe() const {
	return (*this).graphe;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

ostream& operator<< (ostream &os, const Graphe &g){
	for ( map<int,vector<pair<int, int>>>::const_iterator i = (g.graphe).begin(); i != (g.graphe).end(); i++){
		os << i->first;
		vector<pair<int,int>> v = i->second;

		for(int i =0; i<v.size(); i++){
			os << " -- " << v[i].first;
		}
	    os << ";\n";

	}
	return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

/*
vector<pair<int,int>> parcoursLargeur(vector<pair<int,int>> v, int clef){ //v=sommetsVisités
	vector<pair<int,int>> t = graphe[clef];
	v.insert(v.end(), t.begin(), t.end());

	for(int i =0; i<t.size(); i++){
			os << " -- " << v[i].first;
		}

}
*/