// Homework10_03.cpp : Defines the entry point for the console application.
/*
5. ���� ����������� ����� n. �������� ����������� �������, ������� ����� ���������
����� ��� ����.*/

#include "stdafx.h"
#include <iostream>


int sum(int n) {
	if (n < 10) {
		return n;
	}
	return sum(n / 10) + (n % 10);
}


int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "������� �����: ";
	int n = 0;
	std::cin >> n;
	int fib = sum(n);
	std::cout << "����� ���� ����� �����: " << fib << std::endl;

	return 0;
}

