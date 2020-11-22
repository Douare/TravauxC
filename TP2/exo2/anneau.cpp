#include "anneau.hpp"
using namepace std;

class Anneau {
	private:
		List<Noeud> L;

	public:
		Anneau();
		Anneau(list<Noeud> _L);
		~Anneau();

		list<Noeud>::iterator prev(list<Noeud>::iterator &it);

		short majorite();
		list<Noeud> get_anneau();

};
