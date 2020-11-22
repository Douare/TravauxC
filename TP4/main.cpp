#include "stdio.h"
#include "noeud.hpp"
#include "arbre.hpp"



int main(){

	Noeud n1 (1);
	Noeud n2 (2);
	Noeud n3 (3);
	
	Arbre a1 (&n1);
	a1.inserer_noeud(&n2);
	a1.afficher_arbre();
	return 0;
	
}

