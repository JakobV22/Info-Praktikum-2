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
#include "SimuClient.h"

Simulation::Simulation() {
	// TODO Auto-generated constructor stub

}

Simulation::~Simulation() {
	// TODO Auto-generated destructor stub
}


/**
 * Erhält Eingabestrom und erzeugt aus diesem das komplette Verkehrsnetz
 */
void Simulation::vEinlesen(std::istream &i, bool bMitGrafik) {
	std::string sTemp;
	std::string sTemp2;
	double dStartzeitpunkt;
	int iZeilenCounter = 0;

	i >> sTemp;
	while (!i.eof()) {				//bis Dokumentende
		iZeilenCounter++;
		try {


			if (sTemp == "KREUZUNG") {			//Suche nach KEYWORD



				//erstelle entsprechende Kreuzung
				std::shared_ptr<Kreuzung> NeuKreuzung = std::make_shared<
						Kreuzung>();
				i >> *NeuKreuzung;

				//Prüfe ob Kreuzung bereits vorhanden
				auto it = pMapKreuzungen.find(NeuKreuzung->vGetName());
				if (it != pMapKreuzungen.end()) {
					throw std::runtime_error("Kreuzung bereits vorhanden");
				}

				//Ansonsten Füge Kreuzung der SimMap hinzu
				pMapKreuzungen.insert(
						std::pair<std::string, std::shared_ptr<Kreuzung>>(
								NeuKreuzung->vGetName(), NeuKreuzung));
				//für Grafik
				if (bMitGrafik) {

					//Lese X/Y Koordinaten ein
					double dXCoord;
					double dYCoord;
					i >> sTemp;
					dXCoord = stod(sTemp);
					i >> sTemp;
					dYCoord = stod(sTemp);

					//Zeichne damit Kreuzung
					bZeichneKreuzung(dXCoord, dYCoord);

				}
			} else if (sTemp == "STRASSE") {		//Suche nach KEYWORD

				// Straße Einlesen:
				std::string sNameK1;
				std::string sNameK2;
				i >> sNameK1;
				i >> sNameK2;

				std::string sNameW1;
				std::string sNameW2;
				i >> sNameW1;
				i >> sNameW2;

				int iStrassenlaenge;
				i >> sTemp;
				iStrassenlaenge = stoi(sTemp);

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


				//Überprüfe ob Quell- und Zielkreuzungen existieren
				//sonst runtime error
				auto it1 = pMapKreuzungen.find(sNameK1);
				auto it2 = pMapKreuzungen.find(sNameK2);

				if (it1 == pMapKreuzungen.end()
						|| it2 == pMapKreuzungen.end()) {
					throw std::runtime_error(
							"Runtime Error:Gesuchte Kreuzung nicht vorhanden (Strasse)");
				}
				else {
					//Falls beide existieren, erstelle die STraße mit Kreuzung::vVerbinde
					Kreuzung::vVerbinde(sNameW1, sNameW2, iStrassenlaenge,
							it1->second, it2->second, eTempolimit,
							bUeberholverbot);
				}

				//für Grafik
				if(bMitGrafik){

					//Lese Anzahl Koordinaten ein
					int iAnzahlCoords;
					int iTempCoord;
					i>>sTemp;
					iAnzahlCoords = stoi(sTemp);
					int iCoords[2*iAnzahlCoords];

					for (int j = 0; j < 2*iAnzahlCoords; j++){
						//lese die Koordinaten einzelnd ein und speichere diese im iCoords array
						i>>sTemp;
						iTempCoord = stoi(sTemp);
						iCoords[j] = iTempCoord;
					}

					//zeichne Straße mit Koordinatenarray
					bZeichneStrasse(sNameW1, sNameW2, iStrassenlaenge, iAnzahlCoords, iCoords);
				}
			} else if (sTemp == "PKW") {								//Suche nach KEYWORD


				//Einlesen PKW
				std::unique_ptr<PKW> NeuPKW = std::make_unique<PKW>();
				i >> *NeuPKW;
				i >> sTemp;		//Startkreuzung
				i >> sTemp2;	//Zeitpunkt losfahren
				dStartzeitpunkt = stod(sTemp2);

				//Prüfe ob Startkreuzung existiert
				//sonst runtime error
				auto it = pMapKreuzungen.find(sTemp);
				if (it == pMapKreuzungen.end()) {
					throw std::runtime_error(
							"Runtime Error: Gesuchte Kreuzung nicht vorhanden (PKW)");

				}
				else {
					//wenn Kreuzung existiert, nimmt diese Kreuzung den PKW an
					it->second->vAnnahme(move(NeuPKW), dStartzeitpunkt);
				}

			} else if (sTemp == "FAHRRAD") {								//Suche nach KEYWORD
				//Einlesen Fahrrads

				std::unique_ptr<Fahrrad> NeuFahrrad =
						std::make_unique<Fahrrad>();
				i >> *NeuFahrrad;
				i >> sTemp;		//Startkreuzung
				i >> sTemp2;	//Startzeitpunkt
				dStartzeitpunkt = stod(sTemp2);

					//Prüfe ob Startkreuzung existiert
					//ggf runtime error
				auto it = pMapKreuzungen.find(sTemp);
				if (it == pMapKreuzungen.end()) {
					throw std::runtime_error(
							"Runtime Error: Gesuchte Kreuzung nicht vorhanden (Fahrrad)");

				}
				else {
					//wenn Kreuzung existiert, nimmt diese das Fahrrad an
					it->second->vAnnahme(move(NeuFahrrad), dStartzeitpunkt);
				}

			} else {
				//Falsches Keyword Fehler
				throw std::runtime_error("Unbekanntes Keyword in Zeile");
			}

			i >> sTemp;	//Einlesen des nächsten Keywords

		} catch (std::exception &e) {			//Fangen der Exceptions
			std::cout << "In Zeile " << iZeilenCounter << ":	" << e.what();
			exit(EXIT_FAILURE);

		}

	}
}
/**
 * Simuliert alle Kreuzungen für angegebene Dauer mit angegebenem Zeitschritt
 */
void Simulation::vSimulieren(double dDauer, double dZeitschritt) {
	for (dGlobaleZeit = 0; dGlobaleZeit <= dDauer; dGlobaleZeit +=
			dZeitschritt) {
		for (auto it = pMapKreuzungen.begin(); it != pMapKreuzungen.end();
				it++) {
			it->second->vSimulieren();
		}
	}
}
