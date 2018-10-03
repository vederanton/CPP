// Homework11_01.cpp : Defines the entry point for the console application.
// 1. ƒан файл input_1.txt, в котором содержатс€ целые числа. Ќужно записать эти числа в файл res_input_1.txt
// в отсортированном виде (по 1 числу на строку, сортировка по возрастанию).

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


void sort(std::vector<int>& arr) {
	int tmp = 0;
	int minIndex = 0;
	for (int i = 0; i < arr.size() - 1; ++i) {
		minIndex = i;
		for (int j = i + 1; j < arr.size(); ++j) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
}


void writeFile(std::string& path, std::vector<int>& arr) {
	std::ofstream output;
	output.open(path);
	for (int i = 0; i < arr.size(); ++i) {
		output << arr[i] << '\n';
	}
	output.close();
}


int main() {
	std::string filename_input = "input_1.txt";
	std::vector<int> arr;
	readyFile(filename_input, arr);

	sort(arr);

	std::string filename_output = "res_input_1.txt";
	writeFile(filename_output, arr);

    return 0;
}

