// Homework11_05.cpp : Defines the entry point for the console application.
// 5. ��� ���� input_2.txt, � ������� ���������� �����. ����� ���������, ������� ��� � ������ ������� ����� ����� 
// ����������� ����� ��, � �������� ��������� � ���� res_input_6.txt.
// ������ ������ : ����� ������� � ���������� ���� �� � ���.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


void readyFile(const std::string& path, std::vector<std::string>& arr) {
	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		std::cout << "File don't open!";
		return;
	}
	std::string words;
	while (std::getline(input, words)) {
		arr.push_back(words); // ������� ������ �����.
	}
	input.close();
}


void countLetterA(const std::vector<std::string>& arr, std::vector<int>& symbCount) {
	std::string line;
	int count;
	for (int i = 0; i < arr.size(); ++i) {
		line = arr[i]; // ���������� � ������ ������ ����������� ������� ������� �����.
		count = 0;
		for (int j = 0; j < line.length(); ++j) {
			if (line[j] == '�' || line[j] == '�') {
				++count; // ������� ���������� ���� � ������.
			}
		}
		symbCount.push_back(count); // ��������� ���������� ���� � ����� ������.
	}
}


void writeFile(const std::string& path, const std::vector<int>& symbCount) {
	std::ofstream output;
	output.open(path);
	output << "���� '�' ��� '�' � �������:" << '\n';
	for (int i = 0; i < symbCount.size(); ++i) {
		output << "������ " << i + 1 << ": " << symbCount[i] << '\n'; // � ������� ���� ������.
	}
	output.close();
}


int main() {
	setlocale(LC_ALL, "Russian");

	std::string filename_input = "input_2.txt";
	std::vector<std::string> arr;
	readyFile(filename_input, arr);

	std::vector<int> symbCount;
	countLetterA(arr, symbCount);

	std::string filename_output = "res_input_6.txt";
	writeFile(filename_output, symbCount);

	return 0;
}

