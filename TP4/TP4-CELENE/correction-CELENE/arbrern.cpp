#include "arbrern.hpp"

        Noeud* Arbrern::parent(Noeud* n){
            return n->get_pere();
        }

        Noeud* Arbrern::grandparent(Noeud* n){
            return parent(n)->get_pere();
        }

        Noeud* Arbrern::oncle(Noeud* n){
            return frere(parent(n));
        }

        Noeud* Arbrern::frere(Noeud* n){
            Noeud* pere = n->get_pere();
            if(pere->get_fd()->get_val()==n->get_val()){
                return pere->get_fg();
            }else{
                return pere->get_fd();
            }
        }

        void rotation_gauche(Noeud* a){
            Noeud* b = a->get_fd();
            if(a->get_pere()!=NULL){
                Noeud* pereA = a->get_pere();
                if(pereA->get_fg()->get_val()==a->get_val()){ //a est le fg de son pere
                    pereA->set_fg(b);
                }else{
                    pereA->set_fd(b);
                }
                b->set_pere(pereA);
            }
            a->set_fd(b->get_fg());
            b->set_fg(a);
            a->set_pere(b);
            b->set_pere(NULL);
        }