/*
 * Streckenende.h
 *
 *  Created on: 28.11.2024
 *      Author: vogel
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_
#include "Fahrausnahme.h"

/**
 * Exception für Fahrende Autos, die Ende des Weges erreichen
 * Verantwortlich für Löschen des Fahrzeugs aus Liste des entsprechnenden Weges
 */
class Streckenende: public Fahrausnahme {
public:
	Streckenende();
	Streckenende(Fahrzeug& rFahrzeug, Weg& rWeg);
	virtual ~Streckenende();
	virtual void vBearbeiten() override;
};

#endif /* STRECKENENDE_H_ */
