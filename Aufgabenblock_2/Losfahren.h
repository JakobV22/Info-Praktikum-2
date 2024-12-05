/*
 * Losfahren.h
 *
 *  Created on: 28.11.2024
 *      Author: vogel
 */

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_
#include "Fahrausnahme.h"

// Exception für Parkende Autos bei Startzeitpunkt
class Losfahren: public Fahrausnahme {
public:
	Losfahren();
	Losfahren(Fahrzeug& rFahrzeug, Weg& rWeg);
	virtual ~Losfahren();
	virtual void vBearbeiten() override;
};

#endif /* LOSFAHREN_H_ */
