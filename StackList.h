#pragma once
#ifndef STACKLIST_H
#define STACKLIST_H
#include "Stack.h"
#include <iostream>
template <class T>
class StackList : public Stack<T>::template StackList<T> {
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
	StackList<T>& operator=(StackList<T>&& other) noexcept {
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
	StackList<T>(StackList<T>&& other) noexcept :
		top_(other.top_),
		size_(other.size_),
		realSize_(other.realSize_)
	{
		other.top_ = nullptr;
		other.size_ = 0;
		other.realSize_ = 0;
	}
	StackList<T>(const StackList<T>& other) = delete;
	StackList& operator=(const StackList<T>& other) = delete;
	T pop() override;
	void push(const T& e) override;
	bool isEmpty() override;
	template <class K>
	friend std::ostream& operator<<(std::ostream& out, const StackList<K>& list);
private:
	struct Node {
		T key;
		Node* next;
		Node(const T& k, Node* n = nullptr):
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

template<class K>
std::ostream& operator<<(std::ostream& out, const StackList<K>& list) {
	typename StackList<K>::Node* temp = list.top_;
	while (temp) {
		out << temp->key << " ";
		temp = temp->next;
	}
	out << '\n';
	return out;
}

template <class T>
T StackList<T>::pop() {
	if (realSize_ > 0) {
		Node* temp = top_;
		top_ = top_->next;
		T value = temp->key;
		delete temp;
		return value;
	}
	//else StacklUnderflow
}

template <class T>
void StackList<T>::push(const T& e) {
	if (realSize_ < size_) {
		Node* newNode = new Node(e, top_);
		top_ = newNode;
		realSize_++;
	}
	//else StackOverflow;
}

template<class T>
bool StackList<T>::isEmpty() {
	if (top_ == nullptr) {
		return true;
	}
	return false;
}
#endif