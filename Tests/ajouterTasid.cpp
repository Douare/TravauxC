
//  AJOUTER TASID


template<class S, class P> void Tasid<S,P>::decallerDroite(int i){ 
    for (int j = m.size()-1; j>i; j--){ //décaller tous les élé à droite de la fin à i
            m[j]=m[j-1];
    }
}

template<class S, class P> void Tasid<S,P>::decallerGauche(int i){ //decaller tous les élé à gauche de i à la fin
    for (int j = i; j<m.size()-1; j++){ // ---_--- > ------_
            m[j]=m[j+1];
    }
}



template<class S,class P> void Tasid<S,P>::ajouterElement(pair <S,P> ele){
       
    if(m.size()==0){
        m[0]=ele;
    }else{
        bool exist = false;
        m[m.size()]=ele; //agrandi le map de 1


        for (int i =0; i<m.size()-1; i++){ //on ne prend pas en compte le dernier élé qu'on a placé
            
            if( m[i].first == ele.first){ //si le sommet est présent
                if (m[i].second > ele.second){ //si on doit modifier le poids du sommet
                    decallerGauche(i);
                }else{
                    exist = true; //si y a pas de modif à faire sur le map
                }
                m.erase(m.size()-1);
                break;
            }

        }

        if(exist == false){
            for (int i = 0; i<m.size(); i++){
                if(m[i].second < ele.second){
                    decallerDroite(i);
                    m[i]=ele;
                    break;
                } 
            }
        }
    }
}
