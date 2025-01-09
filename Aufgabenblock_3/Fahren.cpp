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
 *
 * Überprüft ob Überholvorgang auf Strecke mit Überholverbot, begrenzt zu fahrende Strecke ggf
 */
double Fahren::dStrecke (Fahrzeug& aFzg, double dZeitIntervall){
				double dZurueckgelegt = (dZeitIntervall * aFzg.dGeschwindigkeit());

				if (dZurueckgelegt + aFzg.getAbschnittStrecke() > p_pWeg->getVirtuelleSchranke()){	//Überholverbot
					dZurueckgelegt = p_pWeg->getVirtuelleSchranke() - aFzg.getAbschnittStrecke();
				}

				if (dZurueckgelegt + aFzg.getAbschnittStrecke() >= p_pWeg->dGetLaenge() - std::numeric_limits<double>::epsilon()) {	//falls rundungsfeheler bei Schranke am ende

					aFzg.setGesamtstrecke(
								aFzg.getGesamtstrecke()
										+ (p_pWeg->dGetLaenge() - aFzg.getAbschnittStrecke()));	//notwendig?

					aFzg.setAbschnittStrecke(p_pWeg->dGetLaenge() - std::numeric_limits<double>::epsilon());
					throw Streckenende(aFzg, *p_pWeg);
					//return (p_pWeg->dGetLaenge() - aFzg.getAbschnittStrecke()) ;
				}
				else return dZurueckgelegt;
}
