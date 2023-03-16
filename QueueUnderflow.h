#pragma once
#ifndef QUEUE_UNDERFLOW_H
#define QUEUE_UNDERFLOW_H
#include <exception>

class QueueUnderflow : public std::exception {
public:
	QueueUnderflow():
		reason_("Queue Underflow")
	{}
	const char* what() const {
		return reason_;
	}
private:
	const char* reason_;
};
#endif
