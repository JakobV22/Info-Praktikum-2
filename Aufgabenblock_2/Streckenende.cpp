/*
 * Streckenende.cpp
 *
 *  Created on: 28.11.2024
 *      Author: vogel
 */

#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"

Streckenende::Streckenende() {
	// TODO Auto-generated constructor stub

}
Streckenende::Streckenende(Fahrzeug& rFahrzeug, Weg& rWeg):
	Fahrausnahme(rFahrzeug,rWeg){

	// TODO Auto-generated constructor stub

}
/**
 * wird bei throw von Streckenende aufgerufen
 * Gibt Meldung über Ausnahme aus
 * Setzt richtige Werte für Gesamtstrecke und Abschnitt für Fahrzeug Objekt
 */
void Streckenende::vBearbeiten() {
	std::cout << "'Ausnahme: Streckenende ist aufgetreten für Fahrzeug: "
			<< p_pFahrzeug->vGetName() << " auf Weg: " << p_pWeg->vGetName() << std::endl;
	p_pFahrzeug->setGesamtstrecke(p_pFahrzeug->getGesamtstrecke() + (p_pWeg->dGetLaenge()- p_pFahrzeug->getAbschnittStrecke()));		//notwendig?
	p_pWeg->pAbgabe(*p_pFahrzeug);
}
Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}

