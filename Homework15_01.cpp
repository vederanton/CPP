// Homework15_01.cpp : Defines the entry point for the console application.

/* ������� ��������� ������������� � ������. 
� ��������� ������ ������ ���� ��������� ����: 
�������� ������, ��������, ����, ������� ������������, ����.

����������� ��������� ����������� : 
- ����� ������ �� �������� 
- ����� ������ �� ����� 
- ����� ������ �� ��������� 
- ����� ������ ����������� ������ ���������� ����� 
- ����� ���� �������, ������� ���� � �������� 
- ���������� ������ � ������� 
- �������� ������ �� �������� 
- ���������� ������� �� �������� */


#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <windows.h>


std::string RUS(const std::string&  DOS_string) // ��� ����������� �������������� ���. �������� � ����� � ����������.
{
	char*  p_buf = new char[DOS_string.length() + 1];
	OemToCharA(DOS_string.c_str(), p_buf);
	std::string res(p_buf);
	delete[] p_buf;
	return res;
}


struct Film {
	std::string filmName;
	std::string filmDirector;
	std::string filmGenre;
	float filmRating;
	float filmPrice;
};


struct VideoMarket {
	std::map<std::string, Film> catalog; // ������ � ���������� ����� ��������� �������� ������.

	void searchFilmName() { // ����� �� �������� ������
		std::cout << "\n������� �������� ������ ��� ������: ";
		std::string tmp;
		std::getline(std::cin, tmp);
		if (catalog.count(RUS(tmp))) {
			auto it = catalog.find(RUS(tmp));
			std::cout << "\n�������� ������: " << it->second.filmName << std::endl;
			std::cout << "��������: " << it->second.filmDirector << std::endl;
			std::cout << "����: " << it->second.filmGenre << std::endl;
			std::cout << "�������: " << it->second.filmRating << std::endl;
			std::cout << "����: " << it->second.filmPrice << std::endl;
		}
		else {
			std::cout << "����� �� ������!" << std::endl;
		}
	}

	void searchFilmGenre() { // ����� ������� �� �����
		std::cout << "\n������� ���� ������ ��� ������: ";
		std::string tmp;
		std::getline(std::cin, tmp);
		int count = 0;
		for (auto it = catalog.begin(); it != catalog.end(); ++it) {
			if (it->second.filmGenre == RUS(tmp)) {
				std::cout << "\n�������� ������: " << it->second.filmName << std::endl;
				std::cout << "��������: " << it->second.filmDirector << std::endl;
				std::cout << "����: " << it->second.filmGenre << std::endl;
				std::cout << "�������: " << it->second.filmRating << std::endl;
				std::cout << "����: " << it->second.filmPrice << std::endl;
				++count;
			}
		}
		if (count == 0) {
			std::cout << "������ �� �������!" << std::endl;
		}
	}

	void searchFilmDirector() { // ����� ������� �� ���������
		std::cout << "\n������� ��������� ������ ��� ������: ";
		std::string tmp;
		std::getline(std::cin, tmp);
		int count = 0;
		for (auto it = catalog.begin(); it != catalog.end(); ++it) {
			if (it->second.filmDirector == RUS(tmp)) {
				std::cout << "\n�������� ������: " << it->second.filmName << std::endl;
				std::cout << "��������: " << it->second.filmDirector << std::endl;
				std::cout << "����: " << it->second.filmGenre << std::endl;
				std::cout << "�������: " << it->second.filmRating << std::endl;
				std::cout << "����: " << it->second.filmPrice << std::endl;
				++count;
			}
		}
		if (count == 0) {
			std::cout << "������ �� �������!" << std::endl;
		}
	}

	void searchFilmGenreMostPopular() { // ����� ���� ������� ����� � ��������� ��������� (���� �� ����������)
		std::cout << "\n������� ���� ��� ������ ������(��) � ��������� ���������: ";
		std::string tmp;
		std::getline(std::cin, tmp);
		std::string tmpFilmName = "";
		float tmpFilmRating = 0;
		for (auto it = catalog.begin(); it != catalog.end(); ++it) { // ������� ���� ������������ ������� �����
			if (it->second.filmGenre == RUS(tmp)) {
				if (it->second.filmRating > tmpFilmRating) {
					tmpFilmRating = it->second.filmRating;
				}
			}
		}
		for (auto it = catalog.begin(); it != catalog.end(); ++it) { // � ����� ������� ��� ������ � ����. ��������� ������� �����
			if (it->second.filmGenre == RUS(tmp)) {
				if (it->second.filmRating == tmpFilmRating) {
					std::cout << "\n�������� ������: " << it->second.filmName << std::endl;
					std::cout << "��������: " << it->second.filmDirector << std::endl;
					std::cout << "����: " << it->second.filmGenre << std::endl;
					std::cout << "�������: " << it->second.filmRating << std::endl;
					std::cout << "����: " << it->second.filmPrice << std::endl;
				}
			}
		}
	}

	void showAllFilms() { // ����� ���� ������� � �������
		std::cout << "\n������ � �������:" << std::endl;
		int count = 0;
		for (auto it = catalog.begin(); it != catalog.end(); ++it) {
			std::cout << "\n�������� ������: " << it->second.filmName << std::endl;
			std::cout << "��������: " << it->second.filmDirector << std::endl;
			std::cout << "����: " << it->second.filmGenre << std::endl;
			std::cout << "�������: " << it->second.filmRating << std::endl;
			std::cout << "����: " << it->second.filmPrice << std::endl;
			++count;
		}
		if (count == 0) {
			std::cout << "��� �� ������ ������!" << std::endl;
		}
	}

	void addFilm() { // ���������� ������ � �������
		std::cout << "\n������� �������� ������: ";
		std::string tmp = "";
		std::getline(std::cin, tmp);
		Film newFilm; // ��� �������� ����� �������
		catalog[RUS(tmp)] = newFilm;
		auto it = catalog.find(RUS(tmp));
		it->second.filmName = RUS(tmp);
		std::cout << "��������: ";
		std::getline(std::cin, tmp);
		it->second.filmDirector = RUS(tmp);
		std::cout << "����: ";
		std::getline(std::cin, tmp);
		it->second.filmGenre = RUS(tmp);
		std::cout << "�������: ";
		float tmp2 = 0;
		std::cin >> tmp2;
		it->second.filmRating = tmp2;
		std::cout << "����: ";
		std::cin >> tmp2;
		it->second.filmPrice = tmp2;
		std::cin.ignore(); // ��� �������� '\n' �� ������
	}

	void deleteFilm() { // �������� ������ �� ��������
		std::cout << "\n������� �������� ������ ��� ��������: ";
		std::string tmp;
		std::getline(std::cin, tmp);
		if (catalog.count(RUS(tmp))) {
			catalog.erase(RUS(tmp));
		}
		else {
			std::cout << "������ ������ �� ����������!" << std::endl;
		}

	}

	void sortFilmRating() { // ����� ������� �� ��������
		std::multimap<float, std::string> tmpFilmRate; // multimap ��� ������� ���������� ��������.
		for (auto it = catalog.begin(); it != catalog.end(); ++it) {
			tmpFilmRate.insert(std::pair<float, std::string> (it->second.filmRating, it->first)); // ���� - �������, �������� - ��������
		}
		for (auto it2 = tmpFilmRate.rbegin(); it2 != tmpFilmRate.rend(); ++it2) { // � �������� �����������
			auto it = catalog.find(it2->second);
			std::cout << "\n�������� ������: " << it->second.filmName << std::endl;
			std::cout << "��������: " << it->second.filmDirector << std::endl;
			std::cout << "����: " << it->second.filmGenre << std::endl;
			std::cout << "�������: " << it->second.filmRating << std::endl;
			std::cout << "����: " << it->second.filmPrice << std::endl;
		}
	}
};


int main() {
	setlocale(LC_ALL, "Russian");

	Film film1; // �������� ����� 1
	film1.filmName = "���";
	film1.filmDirector = "�������� ������";
	film1.filmGenre = "����������";
	film1.filmRating = 7.6;
	film1.filmPrice = 5.50;

	Film film2; // �������� ����� 2
	film2.filmName = "���";
	film2.filmDirector = "����� �������";
	film2.filmGenre = "����������";
	film2.filmRating = 8.0;
	film2.filmPrice = 5.70;

	Film film3; // �������� ����� 3
	film3.filmName = "������";
	film3.filmDirector = "����� �������";
	film3.filmGenre = "�������";
	film3.filmRating = 8.1;
	film3.filmPrice = 5.60;

	VideoMarket allFilms; 
	allFilms.catalog[film1.filmName] = film1; // �������� ���������� �������
	allFilms.catalog[film2.filmName] = film2;
	allFilms.catalog[film3.filmName] = film3;

	while (true) {
		std::cout << "\n1 - ����� ������ �� ��������" << std::endl;
		std::cout << "2 - ����� ������ �� �����" << std::endl;
		std::cout << "3 - ����� ������ �� ���������" << std::endl;
		std::cout << "4 - ����� ������ ����������� ������(��) ������������� �����" << std::endl;
		std::cout << "5 - �������� ��� ������ � �������" << std::endl;
		std::cout << "6 - �������� �����" << std::endl;
		std::cout << "7 - ������� �����" << std::endl;
		std::cout << "8 - ���������� ������� �� ��������" << std::endl;
		std::cout << "0 - ����� �� ���������" << std::endl;
		std::cout << "\n��� �����: " << std::endl;
		int choise;
		std::cin >> choise;
		int endProgram = 0;
		std::cin.ignore();

		switch (choise) {
		case 1:
			allFilms.searchFilmName();
			break;
		case 2:
			allFilms.searchFilmGenre();
			break;
		case 3:
			allFilms.searchFilmDirector();
			break;
		case 4:
			allFilms.searchFilmGenreMostPopular();
			break;
		case 5:
			allFilms.showAllFilms();
			break;
		case 6:
			allFilms.addFilm();
			break;
		case 7:
			allFilms.deleteFilm();
			break;
		case 8:
			allFilms.sortFilmRating();
			break;
		case 0:
			endProgram = 1;
			break;
		default:
			std::cout << "��������� ����!" << std::endl;
			break;
		}

		if (endProgram == 1) {
			break;
		}
	}
	
	std::cout << std::endl;
	return 0;
}

