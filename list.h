#ifndef List_H
#define List_H

#include <string>
#include <sstream>
#include "exception.h"

typedef unsigned int uint;

template <class T> class List;

/* Definition of the Node class */
template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*);

	T	    value;
	Node<T> *next;

	friend class List<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), next(0) {
}

template <class T>
Node<T>::Node(T val, Node* nxt) : value(val), next(nxt) {
}

/* Definition of the List class */
template <class T>
class List {
private:
	Node<T> *head;
	uint 	size;

public:
	List();
	~List();

	uint  length() const;
	bool empty() const;
	bool contains(T) const;
	void clear();
	std::string toString() const;

	T    front() const;
	T    last() const;
	T    get(uint) const;

	void push_front(T);
	void push_back(T);
	void insert_at(T, uint);

	T    pop_front();
	T 	 pop_back();
	T    remove_at(uint);

	long int  indexOf(T) const;
};

template <class T>
List<T>::List() :head(NULL), size(0) {
}

template <class T>
List<T>::~List() {
    clear();
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
uint List<T>::length() const {
	return size;
}

template <class T>
bool List<T>::contains(T val) const {
	Node<T> *p;

	p = head;
	while (p != NULL) {
		if(p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

template <class T>
void List<T>::clear() {
	Node<T> *p, *q;

	p = head;
	while (p != NULL){
		q = p->next;
		delete p;
		p = q;
	}

	head = NULL;
	size = 0;
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;

	p = head;
	aux << "[";
	while (p != NULL) {
		aux << p->value;
		if (p->next != NULL) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
T List<T>::front() const {
	if (empty()) {
		throw NoSuchElement();
	}

	return head->value;
}

template <class T>
T List<T>::last() const {
	Node<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	return p->value;
}

template <class T>
T List<T>::get(uint index) const {
	T aux;

	// TO DO
	return aux;
}

template <class T>
void List<T>::push_front(T val) {
	Node<T> *q;

	q = new Node<T>(val);
	q->next = head;
	head = q;
	size++;
}

template <class T>
void List<T>::push_back(T val) {
	Node<T> *p, *q;

	if (empty()) {
		push_front(val);
		return;
	}

	p = head;
	while (p->next != NULL) {
		p = p->next;
	}

	q = new Node<T>(val);
	q->next = p->next;
	p->next = q;
	size++;
}

template <class T>
void List<T>::insert_at(T val, uint index) {
}

template <class T>
T List<T>::pop_front() {
	T val;
	Node<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;

	head = p->next;
	val = p->value;

	delete p;
	size--;
	return val;
}

template <class T>
T List<T>::pop_back() {
	Node<T> *p, *q;
	T val;

	if (empty()) {
		throw NoSuchElement();
	}

	if (size == 1) {
		return pop_front();
	}

	q = 0;
	p = head;
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}

	q->next = p->next;
	val = p->value;

	delete p;
	size--;

	return val;
}

template <class T>
T List<T>::remove_at(uint index) {
	T aux;
	// TO DO
	return aux;
}

template <class T>
long int List<T>::indexOf(T val) const {
	// TO DO
	return -1;
}

#endif /* NodeEDList_H_ */
