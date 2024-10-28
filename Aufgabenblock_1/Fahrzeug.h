/*
 * Fahrzeug.h
 *
 *  Created on: 21.10.2024
 *      Author: vogel
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
	Fahrzeug(std::string sName);
	Fahrzeug(std::string sName, double dMaxGeschwindigkeit);
	virtual ~Fahrzeug();
	virtual void vAusgeben();
	static void vKopf();
	virtual void vSimulieren();
	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
};

#endif /* FAHRZEUG_H_ */
