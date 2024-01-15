//
// Created by Fabian on 04.01.24.
//

#include "HotelBuchung.h"
#include <iostream>

std::unordered_map<std::string, std::string> HotelBuchung::attributeValues{{"Nachname",  ""},
                                                                           {"Vorname",   ""},
                                                                           {"Hotelname", ""},
                                                                           {"Anreise",   ""},
                                                                           {"Abreise",   ""},
                                                                           {"Zimmertyp", ""}};

HotelBuchung::HotelBuchung(const std::string& nachname, const std::string& vorname, const std::string& hotelName,
                           Date *anreise, Date *abreise, char zimmerTyp)
		: Buchung(nachname, vorname), hotelName(hotelName), anreise(anreise), abreise(abreise), zimmerTyp(zimmerTyp) {}

HotelBuchung::HotelBuchung(const HotelBuchung&) {
	anreise = new Date();
	abreise = new Date();
}

HotelBuchung::~HotelBuchung() {
	delete anreise;
	delete abreise;
}

void HotelBuchung::zeigeDetails() const {
	std::unordered_map<std::string, std::string> attributeValues = HotelBuchung::attributeValues;
	attributeValues["Nachname"] = nachname;
	attributeValues["Vorname"] = vorname;
	attributeValues["Hotelname"] = hotelName;
	attributeValues["Anreise"] = anreise->getContent();
	attributeValues["Abreise"] = abreise->getContent();
	attributeValues["Zimmertyp"] = zimmerTyp;
	std::cout << "Details für Hotelbuchung Nr. " << buchungsNummer << std::endl;
	for (const auto& attributeValue: attributeValues)
		std::cout << attributeValue.first << ": " << attributeValue.second << std::endl;
}

const std::unordered_map<std::string, std::string>& HotelBuchung::getAttributeValues() {
	return attributeValues;
}


