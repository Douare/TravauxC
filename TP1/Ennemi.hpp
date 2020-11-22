#ifndef ENNEMI_HPP
#define ENNEMI_HPP
#include "Oiseau.hpp"
#include <iostream>

class Ennemi {
	private:
		int posx;
		int posy;
		bool vie;
		int type;
		int score;

	public:
		Ennemi();
		Ennemi(int t);
		Ennemi(int t, int x, int y);
		bool estVivant();
		void generation(int t, int l, int h);
		void generation(int l, int h);
		int getX();
		int getY();
		char getSymbole();
		int getScore();
		void setMort();
		bool touche(Oiseau& o);
		~Ennemi();

};

#endif