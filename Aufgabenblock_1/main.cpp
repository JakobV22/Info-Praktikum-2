/*
 * main.cpp
 *
 *  Created on: 22.10.2024
 *      Author: vogel
 */
#include "Fahrzeug.h"
#include <memory>
#include <vector>
#include <string.h>


double dGlobaleZeit = 0.0;
typedef std::unique_ptr<Fahrzeug> u_ptrFahrzeug;

void vGesamtAusgabe(std::vector<u_ptrFahrzeug>& vecUniquePointerFahrzeugVector){
	Fahrzeug::vKopf();
	for (auto it = vecUniquePointerFahrzeugVector.begin() ; it != vecUniquePointerFahrzeugVector.end(); ++it){
		(*it)->vAusgeben();
		std::cout << "\n" << std::endl;
	}
}
void vAufgabe_1() {
	Fahrzeug fF1("F0");
	Fahrzeug *pF2 = new Fahrzeug("F2");
	Fahrzeug *pF3 = new Fahrzeug("F3");

	std::unique_ptr<Fahrzeug> pF4 = std::make_unique<Fahrzeug>("F4"); //(unique)
	std::unique_ptr<Fahrzeug> pF5 = std::make_unique<Fahrzeug>("F5 (unique)");
	std::shared_ptr<Fahrzeug> pF6 = std::make_shared<Fahrzeug>("F6 (shared)");
	std::shared_ptr<Fahrzeug> pF7 = std::make_shared<Fahrzeug>("F7 (shared)");
	std::shared_ptr<Fahrzeug> pF7x;
	std::unique_ptr<Fahrzeug> pF4x;
	pF4->vAusgeben();

	std::cout << "\n\nAnzahl Referenzen auf F7: " << pF7.use_count() << std::endl;
	pF7x = pF7;
	std::cout << "Anzahl Referenzen auf F7 (nach Zuweisung pF7x): "
			<< pF7.use_count() << "\n\n"<< std::endl;

	// pF4x = pF4; gibt natürlich Fehelermeldung, da unique pointer

	pF4->vAusgeben();
	std::cout <<std::endl;
	std::vector<std::unique_ptr<Fahrzeug>> vUniqueFahrzeugVector;
	vUniqueFahrzeugVector.push_back(move(pF4));		//move notwendig
	vUniqueFahrzeugVector.push_back(move(pF5));
	// vUniqueFahrzeugVector.push_back(pF6); nicht in unique_ptr vektor speicherbar, da shared pointr
	// vUniqueFahrzeugVector.push_back(pF7);
	vUniqueFahrzeugVector.clear();

	std::vector<std::shared_ptr<Fahrzeug>> vSharedFahrzeugVector;

	//vSharedFahrzeugVector.push_back(pF4); ebenfalls falscher typ (analog siehe oben)
	//vSharedFahrzeugVector.push_back(pF5);
	std::cout << "Anzahl Referenzen auf F6 (vor Speicherung im Vektor): " << pF6.use_count() << std::endl;
	std::cout << "Anzahl Referenzen auf F7 (vor Speicherung im Vektor): " << pF7.use_count() << std::endl;
	vSharedFahrzeugVector.push_back(pF6);
	vSharedFahrzeugVector.push_back(move(pF7));
	std::cout << "Anzahl Referenzen auf F6 (nach Speicherung im Vektor): " << pF6.use_count() << std::endl;
	std::cout << "Anzahl Referenzen auf F7 (nach Speicherung im Vektor): " << pF7.use_count() << std::endl;



	delete pF2;
	delete pF3;

}
void vAufgabe_1a(){

	std::vector<u_ptrFahrzeug> vecFahrzeugVector;
	std::string sNameInput;
	std::string sGeschwindigkeitInput;
	for (int i=0; i<3; i++){


	std::cout<< "Name :"<< std::endl;
	std::cin >> sNameInput;
	std::cout << "MaxGeschwindigkeit: "<< std::endl;
	std::cin >> sGeschwindigkeitInput;
	std::cout << "\n --- \n" << std::endl;
	double dMaxGeschwindikeitInput = stod(sGeschwindigkeitInput);
	u_ptrFahrzeug  fNewFahrzeug = std::make_unique<Fahrzeug>(sNameInput, dMaxGeschwindikeitInput);
	vecFahrzeugVector.push_back(move(fNewFahrzeug));
	}
	vGesamtAusgabe(vecFahrzeugVector);

}

int main() {

	vAufgabe_1a();

}

