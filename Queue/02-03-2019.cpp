// 02-03-2019.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "queue.h"


int main() {
	Queue<int> q1;
	std::cout << q1.getCapacity() << std::endl; // 32
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.print(); // 1 2 3 4
	std::cout << q1.size() << std::endl; // 4
	q1.pop();
	q1.pop();
	q1.print(); // 3 4
	std::cout << q1.size() << std::endl; // 2
	std::cout << q1.empty() << std::endl; // 0
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.clear();
	std::cout << q1.size() << std::endl; // 0
	q1.push(1);
	std::cout << q1.back() << std::endl; // 1
	std::cout << q1.getCapacity() << std::endl; // 32
	for (int i = 0; i < 1000; ++i) {
		q1.push(i);
	}
	std::cout << q1.getCapacity() << std::endl; // 1024
	for (int i = 0; i < 800; ++i) {
		q1.pop();
	}
	std::cout << q1.getCapacity() << std::endl; // 256
	q1.clear();
	std::cout << q1.getCapacity() << std::endl; // 32

    return 0;
}

