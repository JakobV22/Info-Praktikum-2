/*
 * Losfahren.cpp
 *
 *  Created on: 28.11.2024
 *      Author: vogel
 */

#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Fahren.h"
#include "Verhalten.h"

Losfahren::Losfahren() {
	// TODO Auto-generated constructor stub

}
Losfahren::Losfahren(Fahrzeug& rFahrzeug, Weg& rWeg):
		Fahrausnahme(rFahrzeug, rWeg){

}
void Losfahren::vBearbeiten(){
	std::cout << "'Ausnahme: Losfahren' ist aufgetreten für Fahrzeug: " << p_pFahrzeug->vGetName() << " auf Weg: " << p_pWeg->vGetName()<< std::endl;
	std::unique_ptr<Fahren> pNewVerhalten = std::make_unique<Fahren>(*p_pWeg);
	p_pFahrzeug->setVerhalten(move(pNewVerhalten));
		///////////
}
Losfahren::~Losfahren() {
	// TODO Auto-generated destructor stub
}

