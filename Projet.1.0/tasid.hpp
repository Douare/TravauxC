#ifndef TASID_HPP
#define TASID_HPP

#include <iostream>
#include <map>
#include <stdbool.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

template<class S, class P> class Tasid {
    private:
        map<int ,pair <S,P> >m;
    public:
        Tasid();
    	Tasid(map <int ,pair <S,P> > m_);
    	~Tasid();
        pair<S,P> extraireMin(); //extraire m[1] puis réordonner 
        void ajouterElement(pair<S,P> ele); //V dans le tas ? oui : comparer le poids sinon l'ajouter
        void decallerDroite(int i);
        void decallerGauche(int i);
        void afficher();  // affichage  
};
#endif

template< class S,class P> Tasid<S,P>::Tasid(){}

template< class S,class P> Tasid<S,P>::Tasid(map <int,pair <S,P> > m_){
    m = m_;
    //reordonner();
}

template< class S,class P> Tasid<S,P>::~Tasid(){}

/*
template<class K, class S,class P> T Tasid<S,P>::extraireMin(){
    if(v.size()>0){
        T min = v.front();
        v.erase(v.begin());
        reordonner();
        return min;
    }else{
        throw length_error("Aucun élément à extraire");
    }


}

*/


template< class S,class P> void Tasid<S,P>::afficher(){
    for (typename map< int , pair<S,P>  >::iterator it = (m).begin() ; it != (m).end() ; it++){
        cout<< "[";
        cout<< (it -> first) << ":";
        pair<S, P> myPair= it->second;
        cout<< "(" << (myPair.first) << "," <<  (myPair.second) << ")";
        cout<< "]\n";
    }
    cout<<endl;
}
