// Homework12_03.cpp : Defines the entry point for the console application.
/* Задание 3
1. Создайте пустой контейнер типа std::vector.
2. Создайте пустой контейнер типа std::vector.
3. Заполните вектор четными числами, лежащими в диапазоне от 1 до 99.
4. Выведите в консоль размер и емкость вектора.
5. Измените значение первого элемента так, чтобы оно было равно количеству элементов в векторе.
6. Удалите из вектора элементы под индексами 7, 14 и 21.
7. Сосчитайте, сколько в векторе элементов, кратных 4, и выведите полученное число в консоль.
8. Замените значение 20 - го элемента в векторе на 99.
9. Удалите из вектора последний элемент.
10. Замените последний элемент вектора на 101.
11. Выведите в консоль размер вектора и все его элементы через пробел. */

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


int main() {
	setlocale(LC_ALL, "Russian");

	std::vector<int> myVec;
	srand(time(NULL));
	for (int i = 0; i < 100; ++i) {
		int randElem = 1 + rand() % 98;
		if (randElem % 2 == 0) {
			myVec.push_back(randElem);
			continue;
		}
		myVec.push_back(randElem + 1);
	}
	std::cout << "Созданный вектор:" << std::endl;
	for (int i = 0; i < myVec.size(); ++i) {
		std::cout << "Элемент " << i + 1 << ": " << myVec[i] << std::endl;
	}

	std::cout << "\nРазмер вектора: " << myVec.size() << std::endl;
	std::cout << "Емкость вектора: " << myVec.capacity() << std::endl;

	myVec.front() = myVec.size();
	std::cout << "\nТеперь элемент 1: " << myVec.front() << std::endl;

	myVec.erase(myVec.begin() + 7); // Удаляем 8 элемент с индексом 7
	myVec.erase(myVec.begin() + 13); // 15 с индексом 14 (после предыдущего удаления сместился на индекс 13)
	myVec.erase(myVec.begin() + 19); // 22 с индексом 21 (сместился на индекс 19)
	std::cout << "\nНа место удаленных элементов 8, 15 и 22 встали элементы 9, 17 и 25 исходного вектора: " << std::endl;
	std::cout << "Элемент 8: " << myVec[7] << std::endl;
	std::cout << "Элемент 15: " << myVec[14] << std::endl;
	std::cout << "Элемент 22: " << myVec[21] << std::endl;

	int count = 0;
	for (auto it = myVec.begin(); it != myVec.end(); ++it) {
		if (*it % 4 == 0) {
			++count;
		}
	}
	std::cout << "\nЭлементов вектора, кратных 4: " << count << std::endl;

	myVec[19] = 99;
	std::cout << "\nТеперь элемент 20: " << myVec[19] << std::endl;

	myVec.pop_back();
	std::cout << "\nПоследний элемент удален" << std::endl;

	myVec.pop_back();
	myVec.push_back(101);
	std::cout << "\nВместо нового последнего элемента поставлен элемент со значением 101" << std::endl;

	std::cout << "\nРазмер вектора: " << myVec.size() << std::endl;
	std::cout << "\nПолученный вектор: " << std::endl;
	for (auto elem : myVec) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

    return 0;
}

