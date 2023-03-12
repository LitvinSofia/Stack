#pragma once
#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#include "Stack.h" 

template <class T>
class StackArray : public Stack::template StackArray<T> {
public:
	StackArray(const size_t & size = 100):
		array_(new T[size]),
		size_(size),
		top(0)
	{};
	virtual ~StackArray() override {
		delete[] array_;
	}
	StackArray(StackArray<T>&& other);
	StackArray& operator=(StackArray<T>&& other);
	StackArray<T>(const StackArray<T>& other) = delete;
	StackArray& operator=(const StackArray<T>& other) = delete;
	void push(const T& e) override;
	T pop() override;
	bool isEmpty() const override;
private:
	T* array_;
	size_t top_;
	size_t size_;
};


template <class T>
StackArray<T>::StackArray(StackArray<T>&& other) {
	if (this != &other) {
		delete[] array_;
		array_ = other.array_;
		top_ = other.top_;
		size_ = other.size_;
	}
	return *this;
}

template <class T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& other) {
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
	;
}

template <class T>
T StackArray<T>::pop() {
	;
}

template<class T>
bool StackArray<T>::isEmpty() const {
	;
}

#endif