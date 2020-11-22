#include "graph.hpp"
#include "tas.hpp"
#include "tasid.hpp"


int main() {


/* //TESTS CLASSE GRAPHE
	Graph<string,int> *unSommet = new Graph<string,int>();
	unSommet->ajouterSommet("A");
	unSommet->ajouterArete("A", "B", 2);
	unSommet->ajouterArete("A", "C", 3);
	unSommet->ajouterArete("A", "D", 4);


	unSommet->ajouterSommet("E");
	unSommet->ajouterArete("E", "A", 6);
	unSommet->ajouterArete("E", "B", 3);
	unSommet->ajouterArete("E", "G", 1); 
	unSommet->ajouterArete("E", "H", 1); 
	unSommet->afficher();

	//unSommet->dijkstra();
	delete unSommet; 
*/

/* TESTS CLASSE TAS
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(2);
	Tas<int>*t1 = new Tas<int>(v1);
	Tas<int>*t2 = new Tas<int>();
	t2->afficher();
	int valMin;
	valMin = t2->extraireMin();
	cout << valMin << endl;

	t2->afficher();
*/


	//TESTS CLASSE TASID
	Tasid<string, int> *monTasid = new Tasid<string,int>();
	monTasid->ajouterElement(pair<string,int>("A",1));
	monTasid->ajouterElement(pair<string,int>("B",4));
	monTasid->ajouterElement(pair<string,int>("C",3));
	monTasid->ajouterElement(pair<string,int>("D",2));
	monTasid->ajouterElement(pair<string,int>("B",2));

	monTasid->afficher();



    return 0;
    
}
