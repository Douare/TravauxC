#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include "Oiseau.hpp"
#include "Ennemi.hpp"
#include <iostream>

class Plateau {

	private:
		int l;
		int h;
		int nbLances;
		int nbVivants;
		Ennemi* e;
		Oiseau o;
		int score;
		char* grille;
	public:
		Plateau();
		void initGrille();
		void initEnnemis();
		void grillePeuplee();
		void grilleTraj();
		void traitementOiseau();
		void traitementEnnemi();
		void jeu();
		void affichage();
		~Plateau();
	
};

#endif