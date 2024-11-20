/*
 * Weg.h
 *
 *  Created on: 20.11.2024
 *      Author: vogel
 */

#ifndef WEG_H_
#define WEG_H_
#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Tempolimit.h"

class Weg: public Simulationsobjekt {

protected:
	double p_dLaenge = 0;
	std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit;

public:
	Weg();
	virtual ~Weg();
	double dGetTempolimit();
};

#endif /* WEG_H_ */
