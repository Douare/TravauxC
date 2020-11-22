#ifndef GRAPHE_H
#define GRAPHE_H
#include <iostream>
#include <list>
#include <iterator>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>
#include <utility>
#include <map>
#include <vector>
#include <stdbool.h>

using namespace std;

template <class S, class P>
class Graphe {
	private:
		 map <S,vector<pair<S, P>>> graphe; //map de liste de couple

	public:
		//CONSTRUCTEURS & DESTRUCTEUR
		Graphe();
		Graphe(map <S,vector<pair<S, P>>> g);
		~Graphe();
		//METHODES AJOUT/SUPPR/AFFICHER
		bool estClef(S n);
		bool estVoisin(S clef, S n);
		void ajouterSommet(S n); //nouvelle clé
		void ajouterArete(S clef, pair<S,P> sommet);
		void supprimerSommet(S clef);
		void supprimerArete(S a, S b); //supprimer l'arete a->b
		//GETTERS/SETTERS
		map <S,vector<pair<S, P>>> getGraphe();
		map <S,vector<pair<S, P>>> getGraphe() const;
		//SURCHARGE D'OPPERATEURS
		ostream& operator<< <>(ostream &os, const Graphe<S,P> &g); 
		//PARCOURS LARGEUR ET PROFONDEUR

};
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////

		//IMPLEMENTATIONS DES METHODES


	template<class S, class P> Graphe<S,P>::Graphe(){
		cout<<"constructeur"<<endl;
	}


	template <class S, class P> Graphe<S,P>::~Graphe(){
		cout<<"constructeur par recopie"<<endl;
	}

	template <class S, class P> Graphe<S,P>::Graphe(map <S,vector<pair<S, P>>> g){
		(*this).graphe = g;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////


	template <class S, class P> bool Graphe<S,P>::estClef(S n){
		for ( typename map<S,vector<pair<S, P>>>::iterator i = graphe.begin(); i != graphe.end(); i++){
			if(n==(i->first)){
				return true;

			}
		}
		return false;
	}

	template <class S, class P> bool Graphe<S,P>::estVoisin(S clef, S n){ //vrai si le 1er ele de pair est dans le vector de clef
		vector<pair<S,P>> v = graphe[clef];
		for(int i=0; i<v.size(); i++){
			if(v[i].first==n){
				return true;
			}
		}
		return false;
	}

	template <class S, class P> void Graphe<S,P>::ajouterSommet(S clef){
		if(!estClef(clef)){
			vector<pair<S,P>> v;
			(*this).graphe.insert(std::make_pair(clef,v));
		}
	}

	template <class S, class P> void Graphe<S,P>::ajouterArete(S clef, pair<S, P> sommet){
		if(estClef(sommet.first) && estClef(clef) && !estVoisin(clef,sommet.first)){
			vector<pair<S,P>> &v = graphe[clef];
			v.push_back(sommet);
		}
	}

	template <class S, class P> void Graphe<S,P>::supprimerSommet(S n){
		for ( typename map<S,vector<pair<S, P>>>::iterator i = graphe.begin(); i != graphe.end(); i++){
			if(i->first==n){
				graphe.erase(i);
			}else{
				supprimerArete(i->first,n);
			}
		}

	}

	template <class S, class P> 
	void Graphe<S,P>::supprimerArete(S a, S b){
		if(estVoisin(a,b)){
			vector<pair<S,P>> &v = graphe[a];
			for(int i =0; i<v.size(); i++){
				if(v[i].first==b){
					v.erase(v.begin()+i);
				}
			}
		}
	}

	template<class S,class T> ostream& operator<< <>(ostream& os, const Graphe<S,T> &g) {
		for ( typename map<S,vector<pair<S, P> > >::const_iterator i = (g.graphe).begin(); i != (g.graphe).end(); i++){
			os << i->first;
			vector<pair<S,P> > v = i->second;

			for(int i =0; i<v.size(); i++){
				os << " -- " << v[i].first;
			}
			os << ";\n";
		}
		return os;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////
/*
	map <int,vector<pair<int, int>>> Graphe<S,P>::getGraphe(){
		return (*this).graphe;
	}

	map <int,vector<pair<int, int>>> Graphe<S,P>::getGraphe() const {
		return (*this).graphe;
	}
	*/
	///////////////////////////////////////////////////////////////////////////////////////////////////////

/*
	template <class S, class P> ostream& operator<< (ostream &os, const Graphe &g){
		for ( typename map<S,vector<pair<S, P>>>::const_iterator i = (g.graphe).begin(); i != (g.graphe).end(); i++){
			os << i->first;
			vector<pair<S,P>> v = i->second;

			for(int i =0; i<v.size(); i++){
				os << " -- " << v[i].first;
			}
		    os << ";\n";

		}
		return os;
	}


*/


