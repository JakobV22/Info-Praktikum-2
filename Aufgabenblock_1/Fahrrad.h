/*
 * Fahrrad.h
 *
 *  Created on: 28.10.2024
 *      Author: vogel
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_
#include "Fahrzeug.h"

class Fahrrad: public Fahrzeug {
public:
	Fahrrad();
	virtual ~Fahrrad();
	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
};

#endif /* FAHRRAD_H_ */