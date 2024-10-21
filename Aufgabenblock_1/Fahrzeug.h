/*
 * Fahrzeug.h
 *
 *  Created on: 21.10.2024
 *      Author: vogel
 */
#include <string>
#include <iostream>

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

class Fahrzeug {
private:


	std::string p_sName = "";
	static inline int p_iMaxID = 0;
	const int p_iID = p_iMaxID++;

public:
	Fahrzeug();
	Fahrzeug(std::string sName);
	virtual ~Fahrzeug();
};

#endif /* FAHRZEUG_H_ */
