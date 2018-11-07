// Homework14_02.cpp : Defines the entry point for the console application.
/* ������� 2
������������ ������ � ���������� ����������� �������.
�������� �������, ������� ����� �������� ������ ��� ��� ������� � ��������� �� ���������� �������.
�������� �������� ��������� ������� :
1) ����� ���� ��������� ������� � �������;
2) �������� �������(������� ������);
3) ���������� ����� ���������, ����������� �� ��������� �������;
4) ����������� ������� �� ����������� : ������������ ������ � ���������� ����� �������, 
������� ����������� � ������� � ����������� ������.����������� ������� ���������� ������.
5) ����������� ������� �� ��������� : ������������ ������ � ���������� ����� ������, 
������� ����������� � ������� � ����������� ������.����������� ������ ���������� ����. */

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
	printArr(ptr, a, b); // ����� 1 �������
	getSumElem(ptr, a, b); // ����� 3 �������
	
	std::cout << "\nEnter column index:" << std::endl;
	int indexB = 0;
	std::cin >> indexB;
	expandB(ptr, a, b, indexB); // ����� 4 �������
	b += 1;
	printArr(ptr, a, b);

	std::cout << "\nEnter row index:" << std::endl;
	int indexA = 0;
	std::cin >> indexA;
	ptr = expandA(ptr, a, b, indexA); // ����� 5 �������
	a += 1;
	printArr(ptr, a, b);
	
	deleteArr(ptr, a); // ����� 2 �������

	return 0;
}

