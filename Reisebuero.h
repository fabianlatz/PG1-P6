//
// Created by Fabian on 04.01.24.
//

#ifndef P6_REISEBUERO_H
#define P6_REISEBUERO_H

#include <vector>
#include "Buchung.h"

class Reisebuero {
public:
	void benutzerDialog();

private:
	static std::string readInput(const std::string&);

	void addBuchung();

	void addHotelBuchung();

	void addFlugBuchung();

	void printBuchungsdetails() const;

	static std::string readBuchungsnummer();

	void printAllBuchungen() const;

	std::vector<Buchung *> buchungen;
};


#endif //P6_REISEBUERO_H
