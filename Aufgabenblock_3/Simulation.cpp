/*
 * Simulation.cpp
 *
 *  Created on: 02.01.2025
 *      Author: vogel
 */

#include "Simulation.h"
#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Kreuzung.h"
#include "Tempolimit.h"

Simulation::Simulation() {
	// TODO Auto-generated constructor stub

}

Simulation::~Simulation() {
	// TODO Auto-generated destructor stub
}
void Simulation::vEinlesen(std::istream &i) {
	std::string sTemp;
	std::string sTemp2;
	double dStartzeitpunkt;
	int iZeilenCounter = 0;

	i >> sTemp;
	while (!i.eof()) {
		iZeilenCounter++;
		try {
			if (sTemp == "KREUZUNG") {

				std::shared_ptr<Kreuzung> NeuKreuzung = std::make_shared<
						Kreuzung>();
				i >> *NeuKreuzung;
				pMapKreuzungen.insert(
						std::pair<std::string, std::shared_ptr<Kreuzung>>(
								NeuKreuzung->vGetName(), NeuKreuzung));
			} else if (sTemp == "STRASSE") {

				// Straße Einlesen:
				std::string sNameK1;
				std::string sNameK2;
				i >> sNameK1;
				i >> sNameK2;

				std::string sNameW1;
				std::string sNameW2;
				i >> sNameW1;
				i >> sNameW2;

				double dStrassenlaenge;
				i >> sTemp;
				dStrassenlaenge = stod(sTemp);

				Tempolimit eTempolimit;
				i >> sTemp;
				if (stod(sTemp) == 0)
					eTempolimit = Tempolimit::Innerorts;
				if (stod(sTemp) == 0)
					eTempolimit = Tempolimit::Außerorts;
				if (stod(sTemp) == 0)
					eTempolimit = Tempolimit::Autobahn;

				bool bUeberholverbot = 0;
				i >> sTemp;
				if (stod(sTemp) == 1)
					bUeberholverbot = 1;

				std::shared_ptr<Kreuzung> pK1 = std::make_shared<Kreuzung>(
						sNameK1);
				std::shared_ptr<Kreuzung> pK2 = std::make_shared<Kreuzung>(
						sNameK2);

				auto it1 = pMapKreuzungen.find(sNameK1);
				auto it2 = pMapKreuzungen.find(sNameK2);

				if (it1 == pMapKreuzungen.end()) {
					pMapKreuzungen.insert(
							std::pair<std::string, std::shared_ptr<Kreuzung>>(
									pK1->vGetName(), pK1));
				} else {

					throw std::runtime_error(
							"Runtime Error: Kreuzung Bereits vorhanden");

				}
				if (it2 == pMapKreuzungen.end()) {
					pMapKreuzungen.insert(
							std::pair<std::string, std::shared_ptr<Kreuzung>>(
									pK2->vGetName(), pK2));
				} else {
					throw std::runtime_error(
							"Runtime Error: Kreuzung Bereits vorhanden");

				}
				Kreuzung::vVerbinde(sNameW1, sNameW2, dStrassenlaenge, pK1, pK2,
						eTempolimit, bUeberholverbot);
			} else if (sTemp == "PKW") {
				//Einlesen PKW

				std::unique_ptr<PKW> NeuPKW = std::make_unique<PKW>();
				i >> *NeuPKW;
				i >> sTemp;
				i >> sTemp2;
				dStartzeitpunkt = stod(sTemp2);

				auto it = pMapKreuzungen.find(sTemp);
				if (it == pMapKreuzungen.end()) {
					throw std::runtime_error(
							"Runtime Error: Gesuchte Kreuzung nicht vorhanden");

				} else {
					it->second->vAnnahme(move(NeuPKW), dStartzeitpunkt);
				}

			} else if (sTemp == "FAHRRAD") {
				//Einlesen Fahrrads

				std::unique_ptr<Fahrrad> NeuFahrrad =
						std::make_unique<Fahrrad>();
				i >> *NeuFahrrad;
				i >> sTemp;
				i >> sTemp2;
				dStartzeitpunkt = stod(sTemp2);

				auto it = pMapKreuzungen.find(sTemp);
				if (it == pMapKreuzungen.end()) {
					throw std::runtime_error(
							"Runtime Error: Gesuchte Kreuzung nicht vorhanden");

				} else {
					it->second->vAnnahme(move(NeuFahrrad), dStartzeitpunkt);
				}

			} else {
				throw std::runtime_error("Unbekanntes Keyword in Zeile");
			}

			i >> sTemp;
		} catch (std::exception &e) {
			std::cout << "In Zeile " << iZeilenCounter << ":	"<< e.what();

		}

	}
}
void Simulation::vSimulieren(double dDauer, double dZeitschritt){
	for (dGlobaleZeit = 0; dGlobaleZeit<= dDauer; dGlobaleZeit += dZeitschritt){
	for(auto it = pMapKreuzungen.begin(); it != pMapKreuzungen.end(); it++){
		it->second->vSimulieren();
	}
	}
}
