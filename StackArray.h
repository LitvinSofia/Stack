#pragma once
#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#include "Stack.h" 
#include "WrongStackSize.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"
#include <iostream>

template <class T>
class StackArray : public Stack<T>{
public:
	StackArray(size_t size = 100);
	StackArray() = delete;
	virtual ~StackArray() override {
		delete[] array_;
	}
	StackArray(StackArray<T>&& other) noexcept;
	StackArray& operator=(StackArray<T>&& other) noexcept;
	StackArray<T>(const StackArray<T>& other) = delete;
	StackArray& operator=(const StackArray<T>& other) = delete;
	void push(const T& e) override;
	T pop() override;
	bool isEmpty() const override;
	friend std::ostream& operator<<(std::ostream& out, StackArray<T>& stack);
private:
	T* array_;
	int top_;
	size_t size_;
	void swap(StackArray<T>& other);
};

template <class T>
void StackArray<T>::swap(StackArray<T>& other) {
	std::swap(array_, other.array_);
	std::swap(top_, other.top_);
	std::swap(size_, other.size_);
}

template <class T>
StackArray<T>::StackArray(size_t size):
	size_(size),
	top_(0)
{
	try {
		array_ = new T[size + 1];
	}
	catch (std::bad_alloc&) {
		throw WrongStackSize();
	}
}
template <class T>
StackArray<T>::StackArray(StackArray<T>&& other) noexcept {
	if (this != &other) {
		delete[] array_;
		array_ = other.array_;
		top_ = other.top_;
		size_ = other.size_;
	}
	return *this;
}

template <class T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& other) noexcept {
	if (this != &other) {
		delete[] array_;
		array_ = other.array_;
		top_ = other.top_;
		size_ = other.size_;
	}
	return *this;
}

template <class T>
void StackArray<T>::push(const T& e){
	if (top_ == size_) {
		throw StackOverflow();
	}
	array_[++top_] = e;
}

template <class T>
T StackArray<T>::pop() {
	if (isEmpty()) {//if stack includes 1 element we will pop it and top equals to -1
		throw StackUnderflow();
	}
	return array_[top_--];
}

template<class T>
bool StackArray<T>::isEmpty() const {
	if (top_ == 0) {
		return true;
	}
	return false;
}

template <class T>
std::ostream& operator<<(std::ostream& out, StackArray<T>& stack) {
	for (int i = 0; i < stack.size_; i++) {
		out << stack.array_[i]<<" ";
	}
	return out;
}

#endif