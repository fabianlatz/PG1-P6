//
// Created by Fabian on 04.01.24.
//

#include "Reisebuero.h"
#include "HotelBuchung.h"
#include "FlugBuchung.h"
#include <iostream>

std::string Reisebuero::readInput(const std::string& description) {
	std::string input;
	std::cout << "Bitte geben Sie folgende Information ein: " << description << std::endl;
	std::cout << "> ";
	std::getline(std::cin, input);
	return input;
}

void Reisebuero::addHotelBuchung() {
	std::unordered_map<std::string, std::string> attributeValues = HotelBuchung::getAttributeValues();
	for (const auto& attributeValue: attributeValues) {
		attributeValues.insert_or_assign(attributeValue.first, readInput(attributeValue.first));
	}
	buchungen.push_back(new HotelBuchung(attributeValues["Nachname"], attributeValues["Vorname"],
	                                     attributeValues["Hotelname"], new Date(attributeValues["Anreise"]), new Date
			                                     (attributeValues["Abreise"]),
	                                     attributeValues["Zimmertyp"].at(0)));
}

void Reisebuero::addFlugBuchung() {
	std::unordered_map<std::string, std::string> attributeValues = FlugBuchung::getAttributeValues();
	for (const auto& attributeValue: attributeValues) {
		attributeValues.insert_or_assign(attributeValue.first, readInput(attributeValue.first));
	}
	buchungen.push_back(new FlugBuchung(attributeValues["Nachname"], attributeValues["Vorname"],
	                                    attributeValues["Fluglinie"], attributeValues["Sitzplatz"],
	                                    attributeValues["Start"],
	                                    attributeValues["Ziel"], new Date(attributeValues["Datum"])));
}

void Reisebuero::benutzerDialog() {
	int selection = 0;
	while (true) {
		std::cout << std::endl;
		std::cout << "1: Buchung anlegen" << std::endl;
		std::cout << "2: Buchungsdetails ausgeben" << std::endl;
		std::cout << "3: Alle Buchungen anzeigen" << std::endl;
		std::cout << "0: Programm beenden" << std::endl;
		std::cout << "> ";
		std::cin >> selection;
		switch (selection) {
			case 1:
				addBuchung();
				break;
			case 2:
				printBuchungsdetails();
				break;
			case 3:
				printAllBuchungen();
				break;
			case 0:
				exit(0);
			default:
				std::cerr << "Ungueltige Eingabe!" << std::endl;
		}
	}
}

void Reisebuero::addBuchung() {
	char typeOfBuchung = ' ';
	do {
		std::cout << "Welcher Typ von Buchung soll angelegt werden?" << std::endl;
		std::cout << "H – Hotelbuchung" << std::endl;
		std::cout << "F – Flugbuchung" << std::endl;
		std::cout << "> ";
		std::cin >> typeOfBuchung;
		switch (typeOfBuchung) {
			case 'H':
				addHotelBuchung();
				break;
			case 'F':
				addFlugBuchung();
				break;
			default:
				std::cerr << "Ungueltige Eingabe!" << std::endl;
		}
	} while (typeOfBuchung == ' ');
}

void Reisebuero::printBuchungsdetails() const {
	std::string searchedBuchungsnummer;
	bool found = false;
	while (!found) {
		searchedBuchungsnummer = readBuchungsnummer();
		if (searchedBuchungsnummer == "-1") break;
		auto foundBuchung = std::find_if(buchungen.begin(), buchungen.end(), [&searchedBuchungsnummer](const auto&
		buchung) {
			return buchung->getBuchungsNummer() == searchedBuchungsnummer;
		});
		if (foundBuchung != buchungen.end()) {
			found = true;
			buchungen.at(std::distance(buchungen.begin(), foundBuchung))->zeigeDetails();
		} else {
			std::cerr << "Keine Buchung mit dieser Buchungsnummer vorhanden!" << std::endl;
		}
	}
}

std::string Reisebuero::readBuchungsnummer() {
	std::string buchungsNummer;
	std::cout << "Bitte geben Sie eine Buchungsnummer ein" << std::endl;
	std::cout << "> ";
	std::cin >> buchungsNummer;
	return buchungsNummer;
}

void Reisebuero::printAllBuchungen() const {
	for (Buchung *b: buchungen)
		b->zeigeDetails();
}
