// Homework14_02.cpp : Defines the entry point for the console application.
/* Задание 2
Пользователь вводит с клавиатуры размерность матрицы.
Напишите функцию, которая будет выделять память под эту матрицу и заполнять ее случайными числами.
Отдельно создайте следующие функции :
1) вывод всех элементов матрицы в консоль;
2) удаление матрицы(очистка памяти);
3) вычисление суммы элементов, находящихся на диагонали матрицы;
4) «расширение» матрицы по горизонтали : пользователь вводит с клавиатуры номер столбца, 
который вставляется в матрицу и заполняется нулями.Последующие столбцы сдвигаются правее.
5) «расширение» матрицы по вертикали : пользователь вводит с клавиатуры номер строки, 
которая вставляется в матрицу и заполняется нулями.Последующие строки сдвигаются ниже. */

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>


int** createArr(const int a, const int b) {
	int** ptr_arr = new int*[a];
	for (int i = 0; i < a; ++i) {
		ptr_arr[i] = new int[b];
	}
	return ptr_arr;
}


void deleteArr(int** ptr_arr, const int a) {
	for (int i = 0; i < a; ++i) {
		delete[] ptr_arr[i];
	}
	delete[] ptr_arr;
	ptr_arr = nullptr;
}


void fillArr(int** ptr_arr, const int a, const int b) {
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			ptr_arr[i][j] = 1 + rand() % 100;
		}
	}
}


void printArr(int** ptr_arr, const int a, const int b) {
	std::cout << "\nYoure matrix: " << std::endl;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			std::cout << ptr_arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


void getSumElem(int** ptr_arr, const int a, const int b) {
	int sum = 0;
	int i = 0;
	int j = 0;
	while (i < a) {
		sum += ptr_arr[i][j];
		++i;
		++j;
	}
	std::cout << "\nThe sum of the elements of the diagonal: " << sum << std::endl;
}


void expandB(int** ptr_arr, const int a, const int b, const int indexB) {
	std::vector<int> tmp;
	int newSizeB = b + 1;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < newSizeB; ++j) {
			if (j == indexB) {
				tmp.push_back(0);
			}
			tmp.push_back(ptr_arr[i][j]);
		}
		delete[] ptr_arr[i];
		ptr_arr[i] = new int[newSizeB];
		for (int j = 0; j < newSizeB; ++j) {
			ptr_arr[i][j] = tmp[j];
		}
		tmp.clear();
	}
	tmp.shrink_to_fit();
}


int** expandA(int** ptr_arr, const int a, const int b, const int indexA) {
	int new_size_a = a + 1;
	int** ptr_arr_new = new int*[new_size_a];
	for (int i = 0; i < new_size_a; ++i) {
		ptr_arr_new[i] = new int[b];
	}

	for (int i = 0; i < new_size_a; ++i) {
		for (int j = 0; j < b; ++j) {
			if (i == indexA) {
				ptr_arr_new[i][j] = 0;
			}
			else if (i > indexA) {
				ptr_arr_new[i][j] = ptr_arr[i - 1][j];
			}
			else {
				ptr_arr_new[i][j] = ptr_arr[i][j];
			}
		}
	}

	for (int i = 0; i < a; ++i) {
		delete[] ptr_arr[i];
	}
	delete[] ptr_arr;
	ptr_arr = ptr_arr_new;
	return ptr_arr;
}


int main() {
	std::cout << "Input AxB: " << std::endl;
	int a, b;
	std::cin >> a >> b;

	int** ptr = createArr(a, b);
	srand(time(NULL));
	fillArr(ptr, a, b);
	printArr(ptr, a, b); // Пункт 1 задания
	getSumElem(ptr, a, b); // Пункт 3 задания
	
	std::cout << "\nEnter column index:" << std::endl;
	int indexB = 0;
	std::cin >> indexB;
	expandB(ptr, a, b, indexB); // Пункт 4 задания
	b += 1;
	printArr(ptr, a, b);

	std::cout << "\nEnter row index:" << std::endl;
	int indexA = 0;
	std::cin >> indexA;
	ptr = expandA(ptr, a, b, indexA); // Пункт 5 задания
	a += 1;
	printArr(ptr, a, b);
	
	deleteArr(ptr, a); // Пункт 2 задания

	return 0;
}

