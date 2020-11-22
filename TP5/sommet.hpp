#ifndef SOMMET_HPP
#define SOMMET_HPP
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
# include <stdlib.h>
# include <assert.h>

using namespace std;

class Sommet {
	private:
		int val;
		int poids;

	public:
		//CONSTRUCTEURS & DESTRUCTEUR
		Noeud();
		Noeud(int v, int p);
		Noeud(int v, Noeud *fg, Noeud *fd);
		Noeud(const Noeud &n);
		~Noeud();
		//GETTERS & SETTERS
		int get_val();
		void set_val(int v);
		Noeud* get_filsG();
		void set_filsG(Noeud* n);
		Noeud* get_filsD();
		void set_filsD(Noeud* n);




		void afficher_noeud();
};

#endif