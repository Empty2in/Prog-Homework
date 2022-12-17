#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "base-types.h"

class Shape
{
public:
	virtual ~Shape() = default;
	virtual double getArea() const = 0;
	virtual rectangle_t getFrameRect() const = 0;
	virtual void move(const point_t& newPt) = 0;
	virtual void move(const double& newX, const double& newY) = 0;
	virtual void scale(const double& k) = 0;
	virtual void scale(point_t& newCent, const double& k) = 0;
	virtual std::string getName() const = 0; 
	virtual Shape* clone() = 0;
	friend std::ostream& operator << (std::ostream& os, const Shape* shape);
	bool operator < (const Shape& other);

};
