/*
 * Fahrzeug.h
 *
 *  Created on: 21.10.2024
 *      Author: vogel
 *
 *
 *      Basisklasse
 *      enthält grundlegende Methoden
 */
#include "Simulationsobjekt.h"
#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
extern double dGlobaleZeit;

class Fahrzeug: public Simulationsobjekt {
protected:


	double p_dMaxGeschwindigkeit = 0;
	double p_dGesamtstrecke = 0;



public:
	Fahrzeug();
	Fahrzeug(const Fahrzeug&) = delete;
	Fahrzeug(std::string sName);
	Fahrzeug(std::string sName, double dMaxGeschwindigkeit);
	virtual ~Fahrzeug();
	virtual void vAusgeben(std::ostream& o) const override;
	static void vKopf();
	virtual void vSimulieren() override;
	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
	virtual double dGeschwindigkeit() const;
	bool operator < (const Fahrzeug& fFahrzeug2);
	virtual void operator =(const Fahrzeug& fFahrzeug2);
};

#endif /* FAHRZEUG_H_ */
