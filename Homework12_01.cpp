// Homework12_01.cpp : Defines the entry point for the console application.
/* ������� 1
��� ������ ����� �����.��������� �����������, ��������� ������� �������� �������� ������� � ������� � ��������� ���������.
��������:
����: 0, 1, 2, 3, 4, 5, 6, 7
����� : 1, 0, 3, 2, 5, 4, 7, 6 */

#include "stdafx.h"
#include <iostream>


void swap(int arr[], const int SIZE) {
	int tmp = 0;
	int first_arr = 0;
	int second_arr = 0;
	int* pa = arr;
	while (pa < arr + SIZE - 1) {
		first_arr = *pa % 2; // ���������� ������ ������� ��������� ��� 0 ��� 1 (������ ��� ��������)
		second_arr = *(pa + 1) % 2; // ���������� ������ ������� ��������� ��� 0 ��� 1
		if (first_arr > second_arr || first_arr < second_arr) {
			tmp = *pa;
			*pa = *(pa + 1);
			*(pa + 1) = tmp;
			pa += 2; // ������������� ����� 1 ������� � �������, ����� �� ��������� ��� ������������ ������� ��������.
		}
		else {
			++pa; // ���� ������ �� ����, ��������� � ���������� �������� �������.
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "������� 10 ��������� �������:" << std::endl;
	const int SIZE = 10;
	int arr[SIZE];
	for (int* pa = arr; pa != arr + SIZE; ++pa) {
		std::cin >> *pa;
	}

	std::cout << "�������� ������:" << std::endl;
	for (int* pa = arr; pa != arr + SIZE; ++pa) {
		std::cout << *pa << " ";
	}
	std::cout << std::endl;
	
	swap(arr, SIZE);

	std::cout << "��������������� ������:" << std::endl;
	for (int* pa = arr; pa != arr + SIZE; ++pa) {
		std::cout << *pa << " ";
	}
	std::cout << std::endl;

    return 0;
}

