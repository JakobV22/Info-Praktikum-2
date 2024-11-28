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
void Streckenende::vBearbeiten() {
	std::cout << "'Ausnahme: Losfahren' ist aufgetreten für Fahrzeug: "
			<< p_pFahrzeug->vGetName() << " auf Weg: " << p_pWeg->vGetName();
}
Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}

