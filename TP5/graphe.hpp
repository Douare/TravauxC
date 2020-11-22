#ifndef GRAPHE_HPP
#define GRAPHE_HPP
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

class Graphe {
	private:
		 map <int,vector<pair<int, int>>> graphe; //map de liste de couple

	public:
		//CONSTRUCTEURS & DESTRUCTEUR
		Graphe();
		Graphe(map <int,vector<pair<int, int>>> g);
		~Graphe();
		//METHODES AJOUT/SUPPR/AFFICHER
		bool estClef(int n);
		bool estVoisin(int clef, int n);
		void ajouterSommet(int n); //nouvelle clé
		void ajouterArete(int clef, pair<int,int> sommet);
		void supprimerSommet(int clef);
		void supprimerArete(int a, int b); //supprimer l'arete a->b
		//GETTERS/SETTERS
		map <int,vector<pair<int, int>>> getGraphe();
		map <int,vector<pair<int, int>>> getGraphe() const;
		//SURCHARGE D'OPPERATEURS
		friend ostream& operator<< (ostream &os, const Graphe &g); 
		//PARCOURS LARGEUR ET PROFONDEUR
		vector<pair<int,int>> parcoursLargeur(int clef);
		vector<pair<int,int>> parcoursProfondeur(int clef);

};



#endif