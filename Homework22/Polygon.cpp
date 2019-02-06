#include "pch.h"
#include "Polygon.h"
#include <math.h>


Polygon::Polygon() {}

Polygon::Polygon(Coordinate coordinate) {	
	polygon_.push_back(coordinate);
}

Polygon::Polygon(double x, double y) {
	polygon_.push_back({ x, y });
}

Polygon::~Polygon() {}

std::vector<Coordinate> Polygon::getPolygon_() const {
	return polygon_;
}

int Polygon::getSizePolygon_() const {
	return polygon_.size();
}

void Polygon::addPolygon_(const Coordinate point) {
	for (size_t i = 0; i < polygon_.size(); ++i) {
		if (polygon_[i].x_ == point.x_ && polygon_[i].y_ == point.y_) {
			return;
		}
	}
	polygon_.push_back(point);
}

void Polygon::addPolygon_(const double x, const double y) {
	for (size_t i = 0; i < polygon_.size(); ++i) {
		if (polygon_[i].x_ == x && polygon_[i].y_ == y) {
			return;
		}
	}
	polygon_.push_back({ x, y });
}

void Polygon::delPolygon_(const Coordinate point) {
	for (size_t i = 0; i < polygon_.size(); ++i) {
		if (polygon_[i].x_ == point.x_ && polygon_[i].y_ == point.y_) {
			polygon_.erase(polygon_.begin() + i);
		}
		break;
	}
}

void Polygon::delPolygon_(const double x, const double y) {
	for (size_t i = 0; i < polygon_.size(); ++i) {
		if (polygon_[i].x_ == x && polygon_[i].y_ == y) {
			polygon_.erase(polygon_.begin() + i);
		}
		break;
	}
}

void Polygon::delPolygon_(const int index) {
	polygon_.erase(polygon_.begin() + index);
}

bool Polygon::operator==(const Polygon& obj) const {
	if (polygon_.size() != obj.polygon_.size()) {
		return 0;
	}
	for (size_t i = 0; i < polygon_.size(); ++i) {
		if (polygon_[i].x_ != obj.polygon_[i].x_ || polygon_[i].y_ != obj.polygon_[i].y_) {
			return 0;
		}
	}
	return 1;
}

bool Polygon::operator!=(const Polygon& obj) const {
	if (polygon_.size() != obj.polygon_.size()) {
		return 1;
	}
	for (size_t i = 0; i < polygon_.size(); ++i) {
		if (polygon_[i].x_ != obj.polygon_[i].x_ || polygon_[i].y_ != obj.polygon_[i].y_) {
			return 1;
		}
	}
	return 0;
}

Polygon::operator bool() const {
	if (polygon_.empty()) {
		return 0;
	}
	return 1;
}

void Polygon::movePoligon_(const double x, const double y) {
	for (size_t i = 0; i < polygon_.size(); ++i) {
		polygon_[i].x_ += x;
		polygon_[i].y_ += y;
	}
}

double Polygon::lengthSide(Coordinate one, Coordinate two) const {
	double xDiff, yDiff, lengthSide;
	xDiff = fabs(two.x_ - one.x_); // определяем катет по Х с положительным знаком
	yDiff = fabs(two.y_ - one.y_); // определяем катет по У положительным знаком
	return lengthSide = sqrt(pow(xDiff, 2) + pow(yDiff, 2));
}

double Polygon::calculateSides() const { // сумма длин всех сторон
	double sumSides = 0;
	for (auto it = polygon_.begin(); it != polygon_.end() - 1; ++it) { // сумма сторон для всех сторон кроме последней
		sumSides += lengthSide(*it, *(it + 1));
	}
	return sumSides += lengthSide(polygon_[0], polygon_[polygon_.size() - 1]); // прибавляем последнюю
}

double Polygon::calculateAverageSide() const {
	double averageSide = (this->calculateSides()) / (polygon_.size());
	return averageSide;
}

double Polygon::getAngle(int firstIndex, int thirdIndex) const { 
	double thirdSide = this->lengthSide(polygon_[firstIndex], polygon_[thirdIndex]);
	double a = lengthSide(polygon_[0], polygon_[1]);
	double cosA = thirdSide / (2 * a);
	double angle = acos(cosA);

	return angle;
}

bool Polygon::isRegular() const {
	double a = lengthSide(polygon_[0], polygon_[1]);
	if (a != calculateAverageSide()) {
		return 0;
	}
	double thirdSide, tmpAngle = 0, angle = 0;
	for (int i = 0; i < polygon_.size() - 2; ++i) {
		tmpAngle = angle;
		angle = this->getAngle(i, i + 2);
		if (i > 0 && tmpAngle != angle) {
			return 0;
		}
	}
	tmpAngle = angle;
	angle = this->getAngle(polygon_.size() - 2, 0);
	if (tmpAngle != angle) {
		return 0;
	}
	angle = this->getAngle(polygon_.size() - 1, 1);
	if (tmpAngle != angle) {
		return 0;
	}
	return 1;
}

