#include "graph.cpp"
#include "tas.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;



int main(int argc, char *argv[]){

	if(argc == 3){

		Graph<string,int> *monGraphe = new Graph<string,int>();
		monGraphe->lireFichier(argv[1]);
		cout<< "Votre graphe :" << endl;
		monGraphe->afficher();
		cout<< "Sommets choisis par l'algorithme de Dijkstra dans l'ordre:\n";
		monGraphe->dijkstra(make_pair<string,int>(argv[2],0));
		delete monGraphe;
	}else{
		cout<<"Nombre d'arguments invalide."<<endl;
	}

    return 0;
}
