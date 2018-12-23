// Homework18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Test.h"
#include "MyVector.h"
#include <iostream>

int main() {
	//Test t;
	//t.test();
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	MyVector vec(arr, 10);
	vec.print();
	std::cout << vec.get_capacity() << std::endl;
	std::cout << vec.get_size() << std::endl;
	vec.push_back(999);
	vec.print();
	vec.pop_back();
	std::cout << vec.get_size() << std::endl;
	std::cout << vec.at(5) << std::endl;
}
