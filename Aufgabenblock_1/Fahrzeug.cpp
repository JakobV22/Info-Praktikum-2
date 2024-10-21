/*
 * Fahrzeug.cpp
 *
 *  Created on: 21.10.2024
 *      Author: vogel
 */

#include "Fahrzeug.h"

Fahrzeug::Fahrzeug() {

	std::cout<< "Objekt wurde mit Standardkonstruktor erstellt: " << p_sName <<", "<< p_iID << std::endl;


}
Fahrzeug::Fahrzeug(std::string sName) :
	p_sName(sName)
{

	std::cout<< "Objekt wurde mit Nichtstandardkonstruktor erstellt: " << p_sName <<", "<< p_iID << std::endl;


}
Fahrzeug::~Fahrzeug() {
	std::cout<< "Objekt wurde mit Standarddestruktor gelöscht: " << p_sName << ", "<< p_iID << std::endl;
}

