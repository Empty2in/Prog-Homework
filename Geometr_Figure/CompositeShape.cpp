#include "CompositeShape.h"

CompositeShape::CompositeShape() : arr(nullptr), size(0) {}
CompositeShape::CompositeShape(const int& newSize)
{
	this->size = newSize;
	this->arr = new Shape * [size];
	for (int i = 0; i < size; ++i)
	{
		this->arr[i] = nullptr;
	}
}
CompositeShape::CompositeShape(const CompositeShape& otherShape)
{
	this->size = otherShape.size;
	this->arr = new Shape * [size];
	for (int i = 0; i < size; ++i)
	{
		this->arr[i] = otherShape.arr[i]->clone();
	}
}
CompositeShape::CompositeShape(CompositeShape&& otherShape) noexcept
{
	this->arr = otherShape.arr;
	this->size = otherShape.size;
	otherShape.arr = nullptr;
	otherShape.size = 0;
}
CompositeShape::~CompositeShape()
{
	for (int i = 0; i < size; ++i)
		{
			delete[] arr[i];
		}
	delete[] arr;
}

//methods
void CompositeShape::addShape(const int& number, Shape* newShape)
{
	arr[number] = newShape;
}
bool CompositeShape::isEmpty(const int& k)const
{
	if (arr[k] == NULL)
	{
		return true;
	}
	return false;
}
void CompositeShape::newSize(const int& newSize)
{
	this->size = newSize;
}
//methods by Shape
double CompositeShape::getArea() const
{
	double ans = 0;
	for (int i = 0; i < size; ++i)
	{
		ans += arr[i]->getArea();
	}
	return ans;
}
rectangle_t CompositeShape::getFrameRect() const
{
	rectangle_t shapeRect = arr[0]->getFrameRect();
	if (size < 1)
	{
		return shapeRect;
	}
	point_t pos = shapeRect.pos;
	double height = shapeRect.height,
		width = shapeRect.width,
		right = pos.x + 0.5 * width,
		left = pos.x - 0.5 * width,
		top = pos.y + 0.5 * height,
		bottom = pos.y - 0.5 * height;
	for (int i = 1; i < size; i++)
	{
		shapeRect = arr[i]->getFrameRect();
		if (right < shapeRect.pos.x + shapeRect.width * 0.5)
		{
			right = shapeRect.pos.x + shapeRect.width * 0.5;
		}
		if (left > shapeRect.pos.x - shapeRect.width * 0.5)
		{
			left = shapeRect.pos.x - shapeRect.width * 0.5;
		}
		if (top < shapeRect.pos.y + shapeRect.height * 0.5)
		{
			top = shapeRect.pos.y + shapeRect.height * 0.5;
		}
		if (bottom > shapeRect.pos.y - shapeRect.height * 0.5)
		{
			bottom = shapeRect.pos.y - shapeRect.height * 0.5;
		}
	}
	shapeRect.width = right - left;
	shapeRect.height = top - bottom;
	shapeRect.pos.x = right - (width * 0.5);
	shapeRect.pos.y = top - (height * 0.5);
	return shapeRect;
}
void CompositeShape::move(const point_t& newPt)
{
	point_t pt_befor = getFrameRect().pos;
	move(pt_befor.x - newPt.x, pt_befor.y - newPt.y);
}
void CompositeShape::move(const double& newX, const double& newY)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i]->move(newX, newY);
	}
}
void CompositeShape::scale(const double& k)
{
	rectangle_t rect = this->getFrameRect();
	for (int i = 0; i < size; ++i)
	{
		arr[i]->scale(rect.pos, k);
	}
}
void CompositeShape::scale(point_t& newCent, const double& k)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i]->scale(newCent, k);
	}
}

std::string CompositeShape::getName() const
{
	return "COMPOSITE SHAPE";
}
Shape* CompositeShape::clone()
{
	return new CompositeShape(*this);
}