/*
 * Parken.cpp
 *
 *  Created on: 25.11.2024
 *      Author: vogel
 */

#include "Parken.h"
#include "Fahrzeug.h"

Parken::Parken() {
	// TODO Auto-generated constructor stub

}
Parken::Parken(Weg& rWeg, double dStartzeitpunkt):
		Verhalten(rWeg), p_dStartzeitpunkt(dStartzeitpunkt){

}
Parken::~Parken() {
	// TODO Auto-generated destructor stub
}
double Parken::dStrecke(Fahrzeug& aFzg, double dZeitintervall){
	if (dGlobaleZeit <= p_dStartzeitpunkt) return 0;
	else{
		std::cout << "Startzeit von " << aFzg.getName() << " wurde überschritten" << std::endl;
		return (dZeitintervall * aFzg.dGeschwindigkeit());
	}


}
