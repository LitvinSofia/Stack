#pragma once
#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#include "Stack.h" 
#include <iostream>
template <class T>
class StackArray : public Stack<T>::template StackArray<T> {
public:
	StackArray(const size_t & size = 100)://creates a new empty stack with a top equals to -1
		array_(new T[size]),
		size_(size),
		top_(-1)
	{};
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
	friend std::ostream& operator<<(std::ostream& out, StackArray& stack);
private:
	T* array_;
	int top_;
	size_t size_;
};

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
	if (array_ != nullptr && top_ == -1 && size_ > 0 ) {//if stack is empty we will push the element in it with index eq to 0 
		//top_ = 0;
		array_[top_ = 0] = e;
	}
	else if (top_ >= 0  && top_ + 1 < size_) {//if stack is not empty and it's not full
		array_[++top_] = e;
	}
	///else: StackOverflow
}

template <class T>
T StackArray<T>::pop() {
	if (top_ == 0) {//if stack includes 1 element we will pop it and top equals to -1
		top_ = -1;
		return array_[0];
	}
	else if (top_ != -1) {
		top_--;
		return array_[top_ + 1];
	}
	///else: StackUnderflow
}

template<class T>
bool StackArray<T>::isEmpty() const {
	if (array_ != nullptr && size_ >=1 && top_ == -1 ) {
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