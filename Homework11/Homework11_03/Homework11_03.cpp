// Homework11_03.cpp : Defines the entry point for the console application.
// 3. Дан файл input_2.txt, в котором содержится текст. Нужно найти в этом тексте все разные слова 
// и записать их в файл res_input_4.txt. Знаки препинания удалять не нужно (считаем их словами или частями других слов).

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
	std::string word;
	while (input >> word) {
		arr.push_back(word);
	}
	input.close();
}


void deleteSameWords(std::vector<std::string>& arr) {
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = i + 1; j < arr.size() - 1; ++j) {
			if (arr[i] == arr[j]) {
				arr.erase(arr.begin() + j); // Удаление всех одинаковых слов.
			}
		}
	}
}


void writeFile(const std::string& path, std::vector<std::string>& arr) {
	std::ofstream output;
	output.open(path);
	for (int i = 0; i < arr.size(); ++i) {
		output << arr[i] << '\n';
	}
	output.close();
}


int main() {
	setlocale(LC_ALL, "Russian");
	
	std::string filename_input = "input_2.txt";
	std::vector<std::string> arr;
	readyFile(filename_input, arr);

	deleteSameWords(arr);

	std::string filename_output = "res_input_4.txt";
	writeFile(filename_output, arr);

	return 0;
}

