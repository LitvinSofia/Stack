#pragma once
#ifndef WRONG_QUEUE_SIZE_H
#define WRONG_QUEUE_SIZE_H
#include <exception>

class WrongQueueSize : public std::exception {
public:
	WrongQueueSize():
		reason_("Wrong Queue Size")
	{}
	const char* what() const {
		return reason_;
	}
private:
	const char* reason_;
};
#endif
