// Homework10_02.cpp : Defines the entry point for the console application.
/*
4. �������� ����������� �������, ������� ����� ��������� n - �� ����� ���������.
���������.������� ��������� ���������� ������������������, ������ �������
�������, ������� � ��������, �������� ������ ���� ���������� ���������.������� �����
���������� ���� �������� ����� 0 � 1:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34�*/

#include "stdafx.h"
#include <iostream>


int fibNumber(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return fibNumber(n - 1) + fibNumber(n - 2);
}


int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "������� �����: ";
	int n = 0;
	std::cin >> n;
	int fib = fibNumber(n);
	std::cout << "����� ��������� �����: " << fib << std::endl;

	return 0;
}

