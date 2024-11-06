/*
 * Fahrzeug.cpp
 *
 *  Created on: 21.10.2024
 *      Author: vogel
 */

#include "Fahrzeug.h"

/**
 * Standardkonstruktor
 * legt Erstellungszeitpunkt als Zeitpunkt der letzten Aktualisierung fest
 */
Fahrzeug::Fahrzeug() {
	p_dLetzteAktualisierung = dGlobaleZeit;
	std::cout << "Objekt wurde mit Standardkonstruktor erstellt: " << p_sName
			<< ", " << p_iID << std::endl;

}


/**
 * Konstruktor
 * Erweitert Standardkonstruktor um Initialisierung des Namen
 */
Fahrzeug::Fahrzeug(std::string sName) :
		p_sName(sName) {
	p_dLetzteAktualisierung = dGlobaleZeit;
	std::cout << "Objekt wurde mit Nichtstandardkonstruktor erstellt: "
			<< p_sName << ", " << p_iID << std::endl;
}


/**
 * Konstruktor
 * Erweitert Standardkonstruktor um Initialisierung des Namen + Max. Geschwindigkeit (>= 0)
 */
Fahrzeug::Fahrzeug(std::string sName, double dMaxGeschwindigkeit) :
		p_sName(sName), p_dMaxGeschwindigkeit(
				(dMaxGeschwindigkeit >= 0) ? dMaxGeschwindigkeit : 0) {
	p_dLetzteAktualisierung = dGlobaleZeit;
	std::cout << "Objekt wurde mit Nichtstandardkonstruktor2 erstellt: "
			<< p_sName << ", " << p_iID << ", " << p_dMaxGeschwindigkeit
			<< std::endl;

}

/**
 * Standarddestruktor
 */
Fahrzeug::~Fahrzeug() {
	std::cout << "Objekt wurde mit Standarddestruktor gelöscht: " << p_sName
			<< ", " << p_iID << std::endl;
}


/**
 * vKopf dient zur Ausgabe des Kopfes der Tabelle
 */
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

/**
 * vAusgaben gibt die ID, den Namen, die Max. Geschwindigkeit und die Gesamtstrecke im zu vKopf passendem Format aus
 * Überladung von << op für ostream Objekt
 */
void Fahrzeug::vAusgeben(std::ostream& o) const{
	o << std::resetiosflags(std::ios::left)
			<< std::setiosflags(std::ios::right) << std::setw(3) << p_iID
			<< std::setw(2) << "" << std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left) << std::setw(5) << p_sName
			<< std::resetiosflags(std::ios::left)
			<< std::setiosflags(std::ios::right) << std::setw(20)
			<< p_dMaxGeschwindigkeit << std::setw(15) << p_dGesamtstrecke;

}


/**
 * vSimulieren vergleicht aktuelle globale Zeit mit Zeitpunkt der letzten Aktualisierung des Objekts und errechnet die in dieser Zeit neu zurückgelegte Strecke
 * Setzt neuen Zeitpunkt letzter Aktualisierung
 * Aktualisiert Gesamtstrecke
 */
void Fahrzeug::vSimulieren() {

	if (p_dLetzteAktualisierung != dGlobaleZeit) {
		double dZeitVergangen = dGlobaleZeit - p_dLetzteAktualisierung;
		p_dGesamtstrecke += (dZeitVergangen * dGeschwindigkeit());
		p_dZeit += dZeitVergangen;
		p_dLetzteAktualisierung = dGlobaleZeit;

	}

}

/**
 * dTanken, als virtual vorgesehen, return standardmäßig 0 für alle Fahrzeuge, die nicht Tanken können
 */
double Fahrzeug::dTanken(double dMenge) {
	return 0;
}

/**
 * dGeschwindigkeitn, als virtual vorgesehen, return standardmäßig dMaxGeschwindigkeit für alle Fahrzeuge, dessen Geschwindigkeut konstant bleibt
 */
double Fahrzeug::dGeschwindigkeit() const{
	return p_dMaxGeschwindigkeit;
}

/**
 * Überladung des < Operators, Vergleicht Fahrzeuge anhand der zurückgelegten Gesamtstrecke
 */
bool Fahrzeug::operator< (const Fahrzeug& fFahrzeug2){
	if (p_dGesamtstrecke < fFahrzeug2.p_dGesamtstrecke){
		return true;
	}
	else return false;
}

/**
 * Überladung des = Operators, Überträgt Name und Max. Geschwindigkeit eines Fahrzeug Objektes auf ein anderes
 */
void Fahrzeug::operator =(const Fahrzeug& fFahrzeug2){
	p_sName = fFahrzeug2.p_sName;
	p_dMaxGeschwindigkeit = fFahrzeug2.p_dMaxGeschwindigkeit;

}
