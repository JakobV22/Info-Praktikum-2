/*
 * Kreuzung.h
 *
 *  Created on: 28.12.2024
 *      Author: vogel
 */

#ifndef KREUZUNG_H_
#define KREUZUNG_H_
#include "Simulationsobjekt.h"
#include <memory>

class Weg;
enum class Tempolimit;
class Kreuzung: public Simulationsobjekt {

protected:
	std::list<std::shared_ptr<Weg>> p_pWege;
	double p_dTankstelle;
public:
	Kreuzung();
	virtual ~Kreuzung();
	static void vVerbinde(std::string sWeg1, std::string sWeg2, double dWeglaenge, std::shared_ptr<Kreuzung> pKreuzung1, std::shared_ptr<Kreuzung> pKreuzung2, Tempolimit tTempolimit, bool bUeberholverbot);
};

#endif /* KREUZUNG_H_ */
