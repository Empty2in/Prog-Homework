#include "Point.h"
#include <iostream>
#include <cmath>

Point::Point()
{
	x = 0.0;
	y = 0.0;
}
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}
Point::Point(const Point& ob) 
{ 
	this->x = ob.x;
	this->y = ob.y;
}
void Point::setX(double x)
{ 
	this->x = x;
}
void Point::setY(double y)
{ 
	this->y = y;
}
double Point::getX() const
{ 
	return this->x; 
}
double Point::getY() const
{ 
	return this->y;
}
bool Point::isEqual(const Point& ob)
{ 
	if ((abs(this->x - ob.x) < epsilon) && (abs(this->y - ob.y) < epsilon))
	{
		return true;
	}
	return false;
}
double Point::getDistance(const Point& ob)
{ 
	return std::sqrt(pow((this->x - ob.x), 2) + pow((this->y - ob.y), 2));
}
void Point::move(double k)
{
	this->x += k;
	this->y += k;
}



