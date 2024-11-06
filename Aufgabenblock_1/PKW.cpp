/*
 * PKW.cpp
 *
 *  Created on: 28.10.2024
 *      Author: vogel
 */

#include "PKW.h"

/**
 * Standardkonstruktor
 * ruft Standardkonstruktor der Klasse Fahrzeug auf
 * Initialisiert zudem Tankinhalt
 */
PKW::PKW() :
		Fahrzeug() {
	p_dTankinhalt = p_dTankvolumen / 2.00;

}

/**
 * Konstruktor
 * ruft entsprechnden Konstruktor der Klasse Fahrzeug auf um zusätzlche Attribute zu initialisieren
 * Initialisierungsliste für p_dVerbrauch
 */
PKW::PKW(std::string sName, double dMaxGeschwindigkeit, const double dVerbrauch) :
		Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch) {
	p_dTankinhalt = p_dTankvolumen / 2.00;
}



/**
 * Konstruktor
 * ruft entsprechnden Konstruktor der Klasse Fahrzeug auf um zusätzlche Attribute zu initialisieren
 * Initialisierungsliste für p_dVerbrauch, p_dTankvolumen
 */
PKW::PKW(std::string sName, double dMaxGeschwindigkeit, const double dVerbrauch,
		double dTankvolumen) :
		Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(
				dTankvolumen) {
	p_dTankinhalt = p_dTankvolumen / 2.00;
}



/**
 * Überlädt Fahrzeug::dTanken
 * Tankt maximal voll (falls erwünschte Menge zu hoch oder std::...infinity), ansonsten gewünschte Menge
 * return tatsächlich getankte Menge
 */
double PKW::dTanken(double dMenge) {
	if (dMenge == std::numeric_limits<double>::infinity()
			|| p_dTankinhalt + dMenge >= p_dTankvolumen) {
		double dTemp = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		return dTemp;
	} else {
		p_dTankinhalt += dMenge;
		return dMenge;
	}
}

/**
 * Überlädt Fahrzeug::Simulieren
 * Überprüft Tankinhalt (nötig zum Fahren)
 * Berechnet zusätzlich zur Gesamtstrecke auch neuen Tankinhalt
 */
void PKW::vSimulieren() {

	if (p_dLetzteAktualisierung != dGlobaleZeit) {
		double dZeitVergangen = dGlobaleZeit - p_dLetzteAktualisierung;

		p_dZeit += dZeitVergangen;
		p_dLetzteAktualisierung = dGlobaleZeit;

		if (p_dTankinhalt == 0)
			return;
		else {
			p_dGesamtstrecke += (dZeitVergangen * dGeschwindigkeit());
			double dBenzinVerbraucht = (dZeitVergangen * dGeschwindigkeit() * p_dVerbrauch) / 100.00;
			p_dTankinhalt -= dBenzinVerbraucht;
			if (p_dTankinhalt < 0)
				p_dTankinhalt = 0;
		}

	}
}

/**
 * Überlädt Fahrzeug::vAusgeben
 * gibt zusätzlich Gesamtverbrauch und aktuellen Tankinhakt in zu vKopf passendem Format aus
 */
void PKW::vAusgeben(std::ostream& o) const{
	Fahrzeug::vAusgeben(o);
	o << std::setw(20) << (p_dGesamtstrecke * p_dVerbrauch)/100.00 << std::setw(15) << p_dTankinhalt << std::setw(15) << dGeschwindigkeit();
}

PKW::~PKW() {
	// TODO Auto-generated destructor stub
}

