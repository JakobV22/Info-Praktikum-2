/*
 * main.cpp
 *
 *  Created on: 22.10.2024
 *      Author: vogel
 */
#include "Fahrzeug.h"

void vAufgabe_1(){
	Fahrzeug fF1;
	Fahrzeug* fF2 = new Fahrzeug;
	Fahrzeug* fF3 = new Fahrzeug("Pimmel");
	delete fF2;
	delete fF3;

}


int main() {
	vAufgabe_1();
}



