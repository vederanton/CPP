// Homework10_01.cpp : Defines the entry point for the console application.
// ������� 3. ���� ����������� ����� n. �������� ����������� �������, ������� ����� ��������
// ����� YES, ���� ����� n �������� ������ �������� ������, ��� ����� NO � ��������� ������.


#include "stdafx.h"
#include <iostream>


void pow_2(double n) {
	if (n == 1) {
		std::cout << "YES" << std::endl;
	}
	else if (n > 1 && n < 2) {
		std::cout << "NO" << std::endl;
	}
	else {
		pow_2(n / 2);
	}
}


int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "������� ����� ��� ��������: ";
	double n = 0;
	std::cin >> n;
	pow_2(n);

	return 0;
}

