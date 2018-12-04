// Homework16_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


class Square {
	double sideOne = 0;
	double sideTwo = 0;
public:
	Square() = default;
	Square(double one, double two) :
			sideOne(one),
			sideTwo(two)
	{}
	explicit Square(double one) :
		sideOne(one),
		sideTwo(one)
	{}

	double getSideOne() const {
		return sideOne;
	}
	void setSideOne(const double one) {
		sideOne = one;
	}

	double getSideTwo() const {
		return sideTwo;
	}
	void setSideTwo(const double two) {
		sideTwo = two;
	}

	void getSquareArea() const {
		if (sideOne != sideTwo) {
			std::cout << "Error! The sides of the square are not equal. The calculation will not be." << std::endl;
			return;
		}
		else if (sideOne < 0 || sideTwo < 0) {
			std::cout << "Error! The sides of the square can not be less than zero. The calculation will not be." << std::endl;
			return;
		}
		std::cout << sideOne * sideTwo << std::endl;
	}

	~Square() {}
};

int main() {
	Square sq1(34);
	sq1.getSquareArea();

}

