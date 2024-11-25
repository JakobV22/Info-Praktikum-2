/*
 * Verhalten.h
 *
 *  Created on: 25.11.2024
 *      Author: vogel
 */

#ifndef VERHALTEN_H_
#define VERHALTEN_H_
class Weg;
class Fahrzeug;
class Verhalten {

protected:
	Weg* p_pWeg;
public:
	Verhalten();
	Verhalten(Weg& wWeg);
	virtual ~Verhalten();
	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;
};

#endif /* VERHALTEN_H_ */
