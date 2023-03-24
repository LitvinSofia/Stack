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
	StackArray(int size = 100);
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
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, StackArray<T>& stack);
	const T& getTopElement() const {
		return array_[top_];
	}
	const int& getTop() const {
		return top_;
	}
private:
	T* array_;
	int top_;
	int size_;
	void swap(StackArray<T>& other);
};

template <class T>
void StackArray<T>::swap(StackArray<T>& other) {
	std::swap(array_, other.array_);
	std::swap(top_, other.top_);
	std::swap(size_, other.size_);
}

template <class T>
StackArray<T>::StackArray(int size):
	size_(size),
	top_(0)
{
	if(size > 0){
		array_ = new T[size_ + 1];
	}
	else {
		throw WrongStackSize();
	}
}
template <class T>
StackArray<T>::StackArray(StackArray<T>&& other) noexcept {
	if (this != &other) {
		swap(other);
	}
	return *this;
}

template <class T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& other) noexcept {
	if (this != &other) {
		swap(other);
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
	return top_ == 0;
}

template <class T>
std::ostream& operator<<(std::ostream& out, StackArray<T>& stack) {
	for (int i = 1; i <= stack.top_; i++) {
		out << stack.array_[i]<<" ";
	}
	return out;
}

#endif