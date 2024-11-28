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
Weg::Weg(std::string sName, double dLaenge, Tempolimit eTempolimit) :

		Simulationsobjekt(sName), p_dLaenge(dLaenge), p_eTempolimit(eTempolimit) {
}

Weg::~Weg() {
	// TODO Auto-generated destructor stub
}

/**
 * returnt Tempolimit aus enum Klasse als double
 */
double Weg::dGetTempolimit() {
	return (double) (p_eTempolimit);
}
void Weg::vSimulieren(){
	for(auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++){
		try {
		(*it)->vSimulieren();
		}
		catch (Fahrausnahme& e){
			e.vBearbeiten();
		}
	}
}
void Weg::vAusgeben(std::ostream& o) const{
	Simulationsobjekt::vAusgeben(o);
	o<<std::resetiosflags(std::ios::right)
						<< std::setiosflags(std::ios::left) <<":"<<std::resetiosflags(std::ios::left)
						<< std::setiosflags(std::ios::right) <<std::setw(5)<< p_dLaenge<<" ";

	o<<"(";
	for(auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++){
			o << (*it)->vGetName() << ", Strecke:" << (*it)->getGesamtstrecke();		// ......
		}
	o<<")";


}
void Weg::vKopf(){
	std::cout << std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left) << std::setw(3) << "ID"
			<< std::resetiosflags(std::ios::left)
			<< std::setiosflags(std::ios::right) <<"|"<< std::setw(6) << std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left) << "Name"
			<< std::resetiosflags(std::ios::left)
						<< std::setiosflags(std::ios::right)<< "|" <<std::resetiosflags(std::ios::right)
						<< std::setiosflags(std::ios::left)<< std::setw(5) << "Laenge" << std::resetiosflags(std::ios::left)
						<< std::setiosflags(std::ios::right)<< "|"<< std::setw(15)
						<< std::resetiosflags(std::ios::right)
									<< std::setiosflags(std::ios::left)<< "Fahrzeuge"<< std::endl;
	std::cout << std::setfill('-') << std::setw(85) << "-" << std::endl;
	std::cout << std::setfill(' ');

}

/**
 * Getter Funktion
 */
double Weg::dGetLaenge(){
	return p_dLaenge;
}


/**
 * Fahrzeug unique ptr wird auf neuem Weg aufgenommen
 * Fahrzeug Objekt ruft neueStrecke Funktion auf
 * unique ptr wird anschließend in Fahrzeugliste des Wegobjektes gemoved
 */
void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug){
	pFahrzeug->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(move(pFahrzeug));
}
void Weg::vAnnahme (std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeitpunkt){
	pFahrzeug->vNeueStrecke(*this, dStartzeitpunkt);
		p_pFahrzeuge.push_front(move(pFahrzeug));
}
