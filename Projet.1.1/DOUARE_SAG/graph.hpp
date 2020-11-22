#ifndef GRAPH_HP
#define GRAPH_HPP


#include "tasid.hpp"
#include <iostream>
#include <map>
#include <stdbool.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>


using namespace std;

template<class S, class P> class Graph {
    private:

        map<S,vector< pair<S , P> > > m;
    public:
    	Graph();
    	~Graph();
    	void ajouterSommet(S s);
    	void ajouterArete(S s,const S a,const P p);
    	void supprimerSommet(S s);
    	void supprimerArete(S s, S a);
    	void afficher();
    	void dijkstra(pair<S,P> maPaire); 
    	void lireFichier(string fichier);  
    	vector<string> split(const string& s, char delimiter);
};
#endif


template<class S, class P> Graph<S,P>::Graph(){}

template<class S, class P> Graph<S,P>::~Graph(){}

template<class S, class P> void Graph<S,P>::ajouterSommet(S s){
	bool exist = false;
	for (typename map< S , vector <pair<S,P> > >::iterator it = m.begin() ; it != m.end() ; ++it){
		if( it -> first == s) {
			exist = true;
		}
	}
	if(!exist){
		m[s] =  vector < pair<S,P> >(0) ;
	}
}

template<class S, class P> void Graph<S,P>::ajouterArete(S s,S a,P p){

	if ( m.find(s) == m.end() ){
		ajouterSommet(a);
	}
	bool areteExiste = false;
	vector<pair<S,P> > &v = m[s];
	for (int i = 0; i < v.size(); ++i){
		if (v[i].first == a){
			areteExiste = true;
		}
	}
	if (!areteExiste){
		v.push_back(pair<S,P>(a,p));
	} else {
		cout << "Impossible d'ajouter, l'arete existe déjà." << endl;
	}		

	bool exist = false;
	for (typename map< S , vector < pair<S,P> > >::iterator it = m.begin() ; it != m.end() ; it++){
		if(it->first == a){
			exist = true;
		}
	}
	if(!exist){
		ajouterSommet(a);
	}
}

template<class S, class P> void Graph<S,P>::supprimerArete(S s, S a){
	if ( m.find(s) != m.end() ){
		for (typename vector <pair<S,P> >::iterator itv = m[s].begin() ; itv != m[s].end() ; itv++){
			if((*itv).first == a){
				m[s].erase(itv);
				break;
			}
		}
	}
}

template<class S, class P> void Graph<S,P>::supprimerSommet(S s){
	if ( m.find(s) != m.end() ){
		m.erase(s);
		for (typename map< S , vector < pair<S,P> > >::iterator it = m.begin() ; it != m.end() ; it++){
			supprimerArete(it->first,s);
		}
		
	}
}

template<class S, class P> void Graph<S,P>::afficher(){
	for (typename map< S , vector < pair<S,P> > >::const_iterator it = (m).begin() ; it != (m).end() ; it++){
		cout<< "[";
		cout<< (it -> first) << "]->[";
		for (typename vector <pair<S,P> >::const_iterator itv = (it->second).begin() ; itv != (it->second).end() ; itv++){
			pair<S, P> myPair= *itv;
			cout<< "[" << (myPair.first) << "," <<  myPair.second << "]";
			if (itv != (it->second).end()-1) {
				cout<< ",";
			}
		}
		cout<< "]\n";
	}
	cout<<endl;
}


template<class S, class P> void Graph<S,P>::dijkstra(pair<S,P> maPaire){ //mettre un poids de 0 par défaut	
	typename map<S,vector<pair<S,P> > >::iterator it = m.find(maPaire.first);
	if( it != m.end() ){
   		vector<S> *vect = new vector<S>();
   		if(m.size()>0){ 
   			pair<S,P> pere = maPaire;
   			Tasid<S,P> *tas = new Tasid<S,P>();
   			tas->ajouterElement(maPaire);
   			while(tas->taille()!=0){ //tant que tasid n'est pas vide
   				vector<pair<S,P> > voisins = m[pere.first];
				for (typename vector <pair<S,P> >::iterator it = voisins.begin() ; it != voisins.end() ; it++){
					pair<S,P> voisin = pair<S,P>(it->first,(it->second)+(pere.second));
					if (find(vect->begin(),vect->end(),voisin.first) == vect->end()){
						tas->ajouterElement(voisin);
					}
				}
				pere=tas->extraireMin();
   				vect->push_back(pere.first);
   			}
   			delete tas;
  		}
  		for (int i = 0; i < vect->size(); ++i){
			cout << (*vect)[i] << endl;
		}
		delete vect;
    }else{
        cout<<"Le sommet donné en argument n'existe pas dans le graphe."<<endl;
    }
    
	
}

template<class S, class P> vector<string> Graph<S,P>::split(const string& s, char delimiter){
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

template<class S, class P> void Graph<S,P>::lireFichier(string fich){
 	ifstream fichier(fich, ios::in);  // on ouvre
	if(fichier){
    	string str;  // déclaration d'une chaîne qui contiendra la ligne lue
    	int poids = 0;
    	vector<string> res;
    	while(getline(fichier, str)){
            res = split(str,' ');
            istringstream iss (res[2]);
			iss >> poids;
			ajouterArete(res[0],res[1],poids);
        }
        cout << endl;
        fichier.close();
    }else{
        cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
}