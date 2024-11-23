/*
 * Weg.h
 *
 *  Created on: 20.11.2024
 *      Author: vogel
 */

#ifndef WEG_H_
#define WEG_H_
#include "Simulationsobjekt.h"
#include "Tempolimit.h"
class Fahrzeug;


class Weg: public Simulationsobjekt {

protected:
	double p_dLaenge = 0;
	std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit = Tempolimit::Autobahn;

public:
	Weg();
	Weg(std::string sName, double dLaenge, Tempolimit eTempolimit = Tempolimit::Autobahn);
	virtual ~Weg();
	double dGetTempolimit();
	virtual void vSimulieren() override;
	virtual void vAusgeben(std::ostream& o) const override;
	void vKopf();
};

#endif /* WEG_H_ */
