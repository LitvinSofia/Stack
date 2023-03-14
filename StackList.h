#pragma once
#ifndef STACKLIST_H
#define STACKLIST_H
#include "Stack.h"
#include <iostream>

template <class KeyT>
class StackList : public Stack<T>::template StackList<KeyT> {
public:
	StackList(size_t size):
		top_(nullptr),
		size_(size),
		realSize_(0)
	{}
	virtual ~StackList() override {
		while (top_) {
			Node* temp = top_;
			top_ = top_->next;
			delete temp;
		} 
	}
	StackList<KeyT>& operator=(StackList<KeyT>&& other) noexcept {
		if (this != other) {
			while (top_) {
				Node* temp = top_;
				top_ = top_->next;
				delete temp;
			}
			top_ = other.top_;
			size_ = other.size_;
			realSize_ = other.realSize_;
			other.top_ = nullptr;
			other.size_ = 0;
			other.realSize_ = 0;
		}
		return *this;
	}
	StackList<KeyT>(StackList<KeyT>&& other) noexcept :
		top_(other.top_),
		size_(other.size_),
		realSize_(other.realSize_)
	{
		other.top_ = nullptr;
		other.size_ = 0;
		other.realSize_ = 0;
	}
	StackList<T>(const StackListT>& other) = delete;
	StackList& operator=(const StackList<T>& other) = delete;
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, const StackList<T>& list);
	KeyT pop() override;
	void push(const KeyT& e) override;
	bool isEmpty() override;
private:
	struct Node {
		KeyT key;
		Node* next;
		T key;
		Node(const KeyT& k, Node* n = nullptr):
			key(k),
			next(n)
		{}
		Node():
			key(),
			next(nullptr)
		{}
	};
	Node* top_;
	size_t size_;
	size_t realSize_;
};

template<class T>
std::ostream& operator<<(std::ostream& out, const StackList<T>& list) {
	typename StackList<T>::Node* temp = list.top_;
	while (temp) {
		out << temp->key << " ";
		temp = temp->next;
	}
	out << '\n';
	return out;
}

template <class KeyT>
KeyT StackList<KeyT>::pop() {
	if (realSize_ > 0) {
		Node* temp = top_;
		top_ = top_->next;
		KeyT value = temp->key;
		delete temp;
		return value;
	}
	//else StacklUnderflow
}

template <class KeyT>
void StackList<KeyT>::push(const KeyT& e) {
	if (realSize_ < size_) {
		Node* newNode = new Node(e, top_);
		top_ = newNode;
		realSize++;
	}
	//else StackOverflow;
}

template<class KeyT>
bool StackList<KeyT>::isEmpty() {
	if (top_ == nullptr) {
		return true;
	}
	return false;
}
#endif