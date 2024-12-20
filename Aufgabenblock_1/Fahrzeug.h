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
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
extern double dGlobaleZeit;

class Fahrzeug {
protected:


	std::string p_sName = "";
	static inline int p_iMaxID = 0;
	const int p_iID = p_iMaxID++;
	double p_dMaxGeschwindigkeit = 0;
	double p_dGesamtstrecke = 0;
	double p_dZeit = 0;
	double p_dLetzteAktualisierung = 0;


public:
	Fahrzeug();
	Fahrzeug(const Fahrzeug&) = delete;
	Fahrzeug(std::string sName);
	Fahrzeug(std::string sName, double dMaxGeschwindigkeit);
	virtual ~Fahrzeug();
	virtual void vAusgeben(std::ostream& o) const;
	static void vKopf();
	virtual void vSimulieren();
	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
	virtual double dGeschwindigkeit() const;
	bool operator < (const Fahrzeug& fFahrzeug2);
	virtual void operator =(const Fahrzeug& fFahrzeug2);
};

#endif /* FAHRZEUG_H_ */
