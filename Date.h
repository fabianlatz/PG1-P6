//
// Created by Fabian on 05.01.24.
//

#ifndef P6_DATE_H
#define P6_DATE_H

#include <string>

class Date {
public:
	Date();

	explicit Date(const std::string& content);

	const std::string& getContent() const;

private:
	std::string content;
};


#endif //P6_DATE_H
