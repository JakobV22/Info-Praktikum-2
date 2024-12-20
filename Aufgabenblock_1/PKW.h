/*
 * PKW.h
 *
 *  Created on: 28.10.2024
 *      Author: vogel
 *
 *      erbt von Basisklasse Fahrzeug
 */

#ifndef PKW_H_
#define PKW_H_
#include "Fahrzeug.h"

class PKW: public Fahrzeug {

protected:
	const double p_dVerbrauch = 0; //in Liter / 100km
	const double p_dTankvolumen = 55; // in Liter
	double p_dTankinhalt = 0;

public:
	PKW();
	PKW(const PKW&) = delete;
	PKW(std::string sName, double dMaxGeschwindigkeit, const double dVerbrauch);
	PKW(std::string sName, double dMaxGeschwindigkeit, const double dVerbrauch,
			double dTankvolumen);
	virtual double dTanken(double dMenge =
			std::numeric_limits<double>::infinity()) override;
	virtual void vSimulieren() override;
	virtual void vAusgeben (std::ostream& o) const override;

	virtual ~PKW();
};

#endif /* PKW_H_ */
