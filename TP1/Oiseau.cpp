#include "Oiseau.hpp"
#include <math.h>
#define g 9.8
Oiseau::Oiseau(){
	cout << "Constructeur par défaut" << endl;
	(*this).l = 0;
	(*this).traj = NULL; 
}

Oiseau::Oiseau(int L){
	cout << "Constructeur par défaut" << endl;
	(*this).l = L;
	(*this).traj = new int[(*this).l]; 
}

void Oiseau::setTrajectoire(float angle, float vit){
	for (int i=0; i<l; i++){
		float abs = (float) i;
		float vox = vit * cos(angle * (M_PI/180));
		float voy = vit * sin(angle * (M_PI/180));
		float y = (-g / (2 * vox * vox)) * abs * abs + (voy/vox) * abs;
		traj[i] = round(y);
	}
}

/*
void setTrajectoire(int y, int l, int h, float angle);
*/
void setTrajectoire(int y, int l){
	for(int i=0; i<l, i++){
		(*this).traj[i] = y;
	}
}

int getY(int i){
	return (this*).traj[i];
}
void setGrille(int L){
	 new int[(*this).l];
}
~Oiseau(){
	cout << "Destructeur par défaut" << endl;
	delete[] traj;
}