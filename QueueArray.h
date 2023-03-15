#pragma once
#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include <iostream>
#include "Queue.h"
#include "WrongQueueSize.h"
#include "QueueOverflow.h"
#include "QueueUnderflow.h"

template <class T>
class QueueArray : public Queue<T> {
public:
	QueueArray(const int& length = 100):
		length_(length),
		head_(0),
		tail_(0)
	{
		if (length > 0) {
			queue_ = new T[length];
		}
		else {
			throw WrongQueueSize();
		}
	}
	virtual ~QueueArray() {
		delete[] queue_;
	}
	void enQueue(const T& e);
	T deQueue();
	bool isEmpty();
	QueueArray(QueueArray<T>&& other) noexcept;
	QueueArray& operator=(QueueArray<T>&& other) noexcept;
	QueueArray<T>(const QueueArray<T>& other) = delete;
	QueueArray& operator=(const QueueArray<T>& other) = delete;
	void swap(QueueArray<T>& other);
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, QueueArray<T>& queue);
private:
	T* queue_;
	int length_;
	int head_;
	int tail_;
};
template<class T>
void QueueArray<T>::enQueue(const T& e) {
	if (tail_ + 1 == head_) {
		throw QueueOverflow();
	}
	queue_[tail_] = e;
	if (tail_ == length_ - 1) {
		tail_ = 0;
	}
	else {
		++tail_;
	}
}

template<class T>
T QueueArray<T>::deQueue() {
	if (isEmpty()) {
		throw QueueUnderflow();
	}
	T x = queue_[head_];
	if (head_ == (length_ - 1)) {
		head_ = 0;
	}
	else {
		++head_;
	}
	return x;
}


template<class T>
bool QueueArray<T>::isEmpty() {
	return head_ == tail_;
}

template <class T>
void QueueArray<T>::swap(QueueArray<T>& other) {
	std::swap(queue_, other.queue_);
	std::swap(head_, other.head_);
	std::swap(length_, other.length_);
	std::swap(tail_, other.tail_);
}
template<class T>
QueueArray<T>::QueueArray(QueueArray<T>&& other) noexcept {
	if (this != &other) {
		swap(other);
	}
	return *this;
}
template<class T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& other) noexcept {
	if (this != &other) {
		swap(other);
	}
	return *this;
}

template<class T>
std::ostream& operator<<(std::ostream& out, QueueArray<T>& queue) {
	if (queue.head_ < queue.tail_) {
		for (int i = queue.head_; i < queue.tail_; i++) {
			out << queue.queue_[i] << " ";
		}
	}
	else if (queue.head_ > queue.tail_) {
		for (int i = queue.head_; i < queue.length_; i++) {
			out << queue.queue_[i] << " ";
		}
		for (int i = 0; i < queue.tail_; i++) {
			out << queue.queue_[i];
		}
	}
	return out;
}
#endif