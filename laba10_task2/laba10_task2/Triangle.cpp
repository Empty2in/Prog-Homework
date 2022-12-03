#include "Triangle.h"
#include "Point.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : a(), b(), c() {};

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
Triangle::Triangle(const Triangle& ob)
{
	this->a = ob.a;
	this->b = ob.b;
	this->c = ob.c;
}

void Triangle::setA(const Point& a)
{
	this->a = a;
}
void Triangle::setB(const Point& b)
{
	this->b = b;
}
void Triangle::setC(const Point& c)
{
	this->c = c;
}

Point Triangle::getA() const
{
	return this->a;
}
Point Triangle::getB() const
{
	return this->b;
}
Point Triangle::getC() const
{
	return this->c;
}

bool Triangle::isTriangle() const
{
	double d1, d2, d3;
	d1 = a.getDistance(b);
	d2 = b.getDistance(c);
	d3 = c.getDistance(a);
	return ((d1 < (d2 + d3)) && (d2 < (d1 + d3)) && (d3 < (d2 + d1)));
}
bool Triangle::isEqual(const Triangle& ob)
{
	return (a.isEqual(ob.a) && b.isEqual(ob.b) && c.isEqual(ob.c));
}
double Triangle::getPerimeter()const
{
	double d1, d2, d3;
	d1 = a.getDistance(b);
	d2 = b.getDistance(c);
	d3 = c.getDistance(a);
	return d1 + d2 + d3;
}
void Triangle::move(double k)
{
	a.move(k);
	b.move(k);
	c.move(k);
}
double Triangle::getArea()const
{
	return 0.5 * std::abs(((b.getX() - a.getX()) * (c.getY() - a.getY())) - ((c.getX() - a.getX()) * (b.getY() - a.getY())));
}