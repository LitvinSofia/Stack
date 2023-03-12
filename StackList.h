#pragma once
#ifndef STACKLIST_H
#define STACKLIST_H
#include "Stack.h"

template <class T>
class StackList : public Stack::template StackList<T> {
public:
	StackList():
		head_(nullptr)
	{}
	virtual ~StackList() override {
		while (head_) {
			delete head_;
		}
	}
private:
	struct Node {
		Node* next;
		T key;
	};
	Node* head_;
};
#endif