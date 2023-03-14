#pragma once
#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <string>

template <class KeyT>
class DictionaryList {
public:
	DictionaryList();
	~DictionaryList();
	bool insert(const KeyT&& key);
	//bool insert(const KeyT& key);
	bool del(const KeyT& key);
	bool search(const KeyT& key) const;
	void print(std::ostream& out) const;
	bool merge(DictionaryList<KeyT>& other);
	bool deleteFromDictionary(const DictionaryList<KeyT>& other);
	DictionaryList<KeyT>(DictionaryList<KeyT>&& other) noexcept :
		head_(other.head_)
	{
		other.head_ = nullptr;
	}
	DictionaryList<KeyT>& operator=(DictionaryList<KeyT>&& other) noexcept {
		if (this != &other) {
			while (head_) {
				Node* temp = head_;
				head_ = head_->next;
				delete temp;
			}
			head_ = other.head_;
			other.head_ = nullptr;
		}
		return *this;
	}
	template<class T>
	friend std::ostream& operator<<(std::ostream& out, const DictionaryList<T>& list);
	template<class KeyT>
	friend DictionaryList<KeyT> getIntersection(const DictionaryList<KeyT>& list1, const DictionaryList<KeyT>& list2);
private:
	struct Node {
		KeyT key;
		Node* next;
		Node(const KeyT& k, Node* n = nullptr) :
			key(k),
			next(n)
		{}
		Node() :
			key(),
			next(nullptr)
		{}
	};
	Node* head_;
};

template <class KeyT>
DictionaryList<KeyT>::DictionaryList() :
	head_(nullptr)
{}

template <class KeyT>
DictionaryList<KeyT>::~DictionaryList() {
	while (head_) {
		Node* temp = head_;
		head_ = head_->next;
		delete temp;
	}
}


template <class KeyT>
bool DictionaryList<KeyT>::insert(const KeyT&& key) {
	if (head_ == nullptr || ((key < head_->key) && (head_ != nullptr))) {
		Node* newNode = new Node(key, head_);
		head_ = newNode;
		return true;
	}
	else {
		Node* temp = head_;
		while (temp->next) {
			if ((key > temp->key) && (key < temp->next->key)) {
				Node* newNode = new Node(key, temp->next);
				temp->next = newNode;
				return true;
			}
			if (key == temp->key) {
				return false;
			}
			temp = temp->next;
		}
		if ((temp->next == nullptr) && (key > temp->key)) {
			Node* newNode = new Node(key, temp->next);
			temp->next = newNode;
			return true;
		}
		return false;
	}
}

template <class KeyT>
bool DictionaryList<KeyT>::insert(const KeyT& key) {
	if (head_ == nullptr || ((key < head_->key) && (head_ != nullptr))) {
		Node* newNode = new Node(key, head_);
		head_ = newNode;
		return true;
	}
	else {
		Node* temp = head_;
		while (temp->next) {
			if ((key > temp->key) && (key < temp->next->key)) {
				Node* newNode = new Node(key, temp->next);
				temp->next = newNode;
				return true;
			}
			if (key == temp->key) {
				return false;
			}
			temp = temp->next;
		}
		if ((temp->next == nullptr) && (key > temp->key)) {
			Node* newNode = new Node(key, temp->next);
			temp->next = newNode;
			return true;
		}
		return false;
	}
}

template <class KeyT>
bool DictionaryList<KeyT>::del(const KeyT& key) {
	Node* temp = head_;
	Node* temp2 = nullptr;
	if ((temp == nullptr) || (key < temp->key)) {
		return false;
	}
	if (key == temp->key) {
		head_ = head_->next;
		delete temp;
		return true;
	}
	while (temp->next->next) {
		if ((key > temp->key) && (key < temp->next->key)) {
			return false;
		}
		if (key == temp->next->key) {
			temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
			return true;
		}
		temp = temp->next;
	}
	if (key == temp->next->key) {
		temp2 = temp->next;
		temp->next = nullptr;
		delete temp2;
		return true;
	}
	return false;
}

template<class KeyT>
bool DictionaryList<KeyT>::search(const KeyT& key) const {
	Node* temp = head_;
	if ((temp == nullptr) || (key < temp->key)) {
		return false;
	}
	if (key == temp->key) {
		return true;
	}
	while (temp->next) {
		if ((key > temp->key) && (key < temp->next->key)) {
			return false;
		}
		temp = temp->next;
		if (key == temp->key) {
			return true;
		}

	}
	if (key == temp->key) {
		return true;
	}
	return false;
}

template<class KeyT>
bool DictionaryList<KeyT>::merge(DictionaryList<KeyT>& other) {
	Node* temp1 = this->head_;
	Node* temp2 = other.head_;
	if (temp1 == nullptr) {
		if (temp2 != nullptr) {
			this->head_ = temp2;
			other.head_ = nullptr;
		}
		return true;
	}
	if ((temp1 != nullptr) && (temp2 == nullptr)) {
		return true;
	}
	if (temp2->key < temp1->key) {
		Node* temp3 = temp2->next;
		temp2->next = temp1;
		this->head_ = temp2;
		other.head_ = temp3;
		temp1 = this->head_;
		temp2 = other.head_;
	}
	while (temp1 && temp1->next && other.head_) {
		if (temp1->key == other.head_->key) {
			Node* temp3 = other.head_;
			other.head_ = temp2->next;
			temp2 = other.head_;
			delete temp3;
			continue;
		}
		if ((other.head_->key > temp1->key) && (other.head_->key < temp1->next->key)) {
			Node* temp3 = other.head_->next;
			other.head_->next = temp1->next;
			temp1->next = other.head_;
			other.head_ = temp3;
			temp1 = temp1->next;
			temp2 = other.head_;
			continue;
		}
		temp1 = temp1->next;
	}
	if (other.head_ && temp1) {
		if (temp1->key == other.head_->key) {
			Node* temp3 = other.head_;
			other.head_ = other.head_->next;
			delete temp3;
		}
	}
	if (temp1 && other.head_ && other.head_->key > temp1->key) {
		temp1->next = other.head_;
		other.head_ = nullptr;
	}
	return true;
}

template <class KeyT>
void DictionaryList<KeyT>::print(std::ostream& out) const {
	Node* temp = head_;
	while (temp) {
		out << temp->key << " ";
		temp = temp->next;
	}
	out << '\n';
}

template<class KeyT>
bool DictionaryList<KeyT>::deleteFromDictionary(const DictionaryList<KeyT>& other) {

}

template<class KeyT>
DictionaryList<KeyT> getIntersection(const DictionaryList<KeyT>& list1, const DictionaryList<KeyT>& list2) {
	DictionaryList<KeyT> newDict;
	typename DictionaryList<KeyT>::Node* temp1 = list1.head_;
	typename DictionaryList<KeyT>::Node* temp2 = list2.head_;
	typename DictionaryList<KeyT>::Node* temp = newDict.head_;
	if (temp1 == nullptr || temp2 == nullptr) {
		return newDict;
	}
	while (temp1 && temp2) {
		if (temp1->key > temp2->key) {
			temp2 = temp2->next;
		}
		if (temp1->key < temp2->key) {
			temp1 = temp1->next;
		}
		if (temp1->key == temp2->key) {
			if (newDict.head_ == nullptr) {
				typename DictionaryList<KeyT>::Node* newNode = new typename DictionaryList<KeyT>::Node(temp1->key, nullptr);
				newDict.head_ = newNode;
				temp = newDict.head_;
				temp1 = temp1->next;
				temp2 = temp2->next;
				continue;
			}
			typename DictionaryList<KeyT>::Node* newNode = new typename DictionaryList<KeyT>::Node(temp1->key, temp->next);
			temp->next = newNode;
			temp = temp->next;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	return newDict;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const DictionaryList<T>& list)
{
	// слово typename необходимо, чтобы компилятор понимал, что Node - это тип
	typename DictionaryList<T>::Node* temp = list.head_;
	while (temp)
	{
		out << temp->key << "  ";
		temp = temp->next;
	}
	out << '\n';
	return out;
}
#endif

