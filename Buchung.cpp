//
// Created by Fabian on 04.01.24.
//

#include "Buchung.h"

int Buchung::numOfBuchungen = 0;

Buchung::Buchung(const std::string& nachname, const std::string& vorname) : nachname(nachname), vorname(vorname) {
	buchungsNummer = std::to_string(++numOfBuchungen);
}

Buchung::~Buchung() {
	--numOfBuchungen;
}

const std::string& Buchung::getBuchungsNummer() const {
	return buchungsNummer;
}

Buchung::Buchung() = default;
