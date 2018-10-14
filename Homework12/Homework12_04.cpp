// Homework12_04.cpp : Defines the entry point for the console application.
/* Задание 4
1. Создайте контейнер типа std::map и вставьте в него пары{ 1, 1 }, { 2, 4 }, { 3, 9 }, { 4, 16 }, { 5, 25 }, { 6, 36 }, { 7, 49 }, { 8, 64 }, { 9, 81 }.
2. Выведите содержимое словаря в консоль в формате key = > value.
3. Замените значение по ключу 7 на 14.
4. Вставьте в словарь пару{ 10, 30 }.
5. Удалите из словаря пару с ключом 5.
6. Увеличьте значение по каждому ключу на величину ключа.
7. Проверьте, содержится ли в словаре пара с ключом 7, и если нет, то вставьте в словарь пару{ 7, 5 }.
8. Вычислите произведение всех значений словаря по нечетным ключам и выведите его в консоль.
9. Выведите содержимое словаря в консоль в формате key = > value. */

#include "stdafx.h"
#include <iostream>
#include <map>


int main() {
	setlocale(LC_ALL, "Russian");

	std::map<int, int> myMap = { {1, 1}, {2, 4}, {3, 9}, {4, 16}, {5, 25}, 
							     {6, 36}, {7, 49}, {8, 64}, {9, 81} };

	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		std::cout << it->first << " = > " << it->second << std::endl;
	}
	std::cout << std::endl;

	myMap[7] = 14;
	myMap[10] = 30;
	myMap.erase(5);

	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		it->second += it->first;
	}

	if (myMap.count(7) == 0) {
		myMap[7] = 5;
	}

	double multi = 1;
	double* pmulti = &multi;
	for (auto elem : myMap) {
		if (elem.first % 2 == 1) {
			*pmulti *= elem.second;
		}
	}
	std::cout << "Произведение в новом map: " << *pmulti << std::endl;
	pmulti = nullptr;
	std::cout << std::endl;

	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		std::cout << it->first << " = > " << it->second << std::endl;
	}
	
    return 0;
}
