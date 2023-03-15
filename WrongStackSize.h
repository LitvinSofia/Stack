#pragma once
#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <string>
#include <exception>

class WrongStackSize: public std::exception {
public:
	WrongStackSize():
		reason_("Wrong Stack Size\n")
	{}
	const char* what() const {
		return reason_;
	}
private:
	const char* reason_;
};

#endif

