/*
 * Fahrzeug.cpp
 *
 *  Created on: 21.10.2024
 *      Author: vogel
 */

#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Weg.h"
#include "Fahren.h"
#include "Parken.h"

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
		Simulationsobjekt(sName) {

}

/**
 * Konstruktor
 * Erweitert Standardkonstruktor um Initialisierung des Namen + Max. Geschwindigkeit (>= 0)
 */
Fahrzeug::Fahrzeug(std::string sName, double dMaxGeschwindigkeit) :
		Simulationsobjekt(sName), p_dMaxGeschwindigkeit(
				(dMaxGeschwindigkeit >= 0) ? dMaxGeschwindigkeit : 0) {

}

/**
 * Standarddestruktor
 */
Fahrzeug::~Fahrzeug() {
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
			<< "Gesamtstrecke" << std::setw(20)<< "Abschnitt Strecke" << std::setw(20) << "Gesamtverbrauch"
			<< std::setw(15) << "Tankinhalt" << std::setw(15)
			<< "akt. Geschwindigkeit" << std::endl;
	std::cout << std::setfill('-') << std::setw(85) << "-" << std::endl;
	std::cout << std::setfill(' ');

}

/**
 * vAusgaben gibt die ID, den Namen, die Max. Geschwindigkeit und die Gesamtstrecke im zu vKopf passendem Format aus
 * Überladung von << op für ostream Objekt
 */
void Fahrzeug::vAusgeben(std::ostream &o) const {
	Simulationsobjekt::vAusgeben(o);
	o << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right)
			<< std::setw(20) << p_dMaxGeschwindigkeit << std::setw(15)
			<< p_dGesamtstrecke<<std::setw(15)
			<< p_dAbschnittStrecke;

}

/**
 * Simulationsobjekt::vSimulieren setzt neue lokale Zeit und neuen Zeitpunkt letzter Aktualisierung
 * Überladung für Unterklasse Fahrzeug errechnet zudem neue Gesamtstrecke
 */
void Fahrzeug::vSimulieren() {

	if (p_dLetzteAktualisierung != dGlobaleZeit) {
			double dZeitVergangen = dGlobaleZeit - p_dLetzteAktualisierung;
			double dStreckeGefahren = p_pVerhalten->dStrecke(*this, dZeitVergangen);
			p_dGesamtstrecke += dStreckeGefahren;
			p_dAbschnittStrecke += dStreckeGefahren;
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
double Fahrzeug::dGeschwindigkeit() const {
	return p_dMaxGeschwindigkeit;
}

/**
 * Überladung des < Operators, Vergleicht Fahrzeuge anhand der zurückgelegten Gesamtstrecke
 */
bool Fahrzeug::operator<(const Fahrzeug &fFahrzeug2) {
	if (p_dGesamtstrecke < fFahrzeug2.p_dGesamtstrecke) {
		return true;
	} else
		return false;
}

/**
 * Überladung des = Operators, Überträgt Name und Max. Geschwindigkeit eines Fahrzeug Objektes auf ein anderes
 */
void Fahrzeug::operator =(const Fahrzeug &fFahrzeug2) {
	p_sName = fFahrzeug2.p_sName;
	p_dMaxGeschwindigkeit = fFahrzeug2.p_dMaxGeschwindigkeit;

}

/**
 * Linked neuen Weg zu Fahrzeug Objekt für: Fahrendes Fahrzeug
 */
void Fahrzeug::vNeueStrecke(Weg& rWeg){
	std::unique_ptr<Fahren> pNewVerhalten = std::make_unique<Fahren>(rWeg);
	p_pVerhalten = move(pNewVerhalten);							//alte Instanz gelöscht da unqiue ptr
	p_dAbschnittStrecke = 0;

}

/**
 * Überladung von neueStrecke für den Fall: Parkende Autos
 */
void Fahrzeug::vNeueStrecke(Weg& rWeg, double dStartzeitpunkt){
	std::unique_ptr<Parken> pNewVerhalten = std::make_unique<Parken>(rWeg, dStartzeitpunkt);
	p_pVerhalten = move(pNewVerhalten);							//alte Instanz gelöscht da unqiue ptr
	p_dAbschnittStrecke = 0;

}
double Fahrzeug::getAbschnittStrecke(){
	return p_dAbschnittStrecke;
}
double Fahrzeug::getGesamtstrecke(){
	return p_dGesamtstrecke;
}
std::string Fahrzeug::getName(){
	return p_sName;
}
void Fahrzeug::setGesamtstrecke(double dGesamtstrecke){
	p_dGesamtstrecke = dGesamtstrecke;
}
void Fahrzeug::setAbschnittStrecke(double dAbschnittStrecke){
	p_dAbschnittStrecke = dAbschnittStrecke;
}

