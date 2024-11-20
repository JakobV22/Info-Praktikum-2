/*
 * Simulationsobjekt.cpp
 *
 *  Created on: 20.11.2024
 *      Author: vogel
 */

#include "Simulationsobjekt.h"

Simulationsobjekt::Simulationsobjekt() {
	p_dLetzteAktualisierung = dGlobaleZeit;
		std::cout << "Objekt wurde mit Standardkonstruktor erstellt: " << p_sName
				<< ", " << p_iID << std::endl;

}

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

void Simulationsobjekt::vAusgeben(std::ostream& o) const{
	o << std::resetiosflags(std::ios::left)
			<< std::setiosflags(std::ios::right) << std::setw(3) << p_iID
			<< std::setw(2) << "" << std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left) << std::setw(5) << p_sName;

}
/**
 * vSimulieren setzt neue lokale Zeit und neuen Zeitpunkt letzter Aktualisierung
 */
void Simulationsobjekt::vSimulieren() {

	if (p_dLetzteAktualisierung != dGlobaleZeit) {
		double dZeitVergangen = dGlobaleZeit - p_dLetzteAktualisierung;
		p_dZeit += dZeitVergangen;
		p_dLetzteAktualisierung = dGlobaleZeit;

	}

}

