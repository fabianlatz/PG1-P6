//
// Created by Fabian on 04.01.24.
//

#ifndef P6_BUCHUNG_H
#define P6_BUCHUNG_H

#include <string>
#include <unordered_map>

class Buchung {
public:
	Buchung();

	Buchung(const std::string& nachname, const std::string& vorname);

	Buchung(const Buchung&);

	const std::string& getBuchungsNummer() const;

	virtual void zeigeDetails() const = 0;

	virtual ~Buchung();

protected:

	static int numOfBuchungen;
	std::string buchungsNummer;
	std::string nachname;
	std::string vorname;
};


#endif //P6_BUCHUNG_H
