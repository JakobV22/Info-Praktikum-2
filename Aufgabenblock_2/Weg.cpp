/*
 * Weg.cpp
 *
 *  Created on: 20.11.2024
 *      Author: vogel
 */

#include "Weg.h"

Weg::Weg() {
	// TODO Auto-generated constructor stub

}

Weg::~Weg() {
	// TODO Auto-generated destructor stub
}

/**
 * returnt Tempolimit aus enum Klasse als double
 */
double Weg::dGetTempolimit(){
	return (double)(p_eTempolimit);
}
