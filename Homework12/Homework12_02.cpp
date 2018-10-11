// Homework12_02.cpp : Defines the entry point for the console application.
/* Задание 2
Даны два массива.Пользуясь указателями, создайте третий массив, в который войдут :
1) все элементы из обоих массивов;
2) общие элементы из обоих массивов;
3) элементы, которые есть только в первом массиве;
4) элементы, которые есть только в одном из массивов. */

#include "stdafx.h"
#include <iostream>
#include <vector>


void addItems1(int arr1[], const int SIZE1, int arr2[], const int SIZE2, std::vector<int>& arr3) {	
	for (int* pa1 = arr1; pa1 != arr1 + SIZE1; ++pa1) {
		arr3.push_back(*pa1);
	}
	for (int* pa2 = arr2; pa2 != arr2 + SIZE2; ++pa2) {
		arr3.push_back(*pa2);
	}
}


void addItems2(int arr1[], const int SIZE1, int arr2[], const int SIZE2, std::vector<int>& arr3) {
	for (int* pa1 = arr1; pa1 != arr1 + SIZE1; ++pa1) {
		for (int* pa2 = arr2; pa2 != arr2 + SIZE2; ++pa2) {
			if (*pa1 == *pa2) {
				arr3.push_back(*pa1);
				break;
			}
		}
	}
}


void addItems3(int arr1[], const int SIZE1, int arr2[], const int SIZE2, std::vector<int>& arr3) {
	int count = 0; // Счетчик несоответствий элементов 1 и 2 массивов
	int* pcount = &count;
	for (int* pa1 = arr1; pa1 != arr1 + SIZE1; ++pa1) {
		for (int* pa2 = arr2; pa2 != arr2 + SIZE2; ++pa2) {
			if (*pa1 == *pa2) {
				*pcount = 0; // Обнуляется, если есть текущее соответствие
				break;
			}
			*pcount = 1; // 1, если нет текущего соответствия
		}
		if (*pcount == 1) { // Если по окончанию внутреннего цикла счетчик не обнулился, значит за весь внутр. цикл не было соответствий
			arr3.push_back(*pa1);
		}
	}
}

void coutAndClearArr3(std::vector<int>& arr3) {
	for (int i = 0; i < arr3.size(); ++i) {
		std::cout << arr3[i] << " ";
	}
	std::cout << std::endl;
	arr3.clear();
	std::cout << std::endl;
}


int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите 5 элементов первого массива:" << std::endl;
	const int SIZE = 5;
	int arr1[SIZE];
	for (int* pa = arr1; pa != arr1 + SIZE; ++pa) {
		std::cin >> *pa;
	}

	std::cout << "\nВведите 5 элементов второго массива:" << std::endl;
	int arr2[SIZE];
	for (int* pa = arr2; pa != arr2 + SIZE; ++pa) {
		std::cin >> *pa;
	}

	std::cout << "\nПервый массив:" << std::endl;
	for (int* pa = arr1; pa != arr1 + SIZE; ++pa) {
		std::cout << *pa << " ";
	}
	std::cout << std::endl;

	std::cout << "\nВторой массив:" << std::endl;
	for (int* pa = arr2; pa != arr2 + SIZE; ++pa) {
		std::cout << *pa << " ";
	}
	std::cout << std::endl;

	std::vector<int> arr3;
	addItems1(arr1, SIZE, arr2, SIZE, arr3);
	std::cout << "\nТретий массив с элементами из обоих массивов:" << std::endl;
	coutAndClearArr3(arr3);

	addItems2(arr1, SIZE, arr2, SIZE, arr3);
	std::cout << "Третий массив с общими элементами из обоих массивов:" << std::endl;
	coutAndClearArr3(arr3);

	addItems3(arr1, SIZE, arr2, SIZE, arr3);
	std::cout << "Третий массив с элементами, которые есть только в первом массиве:" << std::endl;
	coutAndClearArr3(arr3);

	addItems3(arr1, SIZE, arr2, SIZE, arr3);
	addItems3(arr2, SIZE, arr1, SIZE, arr3); // Для четвертого пункта задания просто повторим эту функцию, поменяв местами массивы
	std::cout << "Третий массив с элементами, которые есть только в одном из массивов:" << std::endl;
	coutAndClearArr3(arr3);

    return 0;
}

