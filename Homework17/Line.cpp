#include "pch.h"
#include "Line.h"


int Line::countAllLines = 0;
int Line::countNowLines = 0;

Line::Line() {
	++countAllLines;
	++countNowLines;
}

Line::Line(const float kk, const float bb) :
	k(kk),
	b(bb)
{
	++countAllLines;
	++countNowLines;
}

Line::Line(const Point point1, const Point point2) {
	k = (point1.y - point2.y) / (point1.x - point2.x);
	b = point1.y - (k * point1.x);
	++countAllLines;
	++countNowLines;
}

float Line::getK() const {
	return k;
}

void Line::setK(const float kk) {
	k = kk;
}

float Line::getB() const {
	return this->b;
}

void Line::setB(const float bb) {
	this->b = bb;
}

int Line::getCountAllLines() {
	return countAllLines;
}

int Line::getCountNowLines() {
	return countAllLines;
}

bool Line::checkPointLine(const Point point) const {
	return k * point.x + b == point.y ? 1 : 0; // лежит ли точка на прямой, 1-лежит, 0-нет.
}

bool Line::checkPointLine(const float x, const float y) const {
	return k * x + b == y ? 1 : 0; // лежит ли точка на прямой, 1-лежит, 0-нет.
}

int Line::checkPointPosition(const Point point) const {
	float y = k * point.x + b;
	if (point.y > y) {
		return 1;
	}
	else if (point.y == y) {
		return 0;
	}
	return -1;
}

Line::~Line() {
	--countNowLines;
}
