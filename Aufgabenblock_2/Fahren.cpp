/*
 * Fahren.cpp
 *
 *  Created on: 25.11.2024
 *      Author: vogel
 */

#include "Fahren.h"
#include "Weg.h"

Fahren::Fahren() {
	// TODO Auto-generated constructor stub

}
Fahren::Fahren(Weg& rWeg):
	Verhalten(rWeg){


}
Fahren::~Fahren() {
	// TODO Auto-generated destructor stub
}

double Fahren::dStrecke (Fahrzeug& aFzg, double dZeitIntervall){
				double dZurückgelegt = (dZeitIntervall * aFzg.dGeschwindigkeit());
				if (dZurückgelegt + aFzg.getAbschnittStrecke() >= p_pWeg->dGetLaenge()){
					std::cout << "Ende des Weges erreicht für" << aFzg.getName()<< std::endl;
					return (p_pWeg->dGetLaenge() - aFzg.getAbschnittStrecke()) ;
				}
				else return dZurückgelegt;
}
