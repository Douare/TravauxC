#ifndef OISEAU_HPP
#define OISEAU_HPP
#include <iostream>

class Oiseau {
	private:
		int l; //largeur du tableau
		int* traj;

	public:
		Oiseau();
		Oiseau(int l);
		void setTrajectoire(float angle, float vitesse);
		void setTrajectoire(int y, int l, int h, float angle);
		void setTrajectoire(int y, int l);
		int getY(int i);
		void setGrille(int L);
		~Oiseau();
	
};

#endif