/*
 * Kreuzung.h
 *
 *  Created on: 28.12.2024
 *      Author: vogel
 *
 *
 *
 *  Speichert in Liste Wege, die von ihr Wegführen
 *  Kann ggf Autos mit "Tankstelle" volltanken
 */

#ifndef KREUZUNG_H_
#define KREUZUNG_H_
#include "Simulationsobjekt.h"
#include <memory>

class Weg;
class Fahrzeug;
enum class Tempolimit
;
class Kreuzung: public Simulationsobjekt {

protected:
	std::list<std::shared_ptr<Weg>> p_pWege;
	double p_dTankstelle;
public:
	Kreuzung();
	Kreuzung(std::string sName, double dTankstelle = 0);
	virtual ~Kreuzung();
	static void vVerbinde(std::string sWeg1, std::string sWeg2,
			double dWeglaenge, std::shared_ptr<Kreuzung> pKreuzung1,
			std::shared_ptr<Kreuzung> pKreuzung2, Tempolimit tTempolimit,
			bool bUeberholverbot = true);
	void vTanken(Fahrzeug &rFahrzeug);
	void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeitpunkt);
	void vSimulieren();
	double dGetTankstelle();
	std::shared_ptr<Weg> pZufaelligerWeg(Weg&);
	virtual void vEinlesen(std::istream& i) override;

};

#endif /* KREUZUNG_H_ */
