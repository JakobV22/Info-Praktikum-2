/*
 * Fahrrad.cpp
 *
 *  Created on: 28.10.2024
 *      Author: vogel
 */

#include "Fahrrad.h"
#include "Fahrzeug.h"
Fahrrad::Fahrrad() {
	// TODO Auto-generated constructor stub

}
Fahrrad::Fahrrad (std::string sName, double dMaxGeschwindigkeit):
		Fahrzeug(sName, dMaxGeschwindigkeit)
{

}
double Fahrrad::dTanken(double dMenge) {
	return 0;
}
double Fahrrad::dGeschwindigkeit() const {

	double dNewGeschwindigkeit = p_dMaxGeschwindigkeit
			* (1 - p_dGesamtstrecke * 0.005);
	if (dNewGeschwindigkeit < 12)
		return 12.00;
	else
		return dNewGeschwindigkeit;
}
void Fahrrad::vAusgeben(std::ostream& o) const{
	Fahrzeug::vAusgeben(o);
	o << std::setw(20) << "" << std::setw(15) << "" << std::setw(15)
			<< dGeschwindigkeit();

}
Fahrrad::~Fahrrad() {
	// TODO Auto-generated destructor stub
}

