// Homework20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>


std::string bin(int num) { // возвращает строку, определяющую число в бинарном виде
	std::string str = "";
	while (num > 0) {
		str = (num & 1 == 1 ? "1" : "0") + str;
		num >>= 1;
	}
	return str;
}

std::string reverseStr(std::string& string) { // переворачивает строку для поиска нужных битов
	std::string str = "";
	for (int i = string.length() - 1; i >= 0; --i) {
		str = str + string[i];
	}
	return str;
}

int check711Bit(int number) { // проверяет 7 и 11 биты и если они 1, то биты 2 и 6 устанавливает 0
	std::string numberBit = bin(number);
	numberBit = reverseStr(numberBit);
	if (numberBit.length() >= 12 && numberBit[7] == '1' && numberBit[11] == '1') {	// >= 12 чтобы при попытке проверить
		number &= ~(1 << 6);							// число с кол-вом бит меньше 11 не было выхода из диапазона
		number &= ~(1 << 2);
	}
	return number;
}

void testBin(int number) {
	int number2 = check711Bit(number);
	std::cout << bin(number2) << std::endl;
}


int main() {
	testBin(2756);	// 101011000100
			// 101010000000

	testBin(3812);	// 111011100100
			// 111010100000

	testBin(2176);	// 100010000000
			// 100010000000

	testBin(4095);	// 111111111111
			// 111110111011

	testBin(2048);	// 100000000000
			// 100000000000

	testBin(2730);	// 101010101010
			// 101010101010

	testBin(65535);	// 1111111111111111
			// 1111111110111011

	testBin(255);	// 11111111
			// 11111111

	testBin(3008);	// 101111000000
			// 101110000000

	testBin(1);	// 1
			// 1

}
