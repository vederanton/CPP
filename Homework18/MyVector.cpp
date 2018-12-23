#include "pch.h"
#include "MyVector.h"
#include "iostream"


const int DEFAULT_CAP_VALUE = 32;
const int DEFAULT_TWO_DEGREE = 2;
int MyVector::allVecCount = 0;
int MyVector::nowVecCount = 0;

MyVector::MyVector() :
	capacity(DEFAULT_CAP_VALUE),
	arr(new int[capacity])
{
	++allVecCount;
	++nowVecCount;
}

MyVector::MyVector(const int array[], const int sz) {
	capacity = DEFAULT_CAP_VALUE;
	while (capacity <= sz) {
		capacity *= DEFAULT_TWO_DEGREE;
	}
	arr = new int[capacity];
	for (int i = 0; i < sz; ++i) {
		arr[i] = array[i];
	}
	size = sz;
	++allVecCount;
	++nowVecCount;
}

MyVector::MyVector(const MyVector& myVec) :
	size(myVec.size),
	capacity(myVec.capacity),
	arr(new int[myVec.capacity])
{
	for (int i = 0; i < size; ++i) {
		arr[i] = myVec.arr[i];
	}
	++allVecCount;
	++nowVecCount;
}

MyVector::MyVector(MyVector&& myVec) :
	arr(myVec.arr),
	size(myVec.size),
	capacity(myVec.capacity)
{
	myVec.arr = nullptr;
	myVec.size = 0;
	myVec.capacity = 0;
}

MyVector::~MyVector() {
	delete[] arr;
	--nowVecCount;
}

int MyVector::getAllVecCount() {
	return allVecCount;
}

int MyVector::getNowVecCount() {
	return nowVecCount;
}

bool MyVector::empty() const {
	return size > 0 ? 1 : 0;
}

int MyVector::get_size() const {
	return size;
}

int MyVector::get_capacity() const {
	return capacity;
}

void MyVector::push_back(const int elem) {
	++size;
	if (size == capacity) {
		capacity *= DEFAULT_TWO_DEGREE;
		int* newArr = new int[capacity];
		for (int i = 0; i < size - 1; ++i) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		newArr = nullptr;
	}
	arr[size - 1] = elem;
}

void MyVector::pop_back() {
	if (size > 0) {
		--size;
	}
}

int& MyVector::at(int index) const {
	if (index >= size || index < 0) {
		std::cout << "Error Index!" << std::endl;
	}
	return arr[index];
}

void MyVector::print() const {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << std::endl;
	}
}