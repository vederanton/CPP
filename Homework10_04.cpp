// Homework10_04.cpp : Defines the entry point for the console application.
/*
6. Дана последовательность натуральных чисел (одно число в строке), завершающаяся
числом 0. Напишите рекурсивную функцию, которая будет находить наибольшее значение в этой
последовательности. Функция получает данные, считывая их с клавиатуры.
*/


#include "stdafx.h"
#include <iostream>


int maxNumb() {
	std::cout << "Введите число: ";
	int a = 0;
	std::cin >> a;
	if (a == 0) {
		return 0;
	}
	int b = maxNumb();
	return a > b ? a : b;
}


int main() {
	setlocale(LC_ALL, "Russian");

	int max = maxNumb();
	std::cout << "Максимальное число: " << max << std::endl;

	return 0;
}

