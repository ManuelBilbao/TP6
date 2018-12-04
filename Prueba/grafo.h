#include <list>

const int MAX = 200;
const int VERTICES = 8;

#define Nodo pair<int, int>

using namespace std;

class Grafo {
	private:
		int cantidad;
		list<Nodo> vecinos[MAX];

	public:
		Grafo();
		int obtener_cantidad();
		list<Nodo> obtener_vecinos(int i);
		void mostrar();
};