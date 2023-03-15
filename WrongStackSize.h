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
		reason_("Wrong Stack Size")
	{}
	const std::string& what() {
		return reason_;
	}
private:
	const std::string& reason_;
};

#endif

