// Homework22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Polygon.h"

std::ostream& operator<<(std::ostream& os, const Polygon& obj) { // почему-то в .h и в .cpp не работает.
	os << "Number of angles: " << obj.getSizePolygon_() << std::endl;
	os << "Regular: " << obj.isRegular() << std::endl;
	os << "The sum of the lengths of all sides: " << obj.calculateSides() << std::endl;
	os << "Average side length: " << obj.calculateAverageSide() << std::endl;
	return os;
}

int main() {
	Coordinate c1 = { 12.3, 23.1 };
	Polygon pol(c1);

	std::vector<Coordinate> p1 = pol.getPolygon_();
	std::cout << p1[0].x_ << " " << p1[0].y_ << std::endl; // 12.3 23.1

	if (pol) {
		std::cout << "OK operator bool for no empty" << std::endl; // ok
	} 
	Polygon pol2;
	if (pol2 == 0) {
		std::cout << "OK operator bool for empty" << std::endl; // ok
	}

	if (pol == pol2) {
		std::cout << "ERROR operator ==" << std::endl;
	}
	else {
		std::cout << "OK operator ==" << std::endl; // ok
	}

	pol.movePoligon_(100.0, 100.0);
	p1 = pol.getPolygon_();
	std::cout << p1[0].x_ << " " << p1[0].y_ << std::endl; // 112.3 123.1

	pol.addPolygon_(23.1, 34.4); // ok
	std::cout << pol.calculateSides() << std::endl; // 251.59
	std::cout << pol.calculateAverageSide() << std::endl; // 251.59

	pol.addPolygon_(24.0, 45.3);
	pol.addPolygon_(25.0, 46.3);
	pol.addPolygon_(15.0, 36.3);
	std::cout << pol.isRegular() << std::endl; // 0
	
	Polygon pol3(2.0, 4.0);
	pol3.addPolygon_(5.0, 7.0);
	pol3.addPolygon_(8.0, 4.0);
	pol3.addPolygon_(5.0, 1.0);
	std::cout << pol3.isRegular() << std::endl; // 1

	std::cout << pol3 << std::endl;
}
