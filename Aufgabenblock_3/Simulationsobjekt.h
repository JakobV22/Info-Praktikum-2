/*
 * Simulationsobjekt.h
 *
 *  Created on: 20.11.2024
 *      Author: vogel
 */

/**
 * Basisklasse für Fahrzeuge und Wege
 * virtual
 */

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <list>
#ifndef SIMULATIONSOBJEKT_H_
#define SIMULATIONSOBJEKT_H_
extern double dGlobaleZeit;

class Simulationsobjekt {

protected:
	std::string p_sName = "";
	static inline int p_iMaxID = 0;
	const int p_iID = p_iMaxID++;
	double p_dZeit = 0;
	double p_dLetzteAktualisierung = 0;

public:
	Simulationsobjekt();
	Simulationsobjekt(std::string sName);
	virtual ~Simulationsobjekt();
	virtual void vSimulieren() = 0;
	virtual void vAusgeben(std::ostream& o) const;
	std::string vGetName() const;
	double getLetzteAktualisierung() const;
};

std::ostream& operator<<(std::ostream &o, const Simulationsobjekt &s);

#endif /* SIMULATIONSOBJEKT_H_ */
