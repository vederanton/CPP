// Homework12_02.cpp : Defines the entry point for the console application.
/* ������� 2
���� ��� �������.��������� �����������, �������� ������ ������, � ������� ������ :
1) ��� �������� �� ����� ��������;
2) ����� �������� �� ����� ��������;
3) ��������, ������� ���� ������ � ������ �������;
4) ��������, ������� ���� ������ � ����� �� ��������. */

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
	int count = 0; // ������� �������������� ��������� 1 � 2 ��������
	int* pcount = &count;
	for (int* pa1 = arr1; pa1 != arr1 + SIZE1; ++pa1) {
		for (int* pa2 = arr2; pa2 != arr2 + SIZE2; ++pa2) {
			if (*pa1 == *pa2) {
				*pcount = 0; // ����������, ���� ���� ������� ������������
				break;
			}
			*pcount = 1; // 1, ���� ��� �������� ������������
		}
		if (*pcount == 1) { // ���� �� ��������� ����������� ����� ������� �� ���������, ������ �� ���� �����. ���� �� ���� ������������
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

	std::cout << "������� 5 ��������� ������� �������:" << std::endl;
	const int SIZE = 5;
	int arr1[SIZE];
	for (int* pa = arr1; pa != arr1 + SIZE; ++pa) {
		std::cin >> *pa;
	}

	std::cout << "\n������� 5 ��������� ������� �������:" << std::endl;
	int arr2[SIZE];
	for (int* pa = arr2; pa != arr2 + SIZE; ++pa) {
		std::cin >> *pa;
	}

	std::cout << "\n������ ������:" << std::endl;
	for (int* pa = arr1; pa != arr1 + SIZE; ++pa) {
		std::cout << *pa << " ";
	}
	std::cout << std::endl;

	std::cout << "\n������ ������:" << std::endl;
	for (int* pa = arr2; pa != arr2 + SIZE; ++pa) {
		std::cout << *pa << " ";
	}
	std::cout << std::endl;

	std::vector<int> arr3;
	addItems1(arr1, SIZE, arr2, SIZE, arr3);
	std::cout << "\n������ ������ � ���������� �� ����� ��������:" << std::endl;
	coutAndClearArr3(arr3);

	addItems2(arr1, SIZE, arr2, SIZE, arr3);
	std::cout << "������ ������ � ������ ���������� �� ����� ��������:" << std::endl;
	coutAndClearArr3(arr3);

	addItems3(arr1, SIZE, arr2, SIZE, arr3);
	std::cout << "������ ������ � ����������, ������� ���� ������ � ������ �������:" << std::endl;
	coutAndClearArr3(arr3);

	addItems3(arr1, SIZE, arr2, SIZE, arr3);
	addItems3(arr2, SIZE, arr1, SIZE, arr3); // ��� ���������� ������ ������� ������ �������� ��� �������, ������� ������� �������
	std::cout << "������ ������ � ����������, ������� ���� ������ � ����� �� ��������:" << std::endl;
	coutAndClearArr3(arr3);

    return 0;
}

