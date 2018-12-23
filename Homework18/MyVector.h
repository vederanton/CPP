#pragma once

class MyVector {
	int* arr = nullptr;
	int size = 0;
	int capacity;
	static int allVecCount;
	static int nowVecCount;
public:
	MyVector();
	MyVector(const int array[], const int sz);
	MyVector(const MyVector&);
	MyVector(MyVector&&);
	virtual ~MyVector();

	static int getAllVecCount();
	static int getNowVecCount();
	bool empty() const;
	int get_size() const;
	int get_capacity() const;
	void push_back(const int);
	void pop_back();
	int& at(int) const;
	void print() const;

};