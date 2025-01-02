/*
 * Simulation.h
 *
 *  Created on: 02.01.2025
 *      Author: vogel
 */
#include <iostream>
#include <memory>
#include <list>
#include <map>

#ifndef SIMULATION_H_
#define SIMULATION_H_
class Kreuzung;

class Simulation {
protected:
	std::list<std::shared_ptr<Kreuzung>> p_pKreuzungen;
	std::map<std::string, std::shared_ptr<Kreuzung>> pMapKreuzungen;
public:
	Simulation();
	virtual ~Simulation();
	void vEinlesen(std::istream& i);
	void vSimulieren(double dDauer, double dZeitschritt);
};

#endif /* SIMULATION_H_ */
;
