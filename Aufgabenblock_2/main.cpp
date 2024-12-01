/*
 * main.cpp
 *
 *  Created on: 22.10.2024
 *      Author: vogel
 */
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include <memory>
#include <vector>
#include <string.h>
#include <math.h>
#include "SimuClient.h"
#include "vertagt_liste.h"
#include <random>
#include "stdlib.h"

extern double dGlobaleZeit = 0.0;
typedef std::unique_ptr<Fahrzeug> u_ptrFahrzeug;

/**
 * Überladung des << Operators für ostream Objekte
 * Ermöglicht das direkte und geordnete Ausgeben von Attributen von Fahrzeug Objekten
 */
std::ostream& operator<<(std::ostream &o, const Simulationsobjekt &s) {
	s.vAusgeben(o);
	return o;

}
/**
 * Simuliert alle Fahrzeug Objekte aus Vektor über bestimmte Zeit
 *  Gibt aktualisierte Daten jeweils über Konsole aus
 */
void vGesamtAusgabe1a(
		std::vector<u_ptrFahrzeug> &vecUniquePointerFahrzeugVector) {
	Fahrzeug::vKopf();
	for (dGlobaleZeit = 0.0; dGlobaleZeit < 5; dGlobaleZeit += 0.1) {

		for (auto it = vecUniquePointerFahrzeugVector.begin();
				it != vecUniquePointerFahrzeugVector.end(); ++it) {
			(*it)->vSimulieren();
			std::cout << *(*it);
			std::cout << "\n" << std::endl;
		}
	}
}
/**
 * Simuliert alle Fahrzeug Objekte in übergebenem Vektor ein mal
 * gibt aktualisierte Daten in Konsole aus
 */
void vGesamtAusgabe2(
		std::vector<u_ptrFahrzeug> &vecUniquePointerFahrzeugVector) {

	for (auto it = vecUniquePointerFahrzeugVector.begin();
			it != vecUniquePointerFahrzeugVector.end(); ++it) {
		(*it)->vSimulieren();
		std::cout << *(*it);
		std::cout << "\n" << std::endl;
	}
}

/**
 * vAufgabe_1 Hauptsächlich zum Testen grundlegender Funktionen
 * Auskomentiert, das Methode "Ausgeben" ersetzt durch Überladung des << Operators
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "PKW.h"
#include "Fahrrad.h"

using namespace std;
extern double dGlobaleZeit;

void vAufgabe_1() {
//	Fahrzeug fF1("F0");
//	Fahrzeug *pF2 = new Fahrzeug("F2");
//	Fahrzeug *pF3 = new Fahrzeug("F3");
//
//	std::unique_ptr<Fahrzeug> pF4 = std::make_unique<Fahrzeug>("F4"); //(unique)
//	std::unique_ptr<Fahrzeug> pF5 = std::make_unique<Fahrzeug>("F5 (unique)");
//	std::shared_ptr<Fahrzeug> pF6 = std::make_shared<Fahrzeug>("F6 (shared)");
//	std::shared_ptr<Fahrzeug> pF7 = std::make_shared<Fahrzeug>("F7 (shared)");
//	std::shared_ptr<Fahrzeug> pF7x;
//	std::unique_ptr<Fahrzeug> pF4x;
//	pF4->vAusgeben();
//
//	std::cout << "\n\nAnzahl Referenzen auf F7: " << pF7.use_count()
//			<< std::endl;
//	pF7x = pF7;
//	std::cout << "Anzahl Referenzen auf F7 (nach Zuweisung pF7x): "
//			<< pF7.use_count() << "\n\n" << std::endl;
//
//	// pF4x = pF4; gibt natürlich Fehelermeldung, da unique pointer
//
//	pF4->vAusgeben();
//	std::cout << std::endl;
//	std::vector<std::unique_ptr<Fahrzeug>> vUniqueFahrzeugVector;
//	vUniqueFahrzeugVector.push_back(move(pF4));		//move notwendig
//	vUniqueFahrzeugVector.push_back(move(pF5));
//	// vUniqueFahrzeugVector.push_back(pF6); nicht in unique_ptr vektor speicherbar, da shared pointr
//	// vUniqueFahrzeugVector.push_back(pF7);
//	vUniqueFahrzeugVector.clear();
//
//	std::vector<std::shared_ptr<Fahrzeug>> vSharedFahrzeugVector;
//
//	//vSharedFahrzeugVector.push_back(pF4); ebenfalls falscher typ (analog siehe oben)
//	//vSharedFahrzeugVector.push_back(pF5);
//	std::cout << "Anzahl Referenzen auf F6 (vor Speicherung im Vektor): "
//			<< pF6.use_count() << std::endl;
//	std::cout << "Anzahl Referenzen auf F7 (vor Speicherung im Vektor): "
//			<< pF7.use_count() << std::endl;
//	vSharedFahrzeugVector.push_back(pF6);
//	vSharedFahrzeugVector.push_back(move(pF7));
//	std::cout << "Anzahl Referenzen auf F6 (nach Speicherung im Vektor): "
//			<< pF6.use_count() << std::endl;
//	std::cout << "Anzahl Referenzen auf F7 (nach Speicherung im Vektor): "
//			<< pF7.use_count() << std::endl;
//
//	delete pF2;
//	delete pF3;
//
}

/**
 * vAufgabe_1a liest name und Maximalgeschwindigkeit für 3 Fahrzeuge in Konsole ein, speichert erzeugte Objekte in Vektor,
 * und ruft vGesamtAusgabe1a zur Simulation über bestimmte Zeit und Ausgabe auf
 */
void vAufgabe_1a() {

	std::vector<u_ptrFahrzeug> vecFahrzeugVector;
	std::string sNameInput;
	std::string sGeschwindigkeitInput;
	for (int i = 0; i < 3; i++) {

		std::cout << "Name :" << std::endl;
		std::cin >> sNameInput;
		std::cout << "MaxGeschwindigkeit: " << std::endl;
		std::cin >> sGeschwindigkeitInput;
		std::cout << "\n --- \n" << std::endl;
		double dMaxGeschwindikeitInput = stod(sGeschwindigkeitInput);
		u_ptrFahrzeug fNewFahrzeug = std::make_unique<Fahrzeug>(sNameInput,
				dMaxGeschwindikeitInput);
		vecFahrzeugVector.push_back(move(fNewFahrzeug));
	}
	vGesamtAusgabe1a(vecFahrzeugVector);

}

/**
 * Liest Anzahl zu erzeugender PKWs und Fahrräder aus Konsole ein
 * Konstruiert entsprechende Objekte und verwaltet sie in std::vector
 * Simuliert bis 3h, tankt dann auf (nur PKWs logisch) und simuliert weitere 2h
 * gibt bei jedem Sim Schritt vollständige aktualisierte Daten aus
 */
void vAufgabe_2() {
	std::vector<u_ptrFahrzeug> vecFahrzeugVector;
	std::string sInput;
	std::cout << "Wie viele PKWs? " << std::endl;
	std::cin >> sInput;
	int iIntInput1 = stoi(sInput);			//Einlesen der Inputs aus Konsole
	std::cout << "Wie viele Fahrräder? " << std::endl;
	std::cin >> sInput;
	int iIntInput2 = stoi(sInput);

	for (int i = 0; i < iIntInput1; i++) {				//Erstellung der Objekte
		std::string sName = "PKW" + std::to_string(i + 1);
		std::unique_ptr<PKW> fNewPKW = std::make_unique<PKW>(sName, 100, 5);
		vecFahrzeugVector.push_back(move(fNewPKW));

	}

	for (int i = 0; i < iIntInput2; i++) {
		std::string sName = "Bike" + std::to_string(i + 1);
		std::unique_ptr<Fahrrad> fNewFahrrad = std::make_unique<Fahrrad>(sName,
				25);
		vecFahrzeugVector.push_back(move(fNewFahrrad));

	}
	Fahrzeug::vKopf();								//Erhöhung der Globalen Zeit
	for (; dGlobaleZeit < 3.0; dGlobaleZeit += 0.25) {// jeweils Aufruf von vGesamtAsugabe2 zur Simulation und Asugabe aller Objekte des Vektors
		vGesamtAusgabe2(vecFahrzeugVector);
	}
	for (auto it = vecFahrzeugVector.begin(); it < vecFahrzeugVector.end();//Tanken nach 3h
			it++) {
		(*it)->dTanken();
	}
	for (; dGlobaleZeit < 5.0; dGlobaleZeit += 0.25) {		//weitere Simulation
		vGesamtAusgabe2(vecFahrzeugVector);

	}
}

/**
 * Test der überladenen Operatoren <<, = und <
 */
void vAufgabe_3() {
	std::vector<std::unique_ptr<Fahrzeug>> vecFahrzeuge;

	//Erstellung von Objekten aller 3 Klassen
	for (int i = 1; i < 4; i++) {
		std::unique_ptr<Fahrzeug> fF1 = std::make_unique<Fahrzeug>(
				"FZ" + std::to_string(i), i * 10);
		vecFahrzeuge.push_back(move(fF1));
	}
	for (int i = 1; i < 4; i++) {
		std::unique_ptr<PKW> fF1 = std::make_unique<PKW>(
				"PKW" + std::to_string(i), i * 10, i * 3);
		vecFahrzeuge.push_back(move(fF1));
	}

	for (int i = 1; i < 4; i++) {
		std::unique_ptr<Fahrrad> fF1 = std::make_unique<Fahrrad>(
				"FR" + std::to_string(i), i * 10);
		vecFahrzeuge.push_back(move(fF1));
	}
	Fahrzeug::vKopf();

	//Ein Simulationschritt für alle Objekte
	dGlobaleZeit++;
	for (auto it = vecFahrzeuge.begin(); it < vecFahrzeuge.end(); it++) {
		(*it)->vSimulieren();
		std::cout << *(*it) << std::endl;

	}
	//Ausgabe von ausgewählten Abfragen zur Überprüfung der Funktion der neuen Operatoren
	std::cout << " 0 kleiner 1:" << (*(vecFahrzeuge[0]) < *(vecFahrzeuge[1]))
			<< std::endl;
	std::cout << " 1 kleiner 0:" << (*(vecFahrzeuge[1]) < *(vecFahrzeuge[0]))
			<< std::endl;
	std::cout << " 7 kleiner 8:" << (*(vecFahrzeuge[7]) < *(vecFahrzeuge[8]))
			<< std::endl;
	*(vecFahrzeuge[2]) = *(vecFahrzeuge[0]);
	*(vecFahrzeuge[0]) = *(vecFahrzeuge[1]);
	*(vecFahrzeuge[5]) = *(vecFahrzeuge[0]);

	Fahrzeug::vKopf();
	for (auto it = vecFahrzeuge.begin(); it < vecFahrzeuge.end(); it++) {
		std::cout << *(*it) << std::endl;

	}

}
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "PKW.h"
#include "Fahrrad.h"

using namespace std;
extern double dGlobaleZeit;
double dEpsilon = 0.001;
void vAufgabe_AB1() {

	int l = 0; // Laufindex für gezielte AUsgabe
	vector<int> ausgabe { 15 };
	double dTakt = 0.3;

	std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
	vecFahrzeuge.push_back(make_unique<PKW>("Audi", 229, 9.6));
	vecFahrzeuge.push_back(make_unique<Fahrrad>("BMX", 24.7));
	for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dTakt) {
		auto itL = find(ausgabe.begin(), ausgabe.end(), l);
		if (itL != ausgabe.end()) {
			std::cout << std::endl << l << " Globalezeit = " << dGlobaleZeit
					<< std::endl;
			Fahrzeug::vKopf();
		}

		for (int i = 0; i < vecFahrzeuge.size(); i++) {
			vecFahrzeuge[i]->vSimulieren();
			if (fabs(dGlobaleZeit - 3.0) < dTakt / 2) {
				vecFahrzeuge[i]->dTanken();
			}
			if (itL != ausgabe.end()) {
				std::cout << *vecFahrzeuge[i] << endl;
			}
		}
		l++;
	}
	char c;
	std::cin >> c;
}
void vAufgabe_4() {
	Weg *wTestWeg = new Weg("moin", 100);
	wTestWeg->vKopf();
	std::cout << *wTestWeg << std::endl;
}

void vAufgabe_5() {
	Weg Weg1("TestWeg", 100, Tempolimit::Innerorts);
	std::unique_ptr<PKW> fF1 = std::make_unique<PKW>("fF1", 30, 5);
	std::unique_ptr<PKW> fF2 = std::make_unique<PKW>("fF2", 50, 5);
	std::unique_ptr<PKW> fF3 = std::make_unique<PKW>("fF3", 80, 5);
	std::unique_ptr<PKW> fFp1 = std::make_unique<PKW>("fFp1", 30, 5);
	std::unique_ptr<PKW> fFp2 = std::make_unique<PKW>("fFp2", 50, 5);
	std::unique_ptr<PKW> fFp3 = std::make_unique<PKW>("fFp3", 80, 5);
	Weg1.vAnnahme(move(fF1));
	Weg1.vAnnahme(move(fF2));
	Weg1.vAnnahme(move(fF3));
	Weg1.vAnnahme(move(fFp1), 0.5);
	Weg1.vAnnahme(move(fFp2), 1);
	Weg1.vAnnahme(move(fFp3), 2);
	Weg1.vKopf();
	std::cout << Weg1 << std::endl;

	for (; dGlobaleZeit <= 3; dGlobaleZeit += 0.5) {
		std::cout << "GLOBALE ZEIT: " << dGlobaleZeit << std::endl;
		Weg1.vSimulieren();
		std::cout << Weg1 << std::endl;
	}

}
void vAufgabe_6() {
	Weg Weg1("TestWeg", 500, Tempolimit::Innerorts);
	Weg Weg2("TestWeg2", 500, Tempolimit::Außerorts);
	std::unique_ptr<PKW> fF1 = std::make_unique<PKW>("Fiat", 30, 5);
	std::unique_ptr<PKW> fF2 = std::make_unique<PKW>("Audi", 100, 5);
	std::unique_ptr<PKW> fF3 = std::make_unique<PKW>("FiatP", 30, 5);
	std::unique_ptr<PKW> fF4 = std::make_unique<PKW>("AudiP", 100, 5);

	Weg1.vAnnahme(move(fF1));
	Weg1.vAnnahme(move(fF4), 3);
	Weg2.vAnnahme(move(fF2));
	Weg2.vAnnahme(move(fF3), 3);
	bInitialisiereGrafik(800, 800);
	int iCoords[] = { 200, 200, 600, 500 };
	bZeichneStrasse(Weg1.vGetName(), Weg2.vGetName(), 500, 2, iCoords);
	//vSleep(10000);
	for (; dGlobaleZeit <= 10; dGlobaleZeit += 0.25) {
		vSetzeZeit(dGlobaleZeit);
		std::cout << "GLOBALE ZEIT: " << dGlobaleZeit << std::endl;
		Weg1.vSimulieren();
		Weg2.vSimulieren();
		vSleep(100);
		std::cout << Weg1 << std::endl;
		std::cout << Weg2 << std::endl;
	}
}
void vAufgabe_6a() {
	std::list<int> lListe;
	int seed = 1;
	static std::mt19937 device(seed);
	std::uniform_int_distribution<int> dist(1, 10);
	for (int i = 0; i < 10; i++) {

		int iRanNum = dist(device);
		lListe.push_back(iRanNum);
	}
	vertagt::VListe vListe(lListe);

	//Liste ausgeben
	for (vertagt::VListe<int>::iterator it = vListe.begin(); it != vListe.end();
			it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n" << std::endl;
	//alle elemente >5 löschen
	for (vertagt::VListe<int>::iterator it = vListe.begin(); it != vListe.end();
			it++) {
		if (*it > 5) {
			vListe.erase(it);
		}
	}
	//Liste ausgeben
	for (vertagt::VListe<int>::iterator it = vListe.begin(); it != vListe.end();
			it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n" << std::endl;
	vListe.vAktualisieren();
	//Liste ausgeben
	for (vertagt::VListe<int>::iterator it = vListe.begin(); it != vListe.end();
			it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n" << std::endl;
	vListe.push_back(3);
	vListe.push_front(7);
	//Liste ausgeben
	for (vertagt::VListe<int>::iterator it = vListe.begin(); it != vListe.end();
			it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n" << std::endl;

	vListe.vAktualisieren();

	//Liste ausgeben
	for (vertagt::VListe<int>::iterator it = vListe.begin(); it != vListe.end();
			it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n" << std::endl;

}
int main() {
	vAufgabe_6();

}

