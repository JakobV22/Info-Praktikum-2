#pragma once

#include "vertagt_aktion.h"
#include <list>
/**
 * Vertagt liste zur Verzögerung von Schreibe-Listenoperationen bis vAktualisieren (um Iteratoren nicht zu verlieren)
 */
namespace vertagt {
template<class T>
class VListe {
private:
	std::list<T> p_objekte;		//eigentliche Liste der Objekte
	std::list<std::unique_ptr<VAktion<T>>> p_aktionen;		//Liste der auszuführenden Aktionen

public:
	// Typdefinitionen
	using iterator = typename std::list<T>::iterator;
	using const_iterator = typename std::list<T>::const_iterator;

	// Konstruktoren
	VListe(){

	}
	// Benötigt man einen Standardkonstruktor?  Ja, weil Weg mit Instanz von VListe  instanziert wird

	VListe(std::list<T> &objekte) :
			p_objekte(objekte) {

	}
	// Destruktor
	~VListe() {
		vAktualisieren();
		p_objekte.clear();
	}

	void clear() {
		p_aktionen.clear();
	}

	// Lesefunktionen
	const_iterator begin() const {
		return p_objekte.begin();
	}
	const_iterator end() const {
		return p_objekte.end();
	}
	iterator begin() {
		return p_objekte.begin();
	}
	iterator end() {
		return p_objekte.end();
	}
	bool empty() const {
		return p_objekte.empty();
	}

	// Schreibfunktionen
	void push_back(T obj) {
		// Aktionselement für PushBack auf Liste erzeugen
		std::unique_ptr<VPushBack<T>> pPushBack =
				std::make_unique<VPushBack<T>>(p_objekte, std::move(obj));

		//Aktionselement an Ende der Aktionsliste pushen
		p_aktionen.push_back(std::move(pPushBack));
	}

	void push_front(T obj) {
		// Aktionselement für PushBack auf Liste erzeugen
		std::unique_ptr<VPushFront<T>> pPushFront = std::make_unique<
				VPushFront<T>>(p_objekte, std::move(obj));

		//Aktionselement an Ende der Aktionsliste pushen
		p_aktionen.push_back(std::move(pPushFront));
	}

	void erase(iterator it) {
		// Aktionselement für PushBack auf Liste erzeugen (hier Iterator statt Objekt !)
		std::unique_ptr<VErase<T>> pErase = std::make_unique<VErase<T>>(
				p_objekte, it);

		//Aktionselement an Ende der Aktionsliste pushen
		p_aktionen.push_back(std::move(pErase));
	}

	// Änderungen auf Objektliste übertragen
	void vAktualisieren() {
		// Änderungen auf Objektliste übertragen
		for (auto &pAktion : p_aktionen) {
			// Aktion ausführen
			pAktion->vAusfuehren();
		}
		// Aktionsliste löschen
		clear();				//p_aktionen.clear() warum extra funktion
	}
};
} // namespace vertagt
