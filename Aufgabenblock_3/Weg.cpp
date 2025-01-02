/*
 * Weg.cpp
 *
 *  Created on: 20.11.2024
 *      Author: vogel
 */

#include "Weg.h"
#include "Fahrzeug.h"
#include "Losfahren.h"
#include "Streckenende.h"




Weg::Weg() :
		Simulationsobjekt() {
	// TODO Auto-generated constructor stub

}
Weg::Weg(std::string sName, double dLaenge, Tempolimit eTempolimit, bool bUeberholverbot, std::shared_ptr<Kreuzung> pZielkreuzung) :

		Simulationsobjekt(sName), p_dLaenge(dLaenge), p_eTempolimit(eTempolimit), p_bUeberholverbot(bUeberholverbot),p_pZielkreuzung(pZielkreuzung) {

}

Weg::~Weg() {
	// TODO Auto-generated destructor stub
}

/**
 * returnt Tempolimit aus enum Klasse als double
 */
double Weg::dGetTempolimit() const {
	return (double) (p_eTempolimit);
}

/**
 * Simuliert jedes Fahrzeug aus der Fahrzeugliste einzelnd
 * Fängt ggf Exceptions up und ruft die entsprechende Bearbeitungsfunktion auf
 * Aktualisiert Fahrzeugliste am Anfang und Ende (ganze Liste auf einmal)
 * Zeichnet alle Fahrzeuge
 */
void Weg::vSimulieren() {

	//Simulieren
	p_pFahrzeuge.vAktualisieren();
	setVirtuelleSchranke(dGetLaenge());		//für vorderes Fahrzeug nur Wegende limitierung
	for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++) {
		try {
			(*it)->vSimulieren();
			double Schranke = (*it)->dGetSchranke();
			setVirtuelleSchranke(Schranke);
		} catch (Fahrausnahme &e) {
			e.vBearbeiten();
		}
	}
	p_pFahrzeuge.vAktualisieren();
	//Zeichnen
	for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++) {
		(*it)->vZeichnen(*this);
	}
}
/**
 * Gibt Daten des Weges und Fahrzeuge auf diesem Weg in bestimmtem Format aus
 */
void Weg::vAusgeben(std::ostream &o) const {
	Simulationsobjekt::vAusgeben(o);
	o << std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left)
			<< ":" << std::resetiosflags(std::ios::left)
			<< std::setiosflags(std::ios::right) << std::setw(5) << p_dLaenge
			<< " ";

	o << "(";
	for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++) {
		o << (*it)->vGetName() << " "; // ......
	}
	o << ")";

}
void Weg::vKopf() const {
	std::cout << std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left) << std::setw(3) << "ID"
			<< std::resetiosflags(std::ios::left)
			<< std::setiosflags(std::ios::right) << "|" << std::setw(6)
			<< std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left) << "Name"
			<< std::resetiosflags(std::ios::left)
			<< std::setiosflags(std::ios::right) << "|"
			<< std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left) << std::setw(5) << "Laenge"
			<< std::resetiosflags(std::ios::left)
			<< std::setiosflags(std::ios::right) << "|" << std::setw(15)
			<< std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left) << "Fahrzeuge" << std::endl;
	std::cout << std::setfill('-') << std::setw(85) << "-" << std::endl;
	std::cout << std::setfill(' ');

}

/**
 * Getter Funktion
 */
double Weg::dGetLaenge() const {
	return p_dLaenge;
}

/**
 * Fahrzeug unique ptr wird auf neuem Weg aufgenommen
 *
 * Fahrzeug Objekt ruft neueStrecke Funktion auf
 * unique ptr wird anschließend in Fahrzeugliste des Wegobjektes gemoved
 */
void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug) {
	pFahrzeug->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(move(pFahrzeug));
}

/**
 * für Parkende Autos
 */
void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug,
		double dStartzeitpunkt) {
	pFahrzeug->vNeueStrecke(*this, dStartzeitpunkt);
	p_pFahrzeuge.push_front(move(pFahrzeug));
}

/**
 * Sucht übergebenes Fahrzeug in Liste anhand ID
 * Speichert unique:ptr auf dieses (für return)
 * Löscht Listeneintrag
 */
std::unique_ptr<Fahrzeug> Weg::pAbgabe(const Fahrzeug &rFahrzeug) {
	for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++) {

		if (*it == nullptr) continue;		//alhamdulillah vertagte Liste macht Aua

		if ((*it)->getID() == rFahrzeug.getID()) {
					std::unique_ptr<Fahrzeug> pTemp = move(*it);
					p_pFahrzeuge.erase(it);
					return pTemp;

				}

			}
			return nullptr;
		}
void Weg::setVirtuelleSchranke(double dPosition){
	if (dPosition != 0) p_dVirtuelleSchranke = dPosition;
}

double Weg::getVirtuelleSchranke(){
	if (p_bUeberholverbot == true){
	return p_dVirtuelleSchranke;
	}
	else return p_dLaenge;
}
std::shared_ptr<Kreuzung> Weg::pGetZielkreuzung(){
	return p_pZielkreuzung.lock();
}
std::shared_ptr<Weg> Weg::pGetRueckweg(){
	return p_pRueckweg.lock();
}
void Weg::setRueckweg(std::shared_ptr<Weg> pRueckweg){
	p_pRueckweg = pRueckweg;
}

