#pragma once
#include "Shape.h"
class CompositeShape : public Shape
{
private:
	Shape** arr;
	int size;
public:

	CompositeShape();
	CompositeShape(const int& newSize);
	CompositeShape(const CompositeShape& otherShape);
	CompositeShape(CompositeShape&& otherShape) noexcept;
	~CompositeShape();

	void addShape(const int& number, Shape* newShape);
	void newSize(const int& newSize);

	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void move(const point_t& newPt) override;
	void move(const double& newX, const double& newY) override;
	void scale(const double& k) override;
	void scale(point_t& newCent, const double& k) override;
	std::string getName() const override;
	Shape* clone() override;
};

