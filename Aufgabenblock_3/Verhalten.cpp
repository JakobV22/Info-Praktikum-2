/*
 * Verhalten.cpp
 *
 *  Created on: 25.11.2024
 *      Author: vogel
 */

#include "Verhalten.h"
#include "Weg.h"
#include "Fahrzeug.h"

Verhalten::Verhalten() {
	// TODO Auto-generated constructor stub

}
Verhalten::Verhalten(Weg& wWeg):
	p_pWeg(&wWeg){
	// TODO Auto-generated constructor stub

}
Weg* Verhalten::getWeg(){
	return p_pWeg;
}
Verhalten::~Verhalten() {

}



