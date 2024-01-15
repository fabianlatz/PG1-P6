//
// Created by Fabian on 05.01.24.
//

#include "Date.h"

Date::Date(const std::string& content) : content(content) {}

Date::Date() {}

const std::string& Date::getContent() const {
	return content;
}
