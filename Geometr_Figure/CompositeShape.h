#pragma once
#include "Shape.h"
class CompositeShape : public Shape
{
private:
	
public:
	Shape** arr;
	int size;
//constructors
	CompositeShape();
	CompositeShape(const int& newSize);
	CompositeShape(const CompositeShape& otherShape);
	CompositeShape(CompositeShape&& otherShape) noexcept;
	~CompositeShape();

//methods
	void addShape(const int& number, Shape* newShape);
	bool isEmpty(const int& k)const;
	void newSize(const int& newSize);

//methods by Shape
	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void move(const point_t& newPt) override;
	void move(const double& newX, const double& newY) override;
	void scale(const double& k) override;
	void scale(point_t& newCent, const double& k) override;
	std::string getName() const override;
	Shape* clone() override;
};

