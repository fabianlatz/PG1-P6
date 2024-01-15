//
// Created by Fabian on 04.01.24.
//

#ifndef P6_HOTELBUCHUNG_H
#define P6_HOTELBUCHUNG_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Buchung.h"
#include "Date.h"

class HotelBuchung : public Buchung {
public:
	HotelBuchung(const std::string& nachname, const std::string& vorname, const std::string& hotelName, Date *anreise,
	             Date *abreise, char zimmerTyp);

	HotelBuchung(const HotelBuchung&);

	static const std::unordered_map<std::string, std::string>& getAttributeValues();

	void zeigeDetails() const override;

	~HotelBuchung() override;

private:
	static std::unordered_map<std::string, std::string> attributeValues;
	std::string hotelName;
	Date *anreise;
	Date *abreise;
	char zimmerTyp;
};


#endif //P6_HOTELBUCHUNG_H
