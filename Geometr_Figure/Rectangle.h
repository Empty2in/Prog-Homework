#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	point_t pt_1;
	point_t pt_2;

public:


	Rectangle();
	Rectangle(const double& pt1X, const double& pt1Y, const double& pt2X, const double& pt2Y);
	Rectangle(const point_t& pt1, const point_t& pt2);
	Rectangle(const Rectangle& other);


	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void move(const point_t& newPt) override;
	void move(const double& newX, const double& newY) override;
	void scale(const double& k) override;
	void scale(point_t& newCent, const double& k) override;
	std::string getName() const override;
	Shape* clone() override;


	point_t getCenter() const;
	bool checkRectangle() const;

};