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
#include "vertagt_liste.h"

/**
 * Klasse Weg verwaltet die Fahrzeuge auf dem jeweiligen Weg (in VListe)
 * Simuliert alle Fahrzeuge in Liste
 * Besitzt ein Tempolimit und kann dieses Abfragen
 * Nimmt neue Fahrzeuge auf (Fahrend und Parkend möglich), löst dabei für jeweiliges Fahrzeug Trennung von altem Weg aus
 * Kann Fahrzeuge abgeben (werden momentan aus Liste gelöscht und somit generell)
 */

class Fahrzeug;
class Kreuzung;


class Weg: public Simulationsobjekt {

protected:
	double p_dLaenge = 0;
	vertagt::VListe<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit = Tempolimit::Autobahn;
	bool p_bUeberholverbot;
	double p_dVirtuelleSchranke = 0;
	const std::weak_ptr<Kreuzung> p_pZielkreuzung;
	std::weak_ptr<Weg> p_pRueckweg;

public:
	Weg();
	Weg(std::string sName, double dLaenge, Tempolimit eTempolimit =
			Tempolimit::Autobahn, bool bUeberholverbot = true, std::shared_ptr<Kreuzung> pZielkreuzung = nullptr);
	virtual ~Weg();
	double dGetTempolimit() const;
	virtual void vSimulieren() override;
	virtual void vAusgeben(std::ostream &o) const override;
	void vKopf() const;
	double dGetLaenge() const;
	void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug);
	void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeitpunkt);
	std::unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug &rFahrzeug);
	void setVirtuelleSchranke(double dPosition);
	double getVirtuelleSchranke();
	std::shared_ptr<Kreuzung> pGetZielkreuzung();
	std::shared_ptr<Weg> pGetRueckweg();
	void setRueckweg(std::shared_ptr<Weg> pRueckweg);

};

#endif /* WEG_H_ */
