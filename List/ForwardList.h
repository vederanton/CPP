#pragma once
#include <iostream>

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
	ForwardList() {};
	~ForwardList() {};
	
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
};

template <class T>
size_t ForwardList<T>::size() const {
	return list_size;
}

template <class T>
bool ForwardList<T>::empty() const {
	return head == nullptr ? 1 : 0;
}

template <class T>
void ForwardList<T>::push_back(const T& elem) {
	if (head == nullptr) {
		head = new node<T>(elem);
		tail = head;
	}
	else {
		tail->next = new node<T>(elem);
		tail = tail->next;
	}
	++list_size;
}

template <class T>
void ForwardList<T>::push_front(const T& elem) {
	if (head == nullptr) {
		head = new node<T>(elem);
		tail = head;
	}
	else {
		node<T>* tmp = head;
		head = new node<T>(elem);
		head->next = tmp;
	}
	++list_size;
}

template <class T>
bool ForwardList<T>::insert(const T& value, const T& pos) {
	if (head == nullptr) {
		return 0;
	}
	node<T>* currentTmp = head;
	while (currentTmp->data != pos && currentTmp->next != nullptr) {
		currentTmp = currentTmp->next;
	}
	if (currentTmp->data != pos && currentTmp->next == nullptr) {
		return 0;
	}
	return create_node(currentTmp, value);
}

template <class T>
T ForwardList<T>::pop_back() {
	if (list_size == 0) {
		return 0;
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

template <class T>
T ForwardList<T>::pop_front() {
	if (list_size == 0) {
		return 0;
	}
	return deleteFirstNode();
}

template <class T>
T ForwardList<T>::erase(const T& elem) {
	if ((list_size == 1 && head->data != elem) || head == nullptr) {
		return 0;
	}
	if (head->data == elem) {
		return deleteFirstNode();
	}
	node<T>* currentTmp = head;
	while (currentTmp->next->data != elem && currentTmp->next->next != nullptr) {
		currentTmp = currentTmp->next;
	}
	if (currentTmp->next->data != elem && currentTmp->next->next == nullptr) {
		return 0;
	}
	return deleteNode(currentTmp);
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
		T rtrn = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		--list_size;
		return rtrn;
	}
	node<T>* tmp = head;
	head = head->next;
	T rtrn = tmp->data;
	delete tmp;
	--list_size;
	return rtrn;
}

template <class T>
T ForwardList<T>::deleteNode(node<T>* previous) {  
	if(previous->next->next == nullptr){
		tail = previous;
		previous = previous->next;
		tail->next = nullptr;
		T rtrn = previous->data;
		delete previous;
		previous = nullptr;
		--list_size;
		return rtrn;
	}
	node<T>* tmp = previous->next;
	previous->next = tmp->next;
	tmp->next = nullptr;
	T rtrn = tmp->data;
	delete tmp;
	--list_size;
	return rtrn;
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
	return 1;
}
