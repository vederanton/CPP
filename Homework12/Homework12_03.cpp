// Homework12_03.cpp : Defines the entry point for the console application.
/* ������� 3
1. �������� ������ ��������� ���� std::vector.
2. �������� ������ ��������� ���� std::vector.
3. ��������� ������ ������� �������, �������� � ��������� �� 1 �� 99.
4. �������� � ������� ������ � ������� �������.
5. �������� �������� ������� �������� ���, ����� ��� ���� ����� ���������� ��������� � �������.
6. ������� �� ������� �������� ��� ��������� 7, 14 � 21.
7. ����������, ������� � ������� ���������, ������� 4, � �������� ���������� ����� � �������.
8. �������� �������� 20 - �� �������� � ������� �� 99.
9. ������� �� ������� ��������� �������.
10. �������� ��������� ������� ������� �� 101.
11. �������� � ������� ������ ������� � ��� ��� �������� ����� ������. */

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


int main() {
	setlocale(LC_ALL, "Russian");

	std::vector<int> myVec;
	srand(time(NULL));
	for (int i = 0; i < 100; ++i) {
		int randElem = 1 + rand() % 98;
		if (randElem % 2 == 0) {
			myVec.push_back(randElem);
			continue;
		}
		myVec.push_back(randElem + 1);
	}
	std::cout << "��������� ������:" << std::endl;
	for (int i = 0; i < myVec.size(); ++i) {
		std::cout << "������� " << i + 1 << ": " << myVec[i] << std::endl;
	}

	std::cout << "\n������ �������: " << myVec.size() << std::endl;
	std::cout << "������� �������: " << myVec.capacity() << std::endl;

	myVec.front() = myVec.size();
	std::cout << "\n������ ������� 1: " << myVec.front() << std::endl;

	myVec.erase(myVec.begin() + 7); // ������� 8 ������� � �������� 7
	myVec.erase(myVec.begin() + 13); // 15 � �������� 14 (����� ����������� �������� ��������� �� ������ 13)
	myVec.erase(myVec.begin() + 19); // 22 � �������� 21 (��������� �� ������ 19)
	std::cout << "\n�� ����� ��������� ��������� 8, 15 � 22 ������ �������� 9, 17 � 25 ��������� �������: " << std::endl;
	std::cout << "������� 8: " << myVec[7] << std::endl;
	std::cout << "������� 15: " << myVec[14] << std::endl;
	std::cout << "������� 22: " << myVec[21] << std::endl;

	int count = 0;
	for (auto it = myVec.begin(); it != myVec.end(); ++it) {
		if (*it % 4 == 0) {
			++count;
		}
	}
	std::cout << "\n��������� �������, ������� 4: " << count << std::endl;

	myVec[19] = 99;
	std::cout << "\n������ ������� 20: " << myVec[19] << std::endl;

	myVec.pop_back();
	std::cout << "\n��������� ������� ������" << std::endl;

	myVec.pop_back();
	myVec.push_back(101);
	std::cout << "\n������ ������ ���������� �������� ��������� ������� �� ��������� 101" << std::endl;

	std::cout << "\n������ �������: " << myVec.size() << std::endl;
	std::cout << "\n���������� ������: " << std::endl;
	for (auto elem : myVec) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

    return 0;
}

