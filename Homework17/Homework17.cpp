// Homework17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Line.h"
#include "PrettyPrint.h"
#include <iostream>


int main() {
	Point one{ 2, 0 };
	Point two{ 0, -2 };
	Line line1 = Line(one, two);

	Line line2;
	line2.setK(12.33);
	line2.setB(22.54);

	Line line3;
	line3.setK(12.33);
	line3.setB(13.54);

	std::cout << "k1 = " << line1.getK() << " ; b1 = " << line1.getB() << std::endl;
	std::cout << "k2 = " << line2.getK() << " ; b2 = " << line2.getB() << std::endl;
	std::cout << checkIntersection(line1, line2) << std::endl;

	std::cout << "k3 = " << line3.getK() << " ; b3 = " << line3.getB() << std::endl;
	std::cout << checkIntersection(line2, line3) << std::endl;

	std::cout << line3.checkPointLine({ 23, 45 }) << std::endl;
	std::cout << line1.checkPointLine({ 1.34, 2.12 }) << std::endl;
	std::cout << line3.checkPointLine(23, 45) << std::endl;
	std::cout << line1.checkPointLine(1.34, 2.12) << std::endl;

	std::cout << line3.checkPointPosition({ 1.34, -1000 }) << std::endl;

	Point one1{ 0, 0 };
	Point two2{ -1, 1 };
	Line line4 = Line(one1, two2);
	Point inter = calcIntersection(line1, line4);
	std::cout << "x = " << inter.x << " y = " << inter.y << std::endl;

	std::string a = "aba";
	std::string b = "caba";
	PrettyPrint aAndB;
	std::string c = aAndB.concString(a, b);	
	std::cout << c << std::endl;

	c = aAndB.replaceAO(c);
	std::cout << c << std::endl;

	c = aAndB.upend(c);
	std::cout << c << std::endl;

}

