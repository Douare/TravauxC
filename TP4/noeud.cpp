# include "noeud.hpp"
using namespace std ; 


		Noeud::Noeud(){
			(*this).val=(-1);
			(*this).filsG=NULL;
			(*this).filsD=NULL;
		}

		Noeud::Noeud(int v){
			(*this).val=v;
			(*this).filsG=NULL;
			(*this).filsD=NULL;
		}

		Noeud::Noeud(int v, Noeud *fg, Noeud *fd){
			(*this).val=v;
			(*this).filsG=fg;
			(*this).filsD=fd;
		}


		Noeud::Noeud(const Noeud &n){
			(*this).val=n.val;
			(*this).filsG=n.filsG;
			(*this).filsD=n.filsD;
		}


		Noeud::~Noeud(){ //à définir
		}

		//fin const & dest



		int Noeud::get_val(){
			return val;
		}

		void Noeud::set_val(int v){
			val=v;
		}
		Noeud* Noeud::get_filsG(){
			return filsG;
		}
		void Noeud::set_filsG(Noeud* n){
			filsG=n;
		}
		Noeud* Noeud::get_filsD(){
			return filsD;
		}
		void Noeud::set_filsD(Noeud* n){
			filsD=n;
		}




		void Noeud::afficher_noeud(){
			if(val>=0){
				cout<<val<<"\n";
				if(filsG!=NULL){
					filsG->afficher_noeud();
				}
				if(filsD!=NULL){
					filsD->afficher_noeud();
				}
			}
			cout<<endl;
		}
