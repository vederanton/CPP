// Homework15_01.cpp : Defines the entry point for the console application.

/* Создать структуры «Видеомагазин» и «Фильм». 
В структуре «Фильм» должны быть следующие поля: 
Название фильма, режиссер, жанр, рейтинг популярности, цена.

Реализовать следующие возможности : 
- поиск фильма по названию 
- поиск фильма по жанру 
- поиск фильма по режиссеру 
- поиск самого популярного фильма указанного жанра 
- показ всех фильмов, которые есть в магазине 
- добавление фильма в магазин 
- удаление фильма из магазина 
- сортировка фильмов по рейтингу */


#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <windows.h>


std::string RUS(const std::string&  DOS_string) // для корректного преобразования рус. символов с ввода с клавиатуры.
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
	std::map<std::string, Film> catalog; // ключом в дальнейшем будет выступать название фильма.

	void searchFilmName() { // поиск по названию фильма
		std::cout << "\nВведите название фильма для поиска: ";
		std::string tmp;
		std::getline(std::cin, tmp);
		if (catalog.count(RUS(tmp))) {
			auto it = catalog.find(RUS(tmp));
			std::cout << "\nНазвание фильма: " << it->second.filmName << std::endl;
			std::cout << "Режиссер: " << it->second.filmDirector << std::endl;
			std::cout << "Жанр: " << it->second.filmGenre << std::endl;
			std::cout << "Рейтинг: " << it->second.filmRating << std::endl;
			std::cout << "Цена: " << it->second.filmPrice << std::endl;
		}
		else {
			std::cout << "Фильм не найден!" << std::endl;
		}
	}

	void searchFilmGenre() { // поиск фильмов по жанру
		std::cout << "\nВведите жанр фильма для поиска: ";
		std::string tmp;
		std::getline(std::cin, tmp);
		int count = 0;
		for (auto it = catalog.begin(); it != catalog.end(); ++it) {
			if (it->second.filmGenre == RUS(tmp)) {
				std::cout << "\nНазвание фильма: " << it->second.filmName << std::endl;
				std::cout << "Режиссер: " << it->second.filmDirector << std::endl;
				std::cout << "Жанр: " << it->second.filmGenre << std::endl;
				std::cout << "Рейтинг: " << it->second.filmRating << std::endl;
				std::cout << "Цена: " << it->second.filmPrice << std::endl;
				++count;
			}
		}
		if (count == 0) {
			std::cout << "Ничего не найдено!" << std::endl;
		}
	}

	void searchFilmDirector() { // поиск фильмов по режиссеру
		std::cout << "\nВведите режиссера фильма для поиска: ";
		std::string tmp;
		std::getline(std::cin, tmp);
		int count = 0;
		for (auto it = catalog.begin(); it != catalog.end(); ++it) {
			if (it->second.filmDirector == RUS(tmp)) {
				std::cout << "\nНазвание фильма: " << it->second.filmName << std::endl;
				std::cout << "Режиссер: " << it->second.filmDirector << std::endl;
				std::cout << "Жанр: " << it->second.filmGenre << std::endl;
				std::cout << "Рейтинг: " << it->second.filmRating << std::endl;
				std::cout << "Цена: " << it->second.filmPrice << std::endl;
				++count;
			}
		}
		if (count == 0) {
			std::cout << "Ничего не найдено!" << std::endl;
		}
	}

	void searchFilmGenreMostPopular() { // поиск всех фильмов жанра с наивысшим рейтингом (если он одинаковый)
		std::cout << "\nВведите жанр для поиска фильма(ов) с наивысшим рейтингом: ";
		std::string tmp;
		std::getline(std::cin, tmp);
		std::string tmpFilmName = "";
		float tmpFilmRating = 0;
		for (auto it = catalog.begin(); it != catalog.end(); ++it) { // сначала ищем максимальный рейтинг жанра
			if (it->second.filmGenre == RUS(tmp)) {
				if (it->second.filmRating > tmpFilmRating) {
					tmpFilmRating = it->second.filmRating;
				}
			}
		}
		for (auto it = catalog.begin(); it != catalog.end(); ++it) { // а затем выводим все фильмы с макс. рейтингом данного жанра
			if (it->second.filmGenre == RUS(tmp)) {
				if (it->second.filmRating == tmpFilmRating) {
					std::cout << "\nНазвание фильма: " << it->second.filmName << std::endl;
					std::cout << "Режиссер: " << it->second.filmDirector << std::endl;
					std::cout << "Жанр: " << it->second.filmGenre << std::endl;
					std::cout << "Рейтинг: " << it->second.filmRating << std::endl;
					std::cout << "Цена: " << it->second.filmPrice << std::endl;
				}
			}
		}
	}

	void showAllFilms() { // показ всех фильмов в наличии
		std::cout << "\nФильмы в наличии:" << std::endl;
		int count = 0;
		for (auto it = catalog.begin(); it != catalog.end(); ++it) {
			std::cout << "\nНазвание фильма: " << it->second.filmName << std::endl;
			std::cout << "Режиссер: " << it->second.filmDirector << std::endl;
			std::cout << "Жанр: " << it->second.filmGenre << std::endl;
			std::cout << "Рейтинг: " << it->second.filmRating << std::endl;
			std::cout << "Цена: " << it->second.filmPrice << std::endl;
			++count;
		}
		if (count == 0) {
			std::cout << "Нет ни одного фильма!" << std::endl;
		}
	}

	void addFilm() { // добавление фильма в магазин
		std::cout << "\nВведите название фильма: ";
		std::string tmp = "";
		std::getline(std::cin, tmp);
		Film newFilm; // для создания новых фильмов
		catalog[RUS(tmp)] = newFilm;
		auto it = catalog.find(RUS(tmp));
		it->second.filmName = RUS(tmp);
		std::cout << "Режиссер: ";
		std::getline(std::cin, tmp);
		it->second.filmDirector = RUS(tmp);
		std::cout << "Жанр: ";
		std::getline(std::cin, tmp);
		it->second.filmGenre = RUS(tmp);
		std::cout << "Рейтинг: ";
		float tmp2 = 0;
		std::cin >> tmp2;
		it->second.filmRating = tmp2;
		std::cout << "Цена: ";
		std::cin >> tmp2;
		it->second.filmPrice = tmp2;
		std::cin.ignore(); // для удаления '\n' из потока
	}

	void deleteFilm() { // удаление фильма из магазина
		std::cout << "\nВведите название фильма для удаления: ";
		std::string tmp;
		std::getline(std::cin, tmp);
		if (catalog.count(RUS(tmp))) {
			catalog.erase(RUS(tmp));
		}
		else {
			std::cout << "Такого фильма не существует!" << std::endl;
		}

	}

	void sortFilmRating() { // показ фильмов по рейтингу
		std::multimap<float, std::string> tmpFilmRate; // multimap для быстрой сортировки рейтинга.
		for (auto it = catalog.begin(); it != catalog.end(); ++it) {
			tmpFilmRate.insert(std::pair<float, std::string> (it->second.filmRating, it->first)); // ключ - рейтинг, значение - название
		}
		for (auto it2 = tmpFilmRate.rbegin(); it2 != tmpFilmRate.rend(); ++it2) { // в обратном направлении
			auto it = catalog.find(it2->second);
			std::cout << "\nНазвание фильма: " << it->second.filmName << std::endl;
			std::cout << "Режиссер: " << it->second.filmDirector << std::endl;
			std::cout << "Жанр: " << it->second.filmGenre << std::endl;
			std::cout << "Рейтинг: " << it->second.filmRating << std::endl;
			std::cout << "Цена: " << it->second.filmPrice << std::endl;
		}
	}
};


int main() {
	setlocale(LC_ALL, "Russian");

	Film film1; // тестовый фильм 1
	film1.filmName = "Кин";
	film1.filmDirector = "Джонатан Бэйкер";
	film1.filmGenre = "Фантастика";
	film1.filmRating = 7.6;
	film1.filmPrice = 5.50;

	Film film2; // тестовый фильм 2
	film2.filmName = "Зои";
	film2.filmDirector = "Дрейк Доримус";
	film2.filmGenre = "Фантастика";
	film2.filmRating = 8.0;
	film2.filmPrice = 5.70;

	Film film3; // тестовый фильм 3
	film3.filmName = "Патрик";
	film3.filmDirector = "Менди Флетчер";
	film3.filmGenre = "Комедия";
	film3.filmRating = 8.1;
	film3.filmPrice = 5.60;

	VideoMarket allFilms; 
	allFilms.catalog[film1.filmName] = film1; // тестовое добавление фильмов
	allFilms.catalog[film2.filmName] = film2;
	allFilms.catalog[film3.filmName] = film3;

	while (true) {
		std::cout << "\n1 - Поиск фильма по названию" << std::endl;
		std::cout << "2 - Поиск фильма по жанру" << std::endl;
		std::cout << "3 - Поиск фильма по режиссеру" << std::endl;
		std::cout << "4 - Поиск самого популярного фильма(ов) определенного жанра" << std::endl;
		std::cout << "5 - Показать все фильмы в наличии" << std::endl;
		std::cout << "6 - Добавить фильм" << std::endl;
		std::cout << "7 - Удалить фильм" << std::endl;
		std::cout << "8 - Сортировка фильмов по рейтингу" << std::endl;
		std::cout << "0 - Выход из программы" << std::endl;
		std::cout << "\nВаш выбор: " << std::endl;
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
			std::cout << "Повторите ввод!" << std::endl;
			break;
		}

		if (endProgram == 1) {
			break;
		}
	}
	
	std::cout << std::endl;
	return 0;
}

