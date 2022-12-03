#include "Triangle.h"
#include "Point.h"
#include <iostream>
#include <cmath>

bool isEqualSquare(const Triangle& tri1, const Triangle& tri2);
bool input_pt(std::istream& cin, Point& point);
void output_pt(std::ostream& cout, Point& point);
bool input_tri(std::istream& cin, Triangle& triangle);
void output_tri(std::ostream& cout, Triangle& triangle);


int main() {


	Triangle tri_test, tri_test2, tri1, tri2;
	try
	{
		std::cout << "1. Testing class methods\n\n";
		std::cout << "\t1.1 Enter the triangle: ";
		if (!input_tri(std::cin, tri_test))
		{
			throw std::exception("input real number");
		}
		output_tri(std::cout, tri_test);
		std::cout << "\t1.2 Is this a triangle?\n";
		if (tri_test.isTriangle())
		{
			std::cout << "\t\tAnswer: YES\n\n";
		}
		else
		{
			std::cout << "\t\tAnswer: NO\n\n";
		}
		std::cout << "\t1.3 Move triangle\n";
		double k;
		std::cout << "\t\tEnter the number for move: ";
		std::cin >> k;
		tri_test.move(k);
		output_tri(std::cout, tri_test);
		std::cout << "\t1.4 Perimetr of triangle\n";
		std::cout << "\t\tPerimtr is: " << tri_test.getPerimeter() << "\n\n";
		std::cout << "\t1.5 Is two triangle equal?\n";
		std::cout << "\t\tEnter the triangle two: ";
		if (!input_tri(std::cin, tri_test2))
		{
			throw std::exception("input real number");
		}
		if (tri_test.isEqual(tri_test2))
		{
			std::cout << "\t\tThis triangles is equal\n\n";
		}
		else
		{
			std::cout << "\t\tThis triangles isn't equal\n\n";
		}

		std::cout << "2. Testing class functions\n\n";
		std::cout << "\tEnter first triangle: ";
		if (!input_tri(std::cin, tri1))
		{
			throw std::exception("input real number");
		}
		if (!tri1.isTriangle())
		{
			throw std::exception("input real number");
		}
		std::cout << "\tEnter second triangle: ";
		if (!input_tri(std::cin, tri2))
		{
			throw std::exception("input real number");
		}
		if (!tri2.isTriangle())
		{
			throw std::exception("input real number");
		}
		if (isEqualSquare(tri1, tri2))
		{
			std::cout << "\tThe areas are equal";
		}
		else
		{
			std::cout << "\tAreas are not equal";
		}
		std::cout << "\nTrianglt 1: ";
		output_tri(std::cout, tri1);
		std::cout << "Trianglt 2: ";
		output_tri(std::cout, tri2);
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		exit(-1);
	}
	
	return 0;

}

bool isEqualSquare(const Triangle& tri1, const Triangle& tri2)
{
	if (tri1.getArea() == tri2.getArea())
	{
		return true;
	}
	return false;
}

void output_tri(std::ostream& cout, Triangle& triangle)
{
	Point coor;
	cout << "\ta ";
	coor = triangle.getA();
	output_pt(cout, coor);
	cout << "  b ";
	coor = triangle.getB();
	output_pt(cout, coor);
	cout << "  c ";
	coor = triangle.getC();
	output_pt(cout, coor);
	cout << "\n\n";
}

bool input_tri(std::istream& cin, Triangle& triangle)
{
	Point coor;
	if (!input_pt(cin, coor))
	{
		return false;
	}
	triangle.setA(coor);
	if (!input_pt(cin, coor))
	{
		return false;
	}
	triangle.setB(coor);
	if (!input_pt(cin, coor))
	{
		return false;
	}
	triangle.setC(coor);
	return true;
}

bool input_pt(std::istream& cin, Point& point)
{
	double buf = 0;
	cin >> buf;
	if (cin.fail())
	{
		return false;
	}
	point.setX(buf);
	cin >> buf;
	if (cin.fail())
	{
		return false;
	}
	point.setY(buf);
	return true;
}

void output_pt(std::ostream& cout, Point& point)
{
	cout << "(" << point.getX() << ", " << point.getY() << ")";
}