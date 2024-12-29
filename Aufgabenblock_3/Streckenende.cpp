/*
 * Streckenende.cpp
 *
 *  Created on: 28.11.2024
 *      Author: vogel
 */

#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Kreuzung.h"

Streckenende::Streckenende() {
	// TODO Auto-generated constructor stub

}
Streckenende::Streckenende(Fahrzeug &rFahrzeug, Weg &rWeg) :
		Fahrausnahme(rFahrzeug, rWeg) {

	// TODO Auto-generated constructor stub

}
/**
 * wird bei throw von Streckenende aufgerufen
 * Gibt Meldung über Ausnahme aus
 * Setzt richtige Werte für Gesamtstrecke und Abschnitt für Fahrzeug Objekt
 * leitet Abgabe durch den entsprechenden Weg ein (und damit Löschen des Fahzeuug Objektes aus der Liste des Weges + generell)
 */
void Streckenende::vBearbeiten() {
	std::cout << "'Ausnahme: Streckenende ist aufgetreten für Fahrzeug: "
			<< p_pFahrzeug->vGetName() << " auf Weg: " << p_pWeg->vGetName()
			<< std::endl;
	p_pFahrzeug->setGesamtstrecke(
			p_pFahrzeug->getGesamtstrecke()
					+ (p_pWeg->dGetLaenge() - p_pFahrzeug->getAbschnittStrecke()));	//notwendig?

	std::shared_ptr<Weg> pNeuerWeg = p_pWeg->pGetZielkreuzung()->pZufaelligerWeg(*p_pWeg); //Generiert Zufälligen Weg aus Zielkreuzung

			pNeuerWeg->vAnnahme(p_pWeg->pAbgabe(*p_pFahrzeug));	// Dieser Weg nimmt Fahrzeug an, während alter Weg dieses abgibt


	std::cout << "ZEIT			:" << dGlobaleZeit << std::endl;
	std::cout << "KREUZUNG			:" << p_pWeg->pGetZielkreuzung()->vGetName()<< ", " <<p_pWeg->pGetZielkreuzung()->dGetTankstelle()  << std::endl;
	std::cout << "WECHSEL			:"<< pNeuerWeg->vGetName() << "->"<< p_pWeg->vGetName() << std::endl;
	std::cout << "FAHRZEUG			:"<< *p_pFahrzeug << std::endl;
}
Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}

