/*! \brief Classe Noeud.
 *
 *  Contient tous les éléments associés à un Noeud.
 */
#ifndef ARBRERN_HPP
#define ARBRERN_HPP
#include "arbrebinrec.hpp"
#include <iostream>
using namespace std;

class Arbrern : public ArbreBinRec{

    public:
        Arbrern():ArbreBinRec(){}
        Arbrern(int _val):ArbreBinRec(_val){}
        ~Arbrern();

        // fonctions de parenté
        Noeud* parent(Noeud* n);
        Noeud* grandparent(Noeud* n);
        Noeud* oncle(Noeud* n);
        Noeud* frere(Noeud* n); 
        void rotation_gauche(Noeud* a);
        void rotation_droite(Noeud* a);


};
#endif