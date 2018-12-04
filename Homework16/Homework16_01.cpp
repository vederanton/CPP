// Homework16_01.cpp.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include <iostream>
#include <string>


class Point {
	double x;
	double y;
public:
	Point() = default;
	explicit Point(double newX, double newY = 0) : 
		x(newX),
		y(newY)
	{}

	double getX() const {
		return x;
	}

	void setX(double xx) {
		x = xx;
	}

	double getY() const {
		return y;
	}

	void setY(double yy) {
		y = yy;
	}

	~Point() {}
};


void checkPoints(const Point one, const Point two) {
	if (one.getX() != two.getX() || one.getY() != two.getY()) {
		std::cout << "The points do not match." << std::endl;
	}
	else {
		std::cout << "Points are in one place." << std::endl;
	}
}


int main() {
	Point one(13.234, 45.237);
	Point two(13.234);
	checkPoints(one, two);

	return 0;
}

