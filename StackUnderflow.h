#pragma once
#ifndef STACKUNDERFLOW_H
#define STACKUNDERFLOW_H
#include <exception>
#include <string>

class StackUnderflow: public std::exception	{
public:
	StackUnderflow() : 
		reason_("Stack Underflow\n")
	{}
	const char* what() const {
		return reason_;
	}
private:
	const char* reason_;
};
#endif