#include "Rectangle.h"
#include <iostream>


//constructors
Rectangle::Rectangle() : pt_1(), pt_2() {}
Rectangle::Rectangle(const double& pt1X, const double& pt1Y, const double& pt2X, const double& pt2Y) : pt_1(pt1X, pt1Y), pt_2(pt2X, pt2Y) {};
Rectangle::Rectangle(const point_t& pt1, const point_t& pt2) : pt_1(pt1), pt_2(pt2) {};
Rectangle::Rectangle(const Rectangle& other) : pt_1(other.pt_1), pt_2(other.pt_2) {};

//setters
void Rectangle::setPt1(const double& x, const double& y)
{
	pt_1.x = x;
	pt_1.y = y;
};
void Rectangle::setPt1(const point_t& pt)
{
	pt_1.x = pt.x;
	pt_1.y = pt.y;
}
void Rectangle::setPt2(const double& x, const double& y)
{
	pt_2.x = x;
	pt_2.y = y;
}
void Rectangle::setPt2(const point_t& pt)
{
	pt_2.x = pt.x;
	pt_2.y = pt.y;
}

//getters
point_t Rectangle::getPt1() const
{
	return pt_1;
}
point_t Rectangle::getPt2() const
{
	return pt_2;
}

//methods by Shape
double Rectangle::getArea() const
{
	return std::abs(pt_1.x - pt_2.x) * std::abs(pt_1.y - pt_2.y);
}
rectangle_t Rectangle::getFrameRect() const
{
	rectangle_t rect;
	rect.width = std::abs(pt_1.x - pt_2.x);
	rect.height = std::abs(pt_1.y - pt_2.y);
	rect.pos = this->getCenter();
	return rect;
}
void Rectangle::move(const point_t& newPt)
{
	point_t center = getCenter();
	center.x -= newPt.x;
	center.y -= newPt.y;
	pt_1.x -= center.x;
	pt_1.y -= center.y;
	pt_2.x -= center.x;
	pt_2.y -= center.y;
}
void Rectangle::move(const double& newX, const double& newY)
{
	this->pt_1.x += newX;
	this->pt_1.y += newY;
	this->pt_2.x += newX;
	this->pt_2.y += newY;
}
std::string Rectangle::getName() const
{
	return "RECTANGLE";
}
Shape* Rectangle::clone()
{
	Shape* rectClone = new Rectangle(this->pt_1, this->pt_2);
	return rectClone;
}
void Rectangle::scale(const double& k)
{
	if (k <= 0)
	{
		std::cerr << "Uncorrect coefficient.";
		return;
	}
	point_t center = getCenter();
	rectangle_t rect = this->getFrameRect();
	double newWidth = rect.width * k;
	double newHeight = rect.height * k;
	this->pt_1.x = center.x - (newWidth / 2);
	this->pt_1.y = center.y - (newHeight / 2);
	this->pt_2.x = center.x + (newWidth / 2);
	this->pt_2.y = center.y + (newHeight / 2);
}
void Rectangle::scale(point_t& newCent, const double& k)
{
	if (k <= 0)
	{
		std::cerr << "Uncorrect coefficient.";
		return;
	}
	rectangle_t first_rect = this->getFrameRect();
	point_t first_center = first_rect.pos;
	point_t final_center(k * first_center.x - newCent.x, k * first_center.y - newCent.y);
	this->scale(k);
	this->move(final_center);
}

//add methods
point_t Rectangle::getCenter() const //!!!!
{
	point_t center;
	center.x = (pt_1.x + pt_2.x) / 2;
	center.y = (pt_1.y + pt_2.y) / 2;
	return center;
}
bool Rectangle::checkRectangle() const
{
	if ((pt_1.x == pt_2.x) || (pt_1.y == pt_2.y))
	{
		return false;
	}
	return true;
}

