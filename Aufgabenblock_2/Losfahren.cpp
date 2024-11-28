/*
 * Losfahren.cpp
 *
 *  Created on: 28.11.2024
 *      Author: vogel
 */

#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"

Losfahren::Losfahren() {
	// TODO Auto-generated constructor stub

}
Losfahren::Losfahren(Fahrzeug& rFahrzeug, Weg& rWeg):
		Fahrausnahme(rFahrzeug, rWeg){

}
void Losfahren::vBearbeiten(){
	std::cout << "'Ausnahme: Losfahren' ist aufgetreten für Fahrzeug: " << p_pFahrzeug->vGetName() << " auf Weg: " << p_pWeg->vGetName()<< std::endl;
}
Losfahren::~Losfahren() {
	// TODO Auto-generated destructor stub
}

