#pragma once
#include <vector>

struct Coordinate {
	double x_ = 0;
	double y_ = 0;
};

class Polygon {
	std::vector<Coordinate> polygon_;
public:
	Polygon();
	Polygon(Coordinate);
	Polygon(double, double);
	virtual ~Polygon();

	std::vector<Coordinate> getPolygon_() const;
	int getSizePolygon_() const;

	void addPolygon_(const Coordinate);
	void addPolygon_(const double, const double);
	void delPolygon_(const Coordinate);
	void delPolygon_(const double, const double);
	void delPolygon_(const int);

	bool operator==(const Polygon&) const;
	bool operator!=(const Polygon&) const;
	operator bool() const;

	void movePoligon_(const double, const double);
	double lengthSide(Coordinate, Coordinate) const;
	double calculateSides() const;
	double calculateAverageSide() const;
	double getAngle(int, int) const;
	bool isRegular() const;
};