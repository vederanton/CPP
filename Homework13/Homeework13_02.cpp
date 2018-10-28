// Homeework13_02.cpp : Defines the entry point for the console application.
//������� 4
/* ���������� ������� resize.������� resize ��������� �� ���� ��� ��������� : 
��������� �� ������� ������, ���������� � ������� ��������� new[], ������ �������(size) � ����� ������(new_size).
������� ������ �������� ������ ������� new_size, ����������� � ��� ������ �� ���������� ������� ������, 
���������� ������ ������� ������ � ������� ���������� ������� ������ ������ ������� �� �������������� �������. */

#include "stdafx.h"
#include <iostream>


int* resize(int* arr, int size, int new_size)
{
	int* new_arr = new int[new_size];
	for (int i = 0; i < size; ++i) {
		new_arr[i] = arr[i];
	}		
	delete[] arr;
	arr = nullptr;
	return new_arr;
}


int main() {
	int size = 10;
	int* arr = new int[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
	}
	const int new_size = 20;
	int* new_arr = resize(arr, size, new_size);
	for (int i = 0; i < new_size; ++i) {
		std::cout << new_arr[i] << std::endl;
	}

    return 0;
}

