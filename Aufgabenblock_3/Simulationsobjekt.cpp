/*
 * Simulationsobjekt.cpp
 *
 *  Created on: 20.11.2024
 *      Author: vogel
 */

#include "Simulationsobjekt.h"
#include <exception>
#include <stdexcept>

/**
 * Standardkonstruktor
 *
 */
Simulationsobjekt::Simulationsobjekt() {
	p_dLetzteAktualisierung = dGlobaleZeit;
	std::cout << "Objekt wurde mit Standardkonstruktor erstellt: " << p_sName
			<< ", " << p_iID << std::endl;

}

/**
 * Nichtstandardkonstruktor (Name)
 */
Simulationsobjekt::Simulationsobjekt(std::string sName) :
		p_sName(sName) {
	p_dLetzteAktualisierung = dGlobaleZeit;
	std::cout << "Objekt wurde mit Nichtstandardkonstruktor erstellt: "
			<< p_sName << ", " << p_iID << std::endl;
}

/**
 * Standarddestruktor
 */
Simulationsobjekt::~Simulationsobjekt() {

	std::cout << "Objekt wurde mit Standarddestruktor gelöscht: " << p_sName
			<< ", " << p_iID << std::endl;
}

/**
 * Gibt Daten des Objekts in bestimmtem Format aus (wird in Unterklassen erweitert)
 */
void Simulationsobjekt::vAusgeben(std::ostream &o) const {
	o << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right)
			<< std::setw(3) << p_iID << std::setw(2) << ""
			<< std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left) << std::setw(5) << p_sName;

}
/**
 * vSimulieren setzt neue lokale Zeit und neuen Zeitpunkt letzter Aktualisierung
 * virtual
 */
void Simulationsobjekt::vSimulieren() {

	if (p_dLetzteAktualisierung != dGlobaleZeit) {
		double dZeitVergangen = dGlobaleZeit - p_dLetzteAktualisierung;
		p_dZeit += dZeitVergangen;
		p_dLetzteAktualisierung = dGlobaleZeit;

	}

}
std::string Simulationsobjekt::vGetName() const {
	return p_sName;

}

double Simulationsobjekt::getLetzteAktualisierung() const {
	return p_dLetzteAktualisierung;
}
/**
 * Überladung des << Operators für ostream Objekte
 * Ermöglicht das direkte und geordnete Ausgeben von Attributen von Fahrzeug Objekten
 */
std::ostream& operator<<(std::ostream &o, const Simulationsobjekt &s) {
	s.vAusgeben(o);
	return o;

}
/**
 * Nimmt Eingabestream
 * Interpretiert Eingabe als Name und ändert namen des Simulationsobjektes entsprechend (nur falls noch kein Name vorhanden)
 * wirft ggf exception, die im Hauptprogramm gefangen wird
 */
void Simulationsobjekt::vEinlesen(std::istream &i) {
	if (p_sName == ""){
	std::string Eingabe;
	i >> Eingabe;
	p_sName = Eingabe;
	}
	else throw std::runtime_error("Runtime Error: Objekt hat bereits Namen");
}

/**
 * Überladung des Eingabeoperators für Simulationsobjekt
 */
std::istream& operator >>(std::istream &i, Simulationsobjekt &s) {
	s.vEinlesen(i);
	return i;
}
