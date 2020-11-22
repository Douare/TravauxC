#ifndef ARBRE_HPP
#define ARBRE_HPP
# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include "noeud.hpp"


class Arbre {
	private:
		Noeud* racine;

	public:
		Arbre();
		Arbre(Noeud *n);
		~Arbre();
		void inserer_noeud(Noeud* n); //on suppose que l'arbre ne contient pas deux fois la même valeur
		Noeud rechercher_noeud(int v);
		void suppression_noeud(int v);
		void afficher_arbre();

};
#endif