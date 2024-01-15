//
// Created by Fabian on 04.01.24.
//

#ifndef P6_FLUGBUCHUNG_H
#define P6_FLUGBUCHUNG_H

#include <string>
#include <unordered_map>
#include "Buchung.h"
#include "Date.h"

class FlugBuchung : public Buchung {
public:
	FlugBuchung(const std::string& nachname, const std::string& vorname, const std::string& fluglinie,
	            const std::string& sitzPlatz, const std::string& start, const std::string& ziel, Date *datum);

	FlugBuchung(const FlugBuchung&);

	static const std::unordered_map<std::string, std::string>& getAttributeValues();

	void zeigeDetails() const override;

	~FlugBuchung() override;

private:
	static std::unordered_map<std::string, std::string> attributeValues;
	std::string fluglinie;
	std::string sitzPlatz;
	std::string start;
	std::string ziel;
	Date *datum;
};


#endif //P6_FLUGBUCHUNG_H
