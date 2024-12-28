/*
 * Verhalten.h
 *
 *  Created on: 25.11.2024
 *      Author: vogel
 */
/**
 * Basisklasse für "Fahren" und "Parken"
 * besitzt eine Referenz des Weges, auf dem sich das Fahrzeug befindet
 * virtual
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
	Weg* getWeg();
	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;
};

#endif /* VERHALTEN_H_ */
