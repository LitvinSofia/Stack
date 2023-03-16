#pragma once
#pragma once
#ifndef WRONG_STACK_SIZE_H
#define WRONG_STACK_SIZE_H
#include <exception>

class WrongStackSize: public std::exception {
public:
	WrongStackSize():
		reason_("Wrong Stack Size")
	{}
	const char* what() const {
		return reason_;
	}
private:
	const char* reason_;
};

#endif

