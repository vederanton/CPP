// Homework14_01.cpp : Defines the entry point for the console application.
/* ������� 1
��� ��������� �� ������ ������ �� ������ ��������.������������ ������ � ���������� �����, 
������� ����������� ����� �������� � ������. ����� ������������ ���������� ������� �����. 
�� ���� ��������� � ��������� ������, �� ������ ���� ����������� ������.
��������� ���������� ������, ����� ������������ ������ ������������� �����.
����� ��������� ����� ��������� ������� ��� �����, ���������� � ������, 
� �������� ������������ � ������������� �������� � ���� �������.
����������. ������������ �� ����� ������� ������������� ����� ���������, � �� ����� �������. */

#include "stdafx.h"
#include <iostream>


int main() {
	setlocale(LC_ALL, "Russian");

	int sz = 1;
	int* ptr_arr = new int[sz];
	std::cout << "Input: " << std::endl;
	int tmp = 0;
	std::cin >> tmp;
	ptr_arr[0] = tmp;

	while (true) {
	std::cout << "Input: " << std::endl;
	std::cin >> tmp;
	if (tmp < 0) {
	break;
	}
	int* new_ptr = new int[sz + 1];

	int* pa = ptr_arr;
	int* pnew = new_ptr;
	while (pa != ptr_arr + sz) {
		*pnew = *pa;
		++pa;
		++pnew;
	}
	pa = nullptr;
	pnew = nullptr;

	new_ptr[sz] = tmp;
	++sz;
	delete[] ptr_arr;
	ptr_arr = new_ptr;
	}

	for (int* ptr = ptr_arr; ptr != ptr_arr + sz; ++ptr) {
	std::cout << *ptr << " ";
	}
	std::cout << std::endl;

	int min = *ptr_arr;
	int max = *ptr_arr;
	for (int* ptr = ptr_arr; ptr != ptr_arr + sz - 1; ++ptr) {
		if (*(ptr + 1) < *ptr && *(ptr + 1) < min) {
			min = *(ptr + 1);
		}
		else if (*(ptr + 1) > *ptr && *(ptr + 1) > max) {
			max = *(ptr + 1);
		}
	}
	std::cout << "������� ����� ������������ � ����������� ���������: " << max - min << std::endl;

	delete[] ptr_arr;
	ptr_arr = nullptr;

	return 0;
}

