#pragma once
#ifndef STACKUNDERFLOW_H
#define STACKUNDERFLOW_H
#include <exception>
#include <string>

class StackUnderflow: public std::exception	{
public:
	StackUnderflow() : 
		reason_("Stack Underflow")
	{}
	const std::string& what(){
		return reason_;
	}
private:
	const std::string reason_;
};
#endif