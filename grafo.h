#include "vertice.h"
#include <list>

const int MAX = 200;

#define Nodo pair<Vertice, int>

class Grafo {
	private:
		int cantidad;
		List<Nodo> vecinos[MAX];

	public:
		Grafo();
		~Grafo();
};