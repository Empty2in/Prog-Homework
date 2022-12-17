#include "Concave.h"
#include <cmath>


Concave::Concave() : pt_1(0, 0), pt_2(0, 0), pt_3(0, 0), pt_4(0, 0) {}
Concave::Concave(const double& pt1X, const double& pt1Y, const double& pt2X, const double& pt2Y, const double& pt3X, const double& pt3Y, const double& pt4X, const double& pt4Y) : pt_1(pt1X, pt1Y), pt_2(pt2X, pt2Y), pt_3(pt3X, pt3Y), pt_4(pt4X, pt4Y) {}
Concave::Concave(const point_t& pt1, const point_t& pt2, const point_t& pt3, const point_t& pt4) : pt_1(pt1), pt_2(pt2), pt_3(pt3), pt_4(pt4) {}
Concave::Concave(const Concave& other) : pt_1(other.pt_1), pt_2(other.pt_2), pt_3(other.pt_3), pt_4(other.pt_4) {}


double Concave::getArea() const
{
	return 0.5 * std::abs(pt_1.x * pt_2.y + pt_2.x * pt_3.y + pt_3.x * pt_4.y + pt_4.x * pt_1.y - pt_2.x * pt_1.y - pt_3.x * pt_2.y - pt_4.x * pt_3.y - pt_1.x * pt_4.y);
}
rectangle_t Concave::getFrameRect() const
{
	double arrX[3]{ pt_1.x, pt_2.x, pt_3.x };
	double maxX = arrX[0];
	double minX = arrX[0];
	for (int i = 0; i < 3; ++i)
	{
		if (arrX[i] > maxX)
		{
			maxX = arrX[i];
		}
		if (arrX[i] < minX)
		{
			minX = arrX[i];
		}
	}
	double arrY[3]{ pt_1.y, pt_2.y, pt_3.y };
	double maxY = arrY[0];
	double minY = arrY[0];
	for (int i = 0; i < 3; ++i)
	{
		if (arrY[i] > maxY)
		{
			maxY = arrY[i];
		}
		if (arrY[i] < minY)
		{
			minY = arrY[i];
		}
	}
	rectangle_t rect;
	rect.width = maxX - minX;
	rect.height = maxY - minY;
	rect.pos.x = (maxX + minX) / 2;
	rect.pos.y = (maxY + minY) / 2;
	return rect;
}
void Concave::move(const point_t& newPt)
{
	double newX = newPt.x - pt_4.x;
	double newY = newPt.y - pt_4.y;
	this->move(newX, newY);
	
}
void Concave::move(const double& newX, const double& newY)
{
	pt_1.x += newX;
	pt_2.x += newX;
	pt_3.x += newX;
	pt_4.x += newX;
	pt_1.y += newY;
	pt_2.y += newY;
	pt_3.y += newY;
	pt_4.y += newY;
}
void Concave::scale(const double& k)
{
	point_t vect1(k*(pt_1.x - pt_4.x), k*(pt_1.y - pt_4.y));
	point_t vect2(k*(pt_2.x - pt_4.x), k*(pt_2.y - pt_4.y));
	point_t vect3(k*(pt_3.x - pt_4.x), k*(pt_3.y - pt_4.y));
	this->pt_1.x = vect1.x + pt_4.x;
	this->pt_1.y = vect1.y + pt_4.y;
	this->pt_2.x = vect2.x + pt_4.x;
	this->pt_2.y = vect2.y + pt_4.y;
	this->pt_3.x = vect3.x + pt_4.x;
	this->pt_3.y = vect3.y + pt_4.y;
}
void Concave::scale(point_t& newCent, const double& k)
{
	rectangle_t rect = this->getFrameRect();
	point_t firstCent = rect.pos;
	double vectX = k*firstCent.x - newCent.x;
	double vectY = k*firstCent.y - newCent.y;
	point_t finalCent(vectX + pt_4.x, vectY + pt_4.y);
	this->scale(k);
	this->move(finalCent);
}
std::string Concave::getName() const
{
	return "CONCAVE";
}
Shape* Concave::clone()
{
	Shape* ptr = new Concave(this->pt_1, this->pt_2, this->pt_3, this->pt_4);
	return ptr;
}

bool Concave::checkConcave() const
{
	double d1 = sqrt(pow((pt_2.x - pt_1.x), 2) + pow((pt_2.y - pt_1.y), 2));
	double d2 = sqrt(pow((pt_3.x - pt_2.x), 2) + pow((pt_3.y - pt_2.y), 2));
	double d3 = sqrt(pow((pt_3.x - pt_1.x), 2) + pow((pt_3.y - pt_1.y), 2));
	if (((d1 + d2) <= d3) || ((d1 + d3) <= d2) || ((d3 + d2) <= d1))
	{
		return false;
	}
	double a = (pt_1.x - pt_4.x) * (pt_2.y - pt_1.y) - (pt_2.x - pt_1.x) * (pt_1.y - pt_4.y);
	double b = (pt_2.x - pt_4.x) * (pt_3.y - pt_2.y) - (pt_3.x - pt_2.x) * (pt_2.y - pt_4.y);
	double c = (pt_3.x - pt_4.x) * (pt_1.y - pt_3.y) - (pt_1.x - pt_3.x) * (pt_3.y - pt_4.y);
	if (!((a * b > 0) && (a * c > 0) && (b * c) > 0))
	{
		return false;
	}
	if (!(pt_1.y <= pt_2.y) || !(pt_3.y <= pt_2.y) || !(pt_1.x <= pt_2.x))
	{
		return false;
	}
	return true;
}
