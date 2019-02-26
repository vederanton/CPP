// #25 homework

#include "pch.h"
#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

# define M_PI 3.14159265358979323846

class Shape {
public:
	virtual ~Shape() {}
	virtual double getArea() = 0;
	virtual void draw() = 0;
};

class Point {
	double x_;
	double y_;
	Point() {};
public:
	Point (double x, double y) :
		x_(x),
		y_(y)
	{}

	double getX_() const {
		return x_;
	}

	double getY_() const {
		return y_;
	}
};

class Triangle : public Shape {
	Point triangleA_;
	Point triangleB_;
	Point triangleC_;
public:
	Triangle(Point a, Point b, Point c) :
		triangleA_(a),
		triangleB_(b),
		triangleC_(c)
	{}

	double getArea() {
		double area = abs(0.5 * ((triangleA_.getX_() - triangleC_.getX_()) * (triangleB_.getY_() - triangleC_.getY_()) 
			- (triangleB_.getX_() - triangleC_.getX_()) * (triangleA_.getY_() - triangleC_.getY_())));
		return area;
	}

	void draw() {
		std::cout << "\nTriangle\n" << "Point A: (" << triangleA_.getX_() << " ; " << triangleA_.getY_() << ")\n" <<
			"Point B: (" << triangleB_.getX_() << " ; " << triangleB_.getY_() << ")\n" <<
			"Point C: (" << triangleC_.getX_() << " ; " << triangleC_.getY_() << ")\n";
		std::cout << "The area is: " << getArea() << std::endl;
	}
};

class Rectangle : public Shape {
	Point RectangleA_;
	Point RectangleB_;
public:
	Rectangle(Point a, Point b) :
		RectangleA_(a),
		RectangleB_(b)
	{}

	double getArea() {
		double a = abs(RectangleA_.getX_() - RectangleB_.getX_());
		double b = abs(RectangleA_.getY_() - RectangleB_.getY_());
		return a * b;
	}

	void draw() {
		std::cout << "\nRectangle\n" << "Point A: (" << RectangleA_.getX_() << " ; " << RectangleA_.getY_() << ")\n" <<
			"Point B: (" << RectangleB_.getX_() << " ; " << RectangleB_.getY_() << ")\n";
		std::cout << "The area is: " << getArea() << std::endl;
	}
};

class Ellipse : public Shape {
	Point EllipseA_;
	Point EllipseB_;
	Point EllipseCenter_;
public:
	Ellipse(Point a, Point b, Point c) :
		EllipseA_(a),
		EllipseB_(b),
		EllipseCenter_(c)
	{}

	double getArea() {
		double aFromX= abs(EllipseA_.getX_() - EllipseCenter_.getX_());
		double aFromY = abs(EllipseA_.getY_() - EllipseCenter_.getY_());;
		double a = sqrt(pow(aFromX, 2) + pow(aFromY, 2));
		double bFromX = abs(EllipseB_.getX_() - EllipseCenter_.getX_());
		double bFromY = abs(EllipseB_.getY_() - EllipseCenter_.getY_());;
		double b = sqrt(pow(bFromX, 2) + pow(bFromY, 2));
		return M_PI * a * b;
	}

	void draw() {
		std::cout << "\nEllipse\n" << "Point A: (" << EllipseA_.getX_() << " ; " << EllipseA_.getY_() << ")\n" <<
			"Point B: (" << EllipseB_.getX_() << " ; " << EllipseB_.getY_() << ")\n" <<
			"Point C: (" << EllipseCenter_.getX_() << " ; " << EllipseCenter_.getY_() << ")\n";
		std::cout << "The area is: " << getArea() << std::endl;
	}
};

class Circle : public Shape {
	Point CircleA_;
	Point CircleCenter_;
public:
	Circle(Point a, Point c) :
		CircleA_(a),
		CircleCenter_(c)
	{}

	double getArea() {
		double rFromX = abs(CircleA_.getX_() - CircleCenter_.getX_());
		double rFromY = abs(CircleA_.getY_() - CircleCenter_.getY_());;
		double r = sqrt(pow(rFromX, 2) + pow(rFromY, 2));
		return M_PI * pow(r, 2);
	}

	void draw() {
		std::cout << "\nCircle\n" << "Point A: (" << CircleA_.getX_() << " ; " << CircleA_.getY_() << ")\n" <<
			"Point B: (" << CircleCenter_.getX_() << " ; " << CircleCenter_.getY_() << ")\n";
		std::cout << "The area is: " << getArea() << std::endl;
	}
};

void drawShapes(std::vector<std::shared_ptr<Shape>>& shapes) {
	for (size_t i = 0; i < shapes.size(); ++i) {
		shapes[i]->draw();
	}
}

double getShapesArea(std::vector<std::shared_ptr<Shape>>& shapes) {
	double sumAreas = 0;
	for (size_t i = 0; i < shapes.size(); ++i) {
		sumAreas += shapes[i]->getArea();
	}
	return sumAreas;
}

int main() {
	Point p1(21.20, 93.12);
	Point p2(53.67, 11.79);
	Point p3(71.19, 26.78);

	std::shared_ptr<Shape> triangle(new Triangle(p1, p2, p3));
	std::shared_ptr<Shape> rectangle(new Rectangle(p3, p1));
	std::shared_ptr<Shape> ellipse(new Ellipse(p2, p3, p1));
	std::shared_ptr<Shape> circle(new Circle(p1, p3));

	std::vector<std::shared_ptr<Shape>> shapes;
	shapes.push_back(triangle);
	shapes.push_back(rectangle);
	shapes.push_back(ellipse);
	shapes.push_back(circle);

	drawShapes(shapes);
	std::cout << "\nThe sum of all the shapes of the vector is: " << getShapesArea(shapes) << std::endl;
}

/* OUTPUT:
Triangle
Point A: (21.2 ; 93.12)
Point B: (53.67 ; 11.79)
Point C: (71.19 ; 26.78)
The area is: 955.813

Rectangle
Point A: (71.19 ; 26.78)
Point B: (21.2 ; 93.12)
The area is: 3316.34

Ellipse
Point A: (53.67 ; 11.79)
Point B: (71.19 ; 26.78)
Point C: (21.2 ; 93.12)
The area is: 22852.8

Circle
Point A: (21.2 ; 93.12)
Point B: (71.19 ; 26.78)
The area is: 21677

The sum of all the shapes of the vector is: 48802
*/
