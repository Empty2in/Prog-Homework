#pragma once
#include "Shape.h"

class Concave : public Shape
{
private:
	point_t pt_1;
	point_t pt_2;
	point_t pt_3;
	point_t pt_4;
public:

	Concave();
	Concave(const double& pt1X, const double& pt1Y, const double& pt2X, const double& pt2Y, const double& pt3X, const double& pt3Y, const double& pt4X, const double& pt4Y);
	Concave(const point_t& pt1, const point_t& pt2, const point_t& pt3, const point_t& pt4);
	Concave(const Concave& other);

	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void move(const point_t& newPt) override;
	void move(const double& newX, const double& newY) override;
	void scale(const double& k) override;
	void scale(point_t& newCent, const double& k) override;
	std::string getName() const override;
	Shape* clone() override;

	bool checkConcave() const;
};

