#ifndef NOEUD_HPP
#define NOEUD_HPP

# include <iostream>
# include <stdlib.h>
# include <assert.h>

class Noeud {
	private:
		int val;
		Noeud *filsG;
		Noeud *filsD;
	public:
		//CONSTRUCTEURS & DESTRUCTEUR
		Noeud();
		Noeud(int v);
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