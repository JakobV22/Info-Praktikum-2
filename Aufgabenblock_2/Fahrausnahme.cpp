/*
 * Fahrausnahme.cpp
 *
 *  Created on: 28.11.2024
 *      Author: vogel
 */

#include "Fahrausnahme.h"
#include "Weg.h"
#include "Fahrzeug.h"

Fahrausnahme::Fahrausnahme() {
	// TODO Auto-generated constructor stub

}

Fahrausnahme::Fahrausnahme(Fahrzeug& rFahrzeug, Weg& rWeg):
		p_pFahrzeug(&rFahrzeug), p_pWeg(&rWeg){

}


Fahrausnahme::~Fahrausnahme() {
	// TODO Auto-generated destructor stub
}

