/*
 * Parken.h
 *
 *  Created on: 25.11.2024
 *      Author: vogel
 */

#ifndef PARKEN_H_
#define PARKEN_H_
#include "Verhalten.h"


class Parken: public Verhalten {

protected:
	double p_dStartzeitpunkt = 0;

public:
	Parken();
	Parken(Weg& rWeg, double dStartzeitpunkt);
	virtual ~Parken();
	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;
};

#endif /* PARKEN_H_ */
