// Homework11_02.cpp : Defines the entry point for the console application.
// 2. ��� ���� input_1.txt, � ������� ���������� ����� �����.
// ����� ���������, ����� ����� � ��� ������ : ������ ��� ��������. ��������� ���� �������� � ���� res_input_3.txt.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


void readyFile(const std::string& path, std::vector<int>& arr) {
	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		std::cout << "File don't open!";
		return;
	}
	int numbers;
	while (input >> numbers) {
		arr.push_back(numbers);
	}
	input.close();
}


void defineEvenOrOdd(const std::vector<int>& arr, int& even, int& odd) {
	int calc = 0;
	for (int i = 0; i < arr.size(); ++i) {
		calc = arr[i] % 2;
		if (calc == 0) {
			++even;
		 }
		else {
			++odd;
		}
	}
}


void writeFile(std::string& path, int& even, int& odd) {
	std::ofstream output;
	output.open(path);
	if (even > odd) {
		output << "������ ����� ������!" << '\n';
		output << "������: " << even << '\n';
		output << "��������: " << odd << '\n';
	}
	else {
		output << "�������� ����� ������!" << '\n';
		output << "��������: " << odd << '\n';
		output << "������: " << even << '\n';
	}
	output.close();
}


int main() {
	std::string filename_input = "input_1.txt";
	std::vector<int> arr;
	readyFile(filename_input, arr);

	int even = 0;
	int odd = 0;
	defineEvenOrOdd(arr, even, odd);

	std::string filename_output = "res_input_3.txt";
	writeFile(filename_output, even, odd);

	return 0;
}

