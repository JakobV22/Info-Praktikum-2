/*
 * Kreuzung.cpp
 *
 *  Created on: 28.12.2024
 *      Author: vogel
 */

#include "Kreuzung.h"
#include "Weg.h"



Kreuzung::Kreuzung() {
	// TODO Auto-generated constructor stub

}

Kreuzung::~Kreuzung() {
	// TODO Auto-generated destructor stub
}

void Kreuzung::vVerbinde(std::string sWeg1, std::string sWeg2, double dWeglaenge, std::shared_ptr<Kreuzung> pKreuzung1, std::shared_ptr<Kreuzung> pKreuzung2, Tempolimit tTempolimit, bool bUeberholverbot){

	std::shared_ptr<Weg> pWeg1 = std::make_shared<Weg>(sWeg1, dWeglaenge, tTempolimit, bUeberholverbot, pKreuzung2 );
	std::shared_ptr<Weg> pWeg2 = std::make_shared<Weg>(sWeg2, dWeglaenge, tTempolimit, bUeberholverbot, pKreuzung1 );

}
