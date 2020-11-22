/*! \brief Classe Noeud.
 *
 *  Contient tous les éléments associés à un Noeud.
 */
#ifndef NOEUDCOLORE_HPP
#define NOEUDCOLORE_HPP

#include <iostream>
using namespace std;

class Noeudcolore : public Noeud{
    private:
        int couleur; // 0 : rouge / 1 : noir

    public:
        Noeudcolore():Noeud(){
            (*this).couleur = -1;
        }

        Noeudcolore(int _val, int coul):Noeud(_val) {
            (*this).couleur = coul;
        }

        Noeudcolore(const Noeudcolore &n):Noeud(n) {
            (*this).couleur = n.couleur;
        }


        Noeud* &get_couleur() { return couleur; }
        void set_couleur(int c) { (*this).couleur = c;}
        }
};
#endif
