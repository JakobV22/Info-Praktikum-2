/*
 * Fahrrad.cpp
 *
 *  Created on: 28.10.2024
 *      Author: vogel
 */

#include "Fahrrad.h"
#include "Fahrzeug.h"

/**
 * Standardkonstruktor
 */
Fahrrad::Fahrrad() {
	// TODO Auto-generated constructor stub

}


/**
 * Konstruktor, ruft Konstruktor von Basisklasse Fahrzeug auf
 */
Fahrrad::Fahrrad (std::string sName, double dMaxGeschwindigkeit):
		Fahrzeug(sName, dMaxGeschwindigkeit)
{

}

/**
 * Überlädt Tanken Funktion für Fahrräder
 * Fahrräder könne nicht Tanken, deshalb return Tankmenge 0
 */
double Fahrrad::dTanken(double dMenge) {
	return 0;
}

/**
 * Überladung von Fahrzeug::dGeschwindigkeit
 * Fahrrad verliert mit zunehmender Strecke an Geschwindigkeit, fährt jedoch mindestens 12kmh
 */
double Fahrrad::dGeschwindigkeit() const {

	double dNewGeschwindigkeit = p_dMaxGeschwindigkeit
			* (1 - p_dGesamtstrecke * 0.005);
	if (dNewGeschwindigkeit < 12)
		return 12.00;
	else
		return dNewGeschwindigkeit;
}


/**
 * Überlädt Fahrzeug::Asugeben
 * Fügt zusätzliche Asugabe von aktueller Geschwindigkeit in passendem Format hinzu
 */
void Fahrrad::vAusgeben(std::ostream& o) const{
	Fahrzeug::vAusgeben(o);
	o << std::setw(20) << "" << std::setw(15) << "" << std::setw(15)
			<< dGeschwindigkeit();

}

/**
 * Standarddekonstruktor
 */
Fahrrad::~Fahrrad() {
	// TODO Auto-generated destructor stub
}

