// Homework11_04.cpp : Defines the entry point for the console application.
// 4. Дан файл input_2.txt, в котором содержится текст. Нужно сосчитать, сколько раз в этом тексте 
// встречается буква «а», и записать результат в файл res_input_5.txt.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


void readyFile(const std::string& path, std::vector<char>& arr) {
	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		std::cout << "File don't open!";
		return;
	}
	char symb;
	while (input.get(symb)) {
		arr.push_back(symb);
	}
	input.close();
}


int countLetterA(std::vector<char>& arr) {
	int count = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == 'а' || arr[i] == 'А') {
			++count;
		}
	}
	return count;
}


void writeFile(const std::string& path, const int& count) {
	std::ofstream output;
	output.open(path);
	output << "Количество символов 'а' или 'А' равно: " << count << '\n';
	output.close();
}


int main() {
	setlocale(LC_ALL, "Russian");

	std::string filename_input = "input_2.txt";
	std::vector<char> arr;
	readyFile(filename_input, arr);

	int count = countLetterA(arr);

	std::string filename_output = "res_input_5.txt";
	writeFile(filename_output, count);

	return 0;
}

