// Homework23.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
#include "RingBuffer.h"


int main() {
	RingBuffer<int> r1 = { 12, 43, 761, 13};
	r1.print(); // 12 43 761 13
	r1.erase(2);
	r1.print(); // 12 43 13
	std::cout << r1.at(0) << std::endl; // 12
	r1.push(99);
	std::cout << r1.capacity() << std::endl; // 4
	r1.resize(10);
	std::cout << r1.capacity() << std::endl; // 10
	r1.resize(5);
	std::cout << r1.capacity() << std::endl; // 5

	r1.push(222);
	r1.print(); // 12 43 13 99 222
	r1.push(1000);
	r1.print(); // 43 13 99 222 1000
}