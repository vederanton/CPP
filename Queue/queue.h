#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <iostream>

const int CAPACITY_INC = 2;
const int CAPACITY_DEC = 4;
const int CAPACITY_DEF = 32;

template <class T>
class Queue {
	size_t capacity = CAPACITY_DEF;
	int tail = -1;	// index of the last element
	T* data = nullptr;
public:
	Queue();
	Queue(const Queue<T>&);
	Queue(Queue<T>&&);
	Queue& operator=(const Queue<T>&);
	Queue& operator=(Queue<T>&&);
	~Queue();
	
	size_t getCapacity() const;
	int size() const;
	bool empty() const;
	void clear();
	
	void print() const;
	void push(const T&);
	void pop();
	T& back();
	T& front();
};


template <class T>
Queue<T>::Queue() :
	data(new T[capacity])
{}

template <class T>
Queue<T>::Queue(const Queue<T>& myQueue) :
	capacity(myQueue.capacity),
	tail(myQueue.tail),
	data(new T[capacity])
{
	for (size_t i = 0; i <= tail; ++i) {
		data[i] = myQueue.data[i];
	}
}

template <class T>
Queue<T>::Queue(Queue<T>&& myQueue) :
	capacity(myQueue.capacity),
	tail(myQueue.tail),
	data(myQueue.data)
{
	myQueue.capacity = 0;
	myQueue.tail = 0;
	myQueue.data = nullptr;
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& myQueue) {
	if (this == &myQueue) {
		return *this;
	}
	tail = myQueue.tail;
	capacity = myQueue.capacity;
	delete[] data;
	data = new T[capacity];
	for (size_t i = 0; i <= tail; ++i) {
		data[i] = myQueue.data[i];
	}
	return *this;
}

template <class T>
Queue<T>& Queue<T>::operator=(Queue<T>&& myQueue) {
	if (this == &myQueue) {
		return *this;
	}
	tail = myQueue.tail;
	capacity = myQueue.capacity;
	data = myQueue.data;
	myQueue.tail = -1;
	myQueue.capacity = CAPACITY_DEF;
	myQueue.data = nullptr;
	return *this;
}

template <class T>
Queue<T>::~Queue() {
	delete[] data;
	data = nullptr;
}

template <class T>
size_t Queue<T>::getCapacity() const {
	return capacity;
}

template <class T>
int Queue<T>::size() const {
	return tail + 1;
}

template <class T>
bool Queue<T>::empty() const {
	return tail == -1 ? 1 : 0;
}

template <class T>
void Queue<T>::clear() {
	capacity = CAPACITY_DEF;
	tail = -1;
	delete[] data;
	data = new T[capacity];
}

template <class T>
void Queue<T>::print() const {
	for (size_t i = 0; i <= tail; ++i) {
		std::cout << data[i] << std::endl;
	}
}

template <class T>
void Queue<T>::push(const T& myQueue) {
	if (capacity == tail + 1) {
		capacity *= CAPACITY_INC;
		T* dataTmp = new T[capacity];
		for (size_t i = 0; i <= tail; ++i) {
			dataTmp[i] = data[i];
		}
		delete[] data;
		data = dataTmp;
		dataTmp = nullptr;
	}
	data[++tail] = myQueue;
}

template <class T>
void Queue<T>::pop() {
	if ((tail - 1) < (capacity / CAPACITY_DEC)) {
		while (capacity > tail && capacity > CAPACITY_DEF) {
			capacity /= CAPACITY_INC;
		}
	}
	T* dataTmp = new T[capacity];
	for (size_t i = 0; i < tail; ++i) {
		dataTmp[i] = data[i + 1];
	}
	delete[] data;
	data = dataTmp;
	dataTmp = nullptr;
	--tail;
}

template <class T>
T& Queue<T>::back() {
	return data[tail];
}

template <class T>
T& Queue<T>::front() {
	return data[0];
}

#endif /* __QUEUE_H__ */
