/*
 * Fahrausnahme.h
 *
 *  Created on: 28.11.2024
 *      Author: vogel
 */
 #include <exception>
 #include <stdexcept>
#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_

class Fahrzeug;
class Weg;

class Fahrausnahme: public std::exception{

protected:
 Fahrzeug* p_pFahrzeug;
 Weg* p_pWeg;

public:
	Fahrausnahme();
	Fahrausnahme(Fahrzeug& rFahrzeug, Weg& rWeg);
	virtual void vBearbeiten() = 0;
	virtual ~Fahrausnahme();
};

#endif /* FAHRAUSNAHME_H_ */
