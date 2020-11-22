/*! \brief Implémentation de la classe Noeud.
 *
 */
#include "noeud.hpp"

Noeud::Noeud() {
    (*this).fg = NULL;	
    (*this).fd = NULL;
    (*this).pere = NULL;
}

Noeud::Noeud(int _val) {
    (*this).couleur = -1;
    (*this).val = _val;
    (*this).fg = NULL;
    (*this).fd = NULL;
    (*this).pere = NULL;
}

Noeud::Noeud(const Noeud &n) {
    (*this).couleur = n.couleur;
    (*this).val = n.val;
    (*this).fg = n.fg;
    (*this).fd = n.fd;
    (*this).pere = n.pere;
}

Noeud::~Noeud() {
}

void Noeud::afficher() {
    cout << (*this).val << " ";
}
