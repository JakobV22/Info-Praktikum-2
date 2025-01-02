/*
 * Kreuzung.cpp
 *
 *  Created on: 28.12.2024
 *      Author: vogel
 */

#include "Kreuzung.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include <random>

Kreuzung::Kreuzung() {
	// TODO Auto-generated constructor stub

}

Kreuzung::~Kreuzung() {
	// TODO Auto-generated destructor stub
}
/**
 * Konstruktor
 * Erweitert Standardkonstruktor um Initialisierung des Namen
 */
Kreuzung::Kreuzung(std::string sName, double dTankstelle) :
		Simulationsobjekt(sName), p_dTankstelle(dTankstelle) {

}
void Kreuzung::vVerbinde(std::string sWeg1, std::string sWeg2,
		double dWeglaenge, std::shared_ptr<Kreuzung> pKreuzung1,
		std::shared_ptr<Kreuzung> pKreuzung2, Tempolimit tTempolimit,
		bool bUeberholverbot) {

	std::shared_ptr<Weg> pWeg1 = std::make_shared<Weg>(sWeg1, dWeglaenge,
			tTempolimit, bUeberholverbot, pKreuzung2); //Weg1 von Kreuzung 1 zu 2

	std::shared_ptr<Weg> pWeg2 = std::make_shared<Weg>(sWeg2, dWeglaenge,
			tTempolimit, bUeberholverbot, pKreuzung1); //Weg2 von Kreuzung 2 zu 1

	pWeg1->setRueckweg(pWeg2);
	pWeg2->setRueckweg(pWeg1);
	pKreuzung1->p_pWege.push_back(pWeg1);

	pKreuzung2->p_pWege.push_back(pWeg2);

}
void Kreuzung::vTanken(Fahrzeug &rFahrzeug) {
	if (p_dTankstelle > 0) {
		double dTankmenge = rFahrzeug.dTanken(
				std::numeric_limits<double>::infinity());
		p_dTankstelle -= dTankmenge;
		std::cout << "\n" << rFahrzeug.vGetName() << " hat " << dTankmenge << " getankt \n" << std::endl;
	}
}
double Kreuzung::dGetTankstelle() {
	return p_dTankstelle;
}
void Kreuzung::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug,
		double dStartzeitpunkt) {
	if (pFahrzeug != nullptr && !p_pWege.empty()) {
		vTanken(*pFahrzeug);
		p_pWege.front()->vAnnahme(move(pFahrzeug), dStartzeitpunkt);
	} else
		std::cout << "Gewünschte Kreuzung nicht angebunden" << std::endl;

}
void Kreuzung::vSimulieren() {
	for (auto it = p_pWege.begin(); it != p_pWege.end(); it++) {
		(*it)->vSimulieren();
		//std::cout << *(*it)<< std::endl;
	}
}
std::shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg &rWeg) {
	if (p_pWege.size() == 1) {
		return (p_pWege.front());//falls nur 1 Weg, diesen (Rueckweg) nehmen

	} else if (p_pWege.size() > 1) {

		int seed = 1;								//random setup
		static std::mt19937 device(seed);
		std::uniform_int_distribution<int> dist(0, p_pWege.size() - 2);
		int iRanNum = dist(device);
		int iCounter = 0;


		for (auto it = p_pWege.begin(); it != p_pWege.end(); it++) {

			if (((*it)->vGetName().compare(rWeg.pGetRueckweg()->vGetName()))
					!= 0) {									//falls Name von Weg aus Liste != Name des Hinweges
				if (iCounter == iRanNum) {					// Wird berücksichtigt bei Zufallsauswahl
					return *it;
				}
				iCounter++;
			}
		}

	} else
		return nullptr;

}
void Kreuzung::vEinlesen(std::istream &i) {
	Simulationsobjekt::vEinlesen(i);
	std::string Eingabe;
	std::cout << "\n\n Volumen der Tankstelle:		";
	i >> Eingabe;
	double dEingabe = stod(Eingabe);
	p_dTankstelle = dEingabe;
}

