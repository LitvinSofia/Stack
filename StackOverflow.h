#pragma once
#ifndef STACKOVERFLOW_H
#define STACKOVERFLOW_H
#include <exception>
#include <string>
class StackOverflow : public std::exception {
public:
	StackOverflow(): 
		reason_("Stack Overflow")
	{}
	const std::string& what() {
		return reason_; 
	}
private:
	const std::string reason_;
};
#endif