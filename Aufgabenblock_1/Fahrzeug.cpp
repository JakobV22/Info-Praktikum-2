/*
 * Fahrzeug.cpp
 *
 *  Created on: 21.10.2024
 *      Author: vogel
 */

#include "Fahrzeug.h"


Fahrzeug::Fahrzeug() {
	p_dLetzteAktualisierung = dGlobaleZeit;
	std::cout << "Objekt wurde mit Standardkonstruktor erstellt: " << p_sName
			<< ", " << p_iID << std::endl;

}
Fahrzeug::Fahrzeug(std::string sName) :
		p_sName(sName) {

	std::cout << "Objekt wurde mit Nichtstandardkonstruktor erstellt: "
			<< p_sName << ", " << p_iID << std::endl;
}

Fahrzeug::Fahrzeug(std::string sName, double dMaxGeschwindigkeit) :
		p_sName(sName), p_dMaxGeschwindigkeit(
				(dMaxGeschwindigkeit >= 0) ? dMaxGeschwindigkeit : 0) {

	std::cout << "Objekt wurde mit Nichtstandardkonstruktor2 erstellt: "
			<< p_sName << ", " << p_iID << ", " << p_dMaxGeschwindigkeit
			<< std::endl;

}

Fahrzeug::~Fahrzeug() {
	std::cout << "Objekt wurde mit Standarddestruktor gelöscht: " << p_sName
			<< ", " << p_iID << std::endl;
}
void Fahrzeug::vKopf() {
	std::cout << std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left) << std::setw(5) << "ID"
			<< std::resetiosflags(std::ios::left)
			<< std::setiosflags(std::ios::right) << std::setw(5) << "Name"
			<< std::setw(20) << "MaxGeschwindigkeit" << std::setw(15)
			<< "Gesamtstrecke" << std::setw(20) << "Gesamtverbrauch"
			<< std::setw(15) << "Tankinhalt" <<std::setw(15) << "akt. Geschwindigkeit" << std::endl;
	std::cout << std::setfill('-') << std::setw(85) << "-" << std::endl;
	std::cout << std::setfill(' ');

}
void Fahrzeug::vAusgeben(std::ostream& o) const{
	o << std::resetiosflags(std::ios::left)
			<< std::setiosflags(std::ios::right) << std::setw(3) << p_iID
			<< std::setw(2) << "" << std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left) << std::setw(5) << p_sName
			<< std::resetiosflags(std::ios::left)
			<< std::setiosflags(std::ios::right) << std::setw(20)
			<< p_dMaxGeschwindigkeit << std::setw(15) << p_dGesamtstrecke;

}

void Fahrzeug::vSimulieren() {

	if (p_dLetzteAktualisierung != dGlobaleZeit) {
		double dZeitVergangen = dGlobaleZeit - p_dLetzteAktualisierung;
		p_dGesamtstrecke += (dZeitVergangen * dGeschwindigkeit());
		p_dZeit += dZeitVergangen;
		p_dLetzteAktualisierung = dGlobaleZeit;

	}

}
double Fahrzeug::dTanken(double dMenge) {
	return 0;
}
double Fahrzeug::dGeschwindigkeit() const{
	return p_dMaxGeschwindigkeit;
}
bool Fahrzeug::operator< (const Fahrzeug& fFahrzeug2){
	if (p_dGesamtstrecke < fFahrzeug2.p_dGesamtstrecke){
		return true;
	}
	else return false;
}
void Fahrzeug::operator =(const Fahrzeug& fFahrzeug2){
	p_sName = fFahrzeug2.p_sName;
	p_dMaxGeschwindigkeit = fFahrzeug2.p_dMaxGeschwindigkeit;

}
