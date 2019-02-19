// 16-02-2019.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <map>


namespace fs = std::experimental::filesystem;

int main() {
	setlocale(LC_ALL, "rus");

	std::cout << "Enter the path to save the file with the results (ex: c:\\\\myDir\\ ): ";
	std::string myPath = "";
	std::cin >> myPath;
	std::cout << "\nEnter the filename for results (ex: test.txt ): ";
	std::string fileNameResults = "";
	std::cin >> fileNameResults;
	myPath.append(fileNameResults);

	std::fstream f(myPath);
	f.open(myPath, std::ios::out);
	if (!f.is_open()) {
		std::cout << "Erorr! File doesn't open or create!" << std::endl;
		return -1;
	}

	std::cout << "\nEnter the path to scan files and folders (ex: c:\\\\myDir ): ";
	std::cin >> myPath;

	std::multimap<std::uintmax_t, fs::v1::path> fileList; // for sort sizes of files
	for (auto& p : fs::directory_iterator(myPath)) {
		auto& filePath = p.path();
		if (!fs::is_directory(filePath)) {
			fileList.insert({ fs::file_size(filePath), filePath });
		}
		else {
			std::uintmax_t sizeDir = 0;
			for (auto& p2 : fs::recursive_directory_iterator(filePath)) {
				auto& filePathTmp = p2.path();
				if (!fs::is_directory(filePathTmp)) {
					sizeDir += fs::file_size(filePathTmp);
				}
			}
			fileList.insert({ sizeDir, filePath });
		}
	}

	for (auto& it : fileList) {
		f << it.first << " : " << it.second << '\n';
	}

	f.close();

    return 0;
}
