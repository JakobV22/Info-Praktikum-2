/*
 * PKW.cpp
 *
 *  Created on: 28.10.2024
 *      Author: vogel
 */

#include "PKW.h"

PKW::PKW() :
		Fahrzeug() {
	p_dTankinhalt = p_dTankvolumen / 2.00;

}
PKW::PKW(std::string sName, double dMaxGeschwindigkeit, const double dVerbrauch) :
		Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch) {

}
PKW::PKW(std::string sName, double dMaxGeschwindigkeit, const double dVerbrauch,
		double dTankvolumen) :
		Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(
				dTankvolumen) {

}
double PKW::dTanken(double dMenge) {
	if (dMenge == std::numeric_limits<double>::infinity()
			|| p_dTankinhalt + dMenge >= p_dTankvolumen) {
		double dTemp = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		return dTemp;
	} else {
		p_dTankinhalt += dMenge;
		return dMenge;
	}
}
void PKW::vSimulieren() {

	if (p_dLetzteAktualisierung != dGlobaleZeit) {
		double dZeitVergangen = dGlobaleZeit - p_dLetzteAktualisierung;

		p_dZeit += dZeitVergangen;
		p_dLetzteAktualisierung = dGlobaleZeit;

		if (p_dTankinhalt == 0)
			return;
		else {
			p_dGesamtstrecke += (dZeitVergangen * p_dMaxGeschwindigkeit);
			double dBenzinVerbraucht = (dZeitVergangen * p_dVerbrauch) / 100.00;
			p_dTankinhalt -= dBenzinVerbraucht;
			if (p_dTankinhalt < 0)
				p_dTankinhalt = 0;
		}

	}
}
void PKW::vAusgeben(){
	Fahrzeug::vAusgeben();
	std::cout << std::setw(20) << (p_dGesamtstrecke * p_dVerbrauch)/100.00 << std::setw(15) << p_dTankinhalt;
}
PKW::~PKW() {
	// TODO Auto-generated destructor stub
}

