#pragma once
#include <iostream>
#include <exception>

template <typename T>
struct node {
	T data;
	node* next;
	node(T myData, node* myNext = nullptr) :
		data(myData),
		next(myNext)
	{}
};

template <typename T>
class ForwardList {
	node<T>* head = nullptr;
	node<T>* tail = nullptr;
	size_t list_size = 0;
	
public:
	ForwardList() = default;
	~ForwardList();
	
	size_t size() const;
	bool empty() const;
	
	void push_back(const T&);
	void push_front(const T&);
	bool insert(const T&, const T&);
	
	T pop_back();
	T pop_front();
	T erase(const T&);
	
	void print() const;

private:
	T deleteFirstNode();
	T deleteNode(node<T>*);
	bool create_node(node<T>*, const T&);
	void create_single_node(const T&);
};

template <class T>
ForwardList<T>::~ForwardList() {
	if (head != nullptr) {
		while (head->next != nullptr) {
			node<T>* tmp = head;
			head = head->next;
			delete tmp;
		}
		delete head;
	}
}

template <class T>
size_t ForwardList<T>::size() const {
	return list_size;
}

template <class T>
bool ForwardList<T>::empty() const {
	return head == nullptr;
}

template <class T>
void ForwardList<T>::push_back(const T& elem) {
	if (head == nullptr) {
		create_single_node(elem);
	}
	else {
		tail->next = new node<T>(elem);
		tail = tail->next;
		++list_size;
	}
}

template <class T>
void ForwardList<T>::push_front(const T& elem) {
	if (head == nullptr) {
		create_single_node(elem);
	}
	else {
		node<T>* tmp = head;
		head = new node<T>(elem);
		head->next = tmp;
		++list_size;
	}
}

template <class T>
bool ForwardList<T>::insert(const T& value, const T& pos) {
	if (head == nullptr) {
		return false;
	}
	node<T>* currentTmp = head;
	while (currentTmp->data != pos && currentTmp->next != nullptr) {
		currentTmp = currentTmp->next;
	}
	if (currentTmp->data != pos && currentTmp->next == nullptr) {
		return false;
	}
	return create_node(currentTmp, value);
}

template <class T>
T ForwardList<T>::pop_back() {
	try {
		if (list_size == 0) {
			throw std::length_error("pop_back error: the size of list = 0");
		}
		else if (list_size == 1) {
			return deleteFirstNode();
		}
	node<T>* currentTmp = head;
	while (currentTmp->next->next != nullptr) {
		currentTmp = currentTmp->next;
	}
	return deleteNode(currentTmp);
	}
	catch (std::length_error& err) {
		std::cout << err.what() << std::endl;
	}
}

template <class T>
T ForwardList<T>::pop_front() {
	try {
		if (list_size == 0) {
			throw std::length_error("pop_front error: the size of list = 0");
		}
		return deleteFirstNode();
	}
	catch (std::length_error& err) {
		std::cout << err.what() << std::endl;
	}
}

template <class T>
T ForwardList<T>::erase(const T& elem) {
	try {
		if ((list_size == 1 && head->data != elem) || head == nullptr) {
			throw std::length_error("erase error: There is one element in the list and it is not equal to the value. Or the list is completely empty.");
		}
		if (head->data == elem) {
			return deleteFirstNode();
		}
		node<T>* currentTmp = head;
		while (currentTmp->next->data != elem && currentTmp->next->next != nullptr) {
			currentTmp = currentTmp->next;
		}
		if (currentTmp->next->data != elem && currentTmp->next->next == nullptr) {
			throw std::length_error("erase error: No matches found in the list.");
		}
		return deleteNode(currentTmp);
	}
	catch (std::length_error& err) {
		std::cout << err.what() << std::endl;
	}
}

template <class T>
void ForwardList<T>::print() const {
	if (head == nullptr) {
		std::cout << "The List is empty!" << std::endl;
	}
	else {
		node<T>* currentTmp = head;
		while (currentTmp->next != nullptr) {
			std::cout << currentTmp->data << " ";
			currentTmp = currentTmp->next;
		}
		std::cout << currentTmp->data << std::endl;
	}
}

template <class T>
T ForwardList<T>::deleteFirstNode() { 
	if (list_size == 1) {
		T returnTmp = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		--list_size;
		return returnTmp;
	}
	node<T>* tmp = head;
	head = head->next;
	T returnTmp = tmp->data;
	delete tmp;
	--list_size;
	return returnTmp;
}

template <class T>
T ForwardList<T>::deleteNode(node<T>* previous) {  
	if(previous->next->next == nullptr){
		tail = previous;
		previous = previous->next;
		tail->next = nullptr;
		T returnTmp = previous->data;
		delete previous;
		previous = nullptr;
		--list_size;
		return returnTmp;
	}
	node<T>* tmp = previous->next;
	previous->next = tmp->next;
	tmp->next = nullptr;
	T returnTmp = tmp->data;
	delete tmp;
	--list_size;
	return returnTmp;
}

template <class T>
bool ForwardList<T>::create_node(node<T>* previous, const T& value) {
	node<T>* newNode = new node<T>(value);
	newNode->next = previous->next;
	previous->next = newNode;
	if (previous == tail) {
		tail = newNode;
	}
	++list_size;
	return true;
}

template <class T>
void ForwardList<T>::create_single_node(const T& elem) {
	head = new node<T>(elem);
	tail = head;
	++list_size;
}
