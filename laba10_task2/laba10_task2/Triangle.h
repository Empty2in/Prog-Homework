#pragma once
#include "Point.h"
class Triangle
{
private:
	Point a;
	Point b;
	Point c;
public:
	Triangle();
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle& ob);

	void setA(const Point& a);
	void setB(const Point& b);
	void setC(const Point& b);

	Point getA() const;
	Point getB() const;
	Point getC() const;

	bool isTriangle() const;
	bool isEqual(const Triangle& ob);
	double getPerimeter()const;
	void move(double k);
	double getArea()const;
};

