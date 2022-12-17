#include "Shape.h"

std::ostream& operator << (std::ostream& os, const Shape* shape)
{
	rectangle_t rect = shape->getFrameRect();
	point_t center = rect.pos;
	point_t ptRight, ptLeft;
	ptRight.x = round((center.x + rect.width / 2) * 10 ) / 10;
	ptRight.y = round((center.y + rect.height / 2) * 10) / 10;
	ptLeft.x = round((center.x - rect.width / 2) * 10) / 10;
	ptLeft.y = round((center.y - rect.height / 2) * 10) / 10;
	os << "The Name: " << shape->getName() << " Area: " << std::round((shape->getArea()*10))/10;
	os << " Lower left corner: (" << ptLeft.x << "; " << ptLeft.y << ")";
	os << " Lower right corner: (" << ptRight.x << "; " << ptRight.y << ")" << "\n";
	return os;
}
bool Shape::operator < (const Shape& other)
{
	return (this->getArea() < other.getArea());
}