// Homework24.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
#include <iostream>
#include <cstdarg>
#include <cmath>


template <typename T>
T calcPolinom(T x, int count, ...) { // c0 + c1*x + c2*x^2 + c3*x^3 + ...
	T result = 0;
	T c = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i) {
		c = va_arg(args, T);
		result += c * pow(x, i);
	}
	va_end(args);
	return result;
}


int main() {
	std::cout << calcPolinom(1.0, 3, 1.0, 2.0, 3.0) << std::endl; // 6 (OK)
	std::cout << calcPolinom(2.0, 2, 1.0, 2.0) << std::endl; // 5 (OK)
	std::cout << calcPolinom(2, 2, 1, 2) << std::endl; // 5 (OK)
	std::cout << calcPolinom(2, 1, 1) << std::endl; // 1 (OK)
}
