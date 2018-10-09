// Homework12_01.cpp : Defines the entry point for the console application.
/* Задание 1
Дан массив целых чисел.Пользуясь указателями, поменяйте местами соседние элементы массива с четными и нечетными индексами.
Например:
Было: 0, 1, 2, 3, 4, 5, 6, 7
Стало : 1, 0, 3, 2, 5, 4, 7, 6 */

#include "stdafx.h"
#include <iostream>


void swap(int arr[], const int SIZE) {
	int tmp = 0;
	int first_arr = 0;
	int second_arr = 0;
	int* pa = arr;
	while (pa < arr + SIZE - 1) {
		first_arr = *pa % 2; // определяем первый элемент сравнения как 0 или 1 (четное или нечетное)
		second_arr = *(pa + 1) % 2; // определяем второй элемент сравнения как 0 или 1
		if (first_arr > second_arr || first_arr < second_arr) {
			tmp = *pa;
			*pa = *(pa + 1);
			*(pa + 1) = tmp;
			pa += 2; // перепрыгиваем через 1 элемент в массиве, чтобы не затронуть уже поменявшиеся местами элементы.
		}
		else {
			++pa; // если обмена не было, переходим к следующему элементу массива.
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите 10 элементов массива:" << std::endl;
	const int SIZE = 10;
	int arr[SIZE];
	for (int* pa = arr; pa != arr + SIZE; ++pa) {
		std::cin >> *pa;
	}

	std::cout << "Исходный массив:" << std::endl;
	for (int* pa = arr; pa != arr + SIZE; ++pa) {
		std::cout << *pa << " ";
	}
	std::cout << std::endl;
	
	swap(arr, SIZE);

	std::cout << "Преобразованный массив:" << std::endl;
	for (int* pa = arr; pa != arr + SIZE; ++pa) {
		std::cout << *pa << " ";
	}
	std::cout << std::endl;

    return 0;
}

