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
/**
 * Aufruf bei Losfahren Exception eines Parkenden Autos
 * Weg->Abgabe des entsprechenden Fahrzeugs
 * Weg->vAnnahme des quasi identischen Fahrzeugs (neues Verhalten: Fahren)
 */
void Losfahren::vBearbeiten(){
	std::cout << "'Ausnahme: Losfahren' ist aufgetreten für Fahrzeug: " << p_pFahrzeug->vGetName() << " auf Weg: " << p_pWeg->vGetName()<< std::endl;
	std::unique_ptr<Fahrzeug> pFahrzeug = move(p_pWeg->pAbgabe(*p_pFahrzeug));
	p_pWeg->vAnnahme(move(pFahrzeug));

}
Losfahren::~Losfahren() {
	// TODO Auto-generated destructor stub
}

