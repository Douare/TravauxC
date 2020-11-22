#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <map>
#include <stdbool.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
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
    	void dijkstra(S s);      
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
	if ( m.find(s) != m.end() ){
		vector<pair<S,P> > &v = m[s];
		v.push_back(pair<S,P>(a,p));
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
				cout << "Arete " << a << " supprimé" << endl;
				break;
			}
		}
	}
}

template<class S, class P> void Graph<S,P>::supprimerSommet(S s){
	if ( m.find(s) != m.end() ){
		m.erase(s);
		cout << "Sommet " << s << " supprimé" << endl;
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

/*
template<class S, class P> void Graph<S,P>::dijkstra(S s){ //s sommet de départ
	map<S,P> visite ();
	visite[s]=0;
	for (typename map< S , vector < pair<S,P> > >::iterator it = m.begin() ; it != m.end() ; it++){
		for (typename vector <pair<S,P> >::iterator itv = m[it].begin() ; itv != m[it].end() ; itv++){
			//Sommet non-visité
			if(visite.count(m[it].itv.first())<1){ //la fct count retroune 1 si l'élément est présent, 0 sinon
				visite.insert(m[it].itv.first());
				visite[m[it].itv] = m[it].itv.second();
			//Sommet visité
			}else{
				if(visite[m[it].itv.first()]){
			}
		}
	}
}

*/

