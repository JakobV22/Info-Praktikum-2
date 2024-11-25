/*
 * Fahren.h
 *
 *  Created on: 25.11.2024
 *      Author: vogel
 */

#ifndef FAHREN_H_
#define FAHREN_H_
#include "Verhalten.h"
#include "Fahrzeug.h"


class Fahren: public Verhalten {
public:
	Fahren();
	Fahren(Weg& rWeg);
	virtual ~Fahren();
	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;
};

#endif /* FAHREN_H_ */
