/*
 * Fahren.cpp
 *
 *  Created on: 25.11.2024
 *      Author: vogel
 */

#include "Fahren.h"
#include "Weg.h"
#include "Streckenende.h"

Fahren::Fahren() {
	// TODO Auto-generated constructor stub

}
Fahren::Fahren(Weg& rWeg):
	Verhalten(rWeg){


}
Fahren::~Fahren() {
	// TODO Auto-generated destructor stub
}

/**
 * Errechnet in gegebenem Zeitintervall zurückgelegte Strecke
 * Falls diese + vorherige Abschnittstrecke größer als Weg-Länge: Exception Streckenende
 * sonst return zurückgelegte Strecke
 */
double Fahren::dStrecke (Fahrzeug& aFzg, double dZeitIntervall){
				double dZurueckgelegt = (dZeitIntervall * aFzg.dGeschwindigkeit());
				if (dZurueckgelegt + aFzg.getAbschnittStrecke() >= p_pWeg->dGetLaenge()){
					throw Streckenende(aFzg, *p_pWeg);
					//return (p_pWeg->dGetLaenge() - aFzg.getAbschnittStrecke()) ;
				}
				else return dZurueckgelegt;
}
