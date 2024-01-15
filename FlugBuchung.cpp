//
// Created by Fabian on 04.01.24.
//

#include "FlugBuchung.h"
#include "Buchung.h"

#include <iostream>

std::unordered_map<std::string, std::string> FlugBuchung::attributeValues{{"Nachname",  ""},
                                                                          {"Vorname",   ""},
                                                                          {"Fluglinie", ""},
                                                                          {"Sitzplatz", ""},
                                                                          {"Start",     ""},
                                                                          {"Ziel",      ""},
                                                                          {"Datum",     ""}};


FlugBuchung::FlugBuchung(const std::string& nachname, const std::string& vorname, const std::string& fluglinie,
                         const std::string& sitzPlatz, const std::string& start, const std::string& ziel, Date *datum)
		: Buchung(nachname, vorname),
		  fluglinie(fluglinie), sitzPlatz(sitzPlatz), start(start),
		  ziel(ziel), datum(datum) {}

FlugBuchung::FlugBuchung(const FlugBuchung&) {
	datum = new Date();
}

FlugBuchung::~FlugBuchung() {
	delete datum;
}

void FlugBuchung::zeigeDetails() const {
	std::unordered_map<std::string, std::string> attributeValues = FlugBuchung::attributeValues;
	attributeValues["Nachname"] = nachname;
	attributeValues["Vorname"] = vorname;
	attributeValues["Fluglinie"] = fluglinie;
	attributeValues["Sitzplatz"] = sitzPlatz;
	attributeValues["Start"] = start;
	attributeValues["Ziel"] = ziel;
	attributeValues["Datum"] = datum->getContent();
	std::cout << "Details für Flugbuchung Nr. " << buchungsNummer << std::endl;
	for (const auto& attributeValue: attributeValues)
		std::cout << attributeValue.first << ": " << attributeValue.second << std::endl;
}

const std::unordered_map<std::string, std::string>& FlugBuchung::getAttributeValues() {
	return attributeValues;
}
