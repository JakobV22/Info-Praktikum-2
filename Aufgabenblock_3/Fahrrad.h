/*
 * Fahrrad.h
 *
 *  Created on: 28.10.2024
 *      Author: vogel
 *
 *      erbt von Basisklasse Fahrzeug
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_
#include "Fahrzeug.h"

/**
 * Unterklasse von Fahrzeug
 * Geschwindigkeit nimmt mit zunehmender Strecke ab
 * Tanken default 0
 * andere Zeichnung
 */

class Fahrrad: public Fahrzeug {
public:
	Fahrrad();
	Fahrrad(const Fahrrad&) = delete;
	Fahrrad (std::string sName, double dMaxGeschwindigkeit);
	virtual ~Fahrrad();
	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
	virtual double dGeschwindigkeit() const override;
	virtual void vAusgeben(std::ostream& o) const override;
	virtual void vZeichnen(const Weg& rWeg) const override;

};

#endif /* FAHRRAD_H_ */
