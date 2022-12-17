#pragma once

struct point_t 
{
	double x;
	double y;

	point_t() : x(0.0), y(0.0) {}
	point_t(const double& x, const double& y) : x(x), y(y) {}
	point_t(const point_t& pt) : x(pt.x), y(pt.y) {}
};

struct rectangle_t
{
	double width;
	double height;
	point_t pos;

	rectangle_t() : width(0), height(0), pos(0, 0) {}
};