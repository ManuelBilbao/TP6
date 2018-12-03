#include <string>

using namespace std;

class Vertice {
	private:
		string iata;
		Aeropuerto* datos_aeropuerto;

	public:
		Vertice(string iata, Aeropuerto* aeropuerto);
		string obtener_iata();
		Aeropuerto* obtener_aeropuerto();
		void asignar_iata(string iata);
		void asignar_aeropuerto(Aeropuerto* aeropuerto);
};