// Homework10_04.cpp : Defines the entry point for the console application.
/*
6. ���� ������������������ ����������� ����� (���� ����� � ������), �������������
������ 0. �������� ����������� �������, ������� ����� �������� ���������� �������� � ����
������������������. ������� �������� ������, �������� �� � ����������.*/

#include "stdafx.h"
#include <iostream>


int maxNumb() {
	std::cout << "������� �����: ";
	int a = 0;
	std::cin >> a;
	if (a == 0) {
		return 0;
	}
	int b = maxNumb();
	return a > b ? a : b;
}


int main() {
	setlocale(LC_ALL, "Russian");

	int max = maxNumb();
	std::cout << "������������ �����: " << max << std::endl;

	return 0;
}

