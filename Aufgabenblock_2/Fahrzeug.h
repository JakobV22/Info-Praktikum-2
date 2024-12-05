/*
 * Fahrzeug.h
 *
 *  Created on: 21.10.2024
 *      Author: vogel
 *
 *
 *      Basisklasse
 *      enthält grundlegende Methoden
 */
#include "Simulationsobjekt.h"
#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
extern double dGlobaleZeit;


/**
 *
 * Fahrzeug Basisklasse (Kinder: PKW, Fahrrad)
 * Errechnet und Aktualisiert Gesamt-, Abschnittstrecken
 * Besitzt Atrribut Verhalten (Fahren oder Parken)
 * Fahreuge betankbar
 * können Weg mit vNeueStrecke den Weg wechseln
 */
class Verhalten;
class Weg;
class Fahrzeug: public Simulationsobjekt {
protected:


	double p_dMaxGeschwindigkeit = 0;
	double p_dGesamtstrecke = 0;
	std::unique_ptr<Verhalten> p_pVerhalten;
	double p_dAbschnittStrecke = 0;



public:
	Fahrzeug();
	Fahrzeug(const Fahrzeug&) = delete;
	Fahrzeug(std::string sName);
	Fahrzeug(std::string sName, double dMaxGeschwindigkeit);
	virtual ~Fahrzeug();
	virtual void vAusgeben(std::ostream& o) const override;
	static void vKopf();
	virtual void vSimulieren() override;
	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
	virtual double dGeschwindigkeit() const;
	bool operator < (const Fahrzeug& fFahrzeug2);
	virtual void operator =(const Fahrzeug& fFahrzeug2);
	void vNeueStrecke(Weg& rWeg);
	void vNeueStrecke(Weg& rWeg, double dStartzeitpunkt);
	double getAbschnittStrecke() const;
	double getGesamtstrecke() const ;
	void setVerhalten(std::unique_ptr<Verhalten> pVerhalten);
	void setGesamtstrecke(double dGesamtstrecke);
	void setAbschnittStrecke(double dAbschnittStrecke);
	virtual void vZeichnen(const Weg&) const;
	int getID() const;

};

#endif /* FAHRZEUG_H_ */
