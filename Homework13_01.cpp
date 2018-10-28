// Homework13_01.cpp : Defines the entry point for the console application.
/* ������� 2
��� ���� 2_input.txt, � ������� ���������� ������, ��������� �� ���� � ����.
�) �����������, ������� �� ������� ����� ������ ��������.
�) �������� ��������� ������� ������ �������� � ������� ������� � ��������� � ����������. 
���������� �������� � ���� result.txt.
�) �������� �������, ������� ������ � ����� ��� �������� ��������������������� � ����� ������ ���������, 
���� �� ����� ��� ���������������������, ��������� �������������. */

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>


void readFile(std::string& path, std::set<char>& mySet) { // ��� ������ �)
	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		return;
	}
	char tmp;
	while (input.get(tmp)) {
		mySet.insert(tmp);
	}
	input.close();
}


void readFile2(std::string& path, std::map<char, int>& myMap) { // ��� ������ �)
	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		return;
	}
	char tmp;
	int countCharTmp = 1;
	while (input.get(tmp)) {
		if (myMap.count(tmp) == 0) {
			myMap[tmp] = countCharTmp;
			continue;
		}		
		myMap.find(tmp)->second++;
	}
	input.close();
}


void writeFile2(std::string& path, std::map<char, int>& myMap) {
	std::ofstream output;
	output.open(path);
	for (auto& elem : myMap) {
		output << elem.first << '\t' << elem.second << '\n';
	}
	output.close();
}


void readFile3(std::string& path, std::set<std::string>& mySet) { // ��� ������ �)
	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		return;
	}
	char tmp;
	std::string tempStr = "";
	while (input.get(tmp)) {
		if (tmp == '1' || tmp == '2' || tmp == '3' || tmp == '4' || tmp == '5' ||
			tmp == '6' || tmp == '7' || tmp == '8' || tmp == '9' || tmp == '0') {
			tempStr += tmp;
			continue;
		}
		else if (!tempStr.empty()) {
			mySet.insert(tempStr);
			tempStr.clear();
		}	
	}
	input.close();
}


int main() {
	setlocale(LC_ALL, "Russian");

	std::string fileName = "2_input.txt";
	std::set<char> mySet;
	readFile(fileName, mySet);
	std::cout << "� ����� " << mySet.size() << " ������ ��������." << std::endl;
	mySet.clear();

	std::map<char, int> myMap;
	readFile2(fileName, myMap);
	std::string fileName2 = "result.txt";
	writeFile2(fileName2, myMap);
	myMap.clear();

	std::set<std::string> mySetStr;
	readFile3(fileName, mySetStr);
	std::cout << "������� �������� ���������������������: ";
	std::string numberCount = "";
	std::cin >> numberCount;
	if (mySetStr.count(numberCount)) {
		std::cout << "� ����� ���� ������ ���������������������!" << std::endl;
	}
	else {
		std::cout << "� ����� ��� ������ ���������������������!" << std::endl;
	}

    return 0;
}

