#pragma once

struct Point {
	float x;
	float y;
};

class Line {
	float k;
	float b;
	static int countAllLines;
	static int countNowLines;
public:
	Line();
	explicit Line(const float, const float b = 0);
	Line(const Point, const Point);

	float getK() const;
	void setK(const float k);
	float getB() const;
	void setB(const float b);

	static int getCountAllLines();
	static int getCountNowLines();

	bool checkPointLine(const Point) const;
	bool checkPointLine(const float, const float) const;
	int checkPointPosition(const Point) const;

	virtual ~Line();
};

inline bool checkIntersection(const Line a, const Line b) {
	return a.getK() == b.getK() && a.getB() != b.getB() ? 0 : 1; // пересекаются ли прямые, 1-да, 0-нет.
}

inline Point calcIntersection(const Line a, const Line b) { // точка пересечения 2 пересекающихся прямых.
	Point point;
	point.x = (a.getB() - b.getB()) / (b.getK() - a.getK());
	point.y = (b.getK() * a.getB() - a.getK() * b.getB()) / (b.getK() - a.getK());
	return point;
}
