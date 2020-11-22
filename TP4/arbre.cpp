# include "arbre.hpp"
using namespace std ; 

		Arbre::Arbre(){
			(*this).racine=NULL;
		}

		Arbre::Arbre(Noeud* n){
			(*this).racine= n;
		}

		Arbre::~Arbre(){ //à définir
		}



		void Arbre::inserer_noeud(Noeud* n){
			Noeud* tmp=racine;
			while((*tmp).get_filsG()==NULL && (*tmp).get_filsD()==NULL){
				tmp = (*tmp).get_filsG();
			}
			if((*tmp).get_filsG()!=NULL){
				(*tmp).set_filsG(n);
			}else{
				(*tmp).set_filsD(n);
			}

		}

		void Arbre::afficher_arbre(){
			if(racine!=NULL){
				racine->afficher_noeud();
			}else{
				cout<<"Arbre vide."<<endl;
			}
		}
