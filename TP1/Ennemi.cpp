#include "Ennemi.hpp"

/*
		int posx;
		int posy;
		bool vie;
		int type;
		int score;
*/




		Ennemi::Ennemi(){
			(*this).posx=0;
			(*this).posy=0;
			(*this).vie=true;
			(*this).type=0;
			(*this).score=0;
		}

		Ennemi::Ennemi(int t){
			(*this).type=t;
		}

		Ennemi::Ennemi(int t, int x, int y){
			(*this).type=t;
			(*this).posx=x;
			(*this).posy=y;
		}

		bool Ennemi::estVivant(){
			return (*this).vie;
		}

		//void Ennemi::generation(int t, int l, int h){}
		//void Ennemi::generation(int l, int h){}

		int Ennemi::getX(){
			return (*this).posx;
		}
		int Ennemi::getY(){
			return (*this).posy;
		}
		char Ennemi::getSymbole(){
			if ((*this).type==1){
				return '@';
			}else{
				return '~';
			}
		}

		int Ennemi::getScore(){
			(*this).score;
		}
		void Ennemi::setMort(){
			(*this).vie=false;
		}	
		bool Ennemi::touche(Oiseau& o){
			if((o.getY((*this).getX)) == (*this).getY){
					return true;
			}
		}

		//Ennemi::~Ennemi();
