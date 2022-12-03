#include "Point.h"
#include <iostream>
#include <cmath>

bool isPointInCircle(Point point, double radius);
bool input(std::istream& cin, Point& point);
void output(std::ostream& cout, Point& point);
bool endInput(Point& point);
double getStartDistance(Point& point);

int main() {

	Point pt_test1, pt_test2, pt_func, pt1, pt_ans;
	double x, y;
	double minim_distance;

	try
	{
		std::cout << "1. Testing class methods\n\n";
		std::cout << "\tInput coordinates for point_1 (setX, setY): ";
		if ((!input(std::cin, pt_test1)))
		{
			throw std::exception("input real number");
		}
		std::cout << "\tInput coordinates for point_2 (setX, setY): ";
		if ((!input(std::cin, pt_test2)))
		{
			throw std::exception("input real number");
		}
		std::cout << "\n\t1.1 Output coordinates (getX, getY)\n";
		std::cout << "\t\tpoint1_x = " << pt_test1.getX() << " " << "\tpoint1_y = " << pt_test1.getY() << "\n";
		std::cout << "\t\tpoint2_x = " << pt_test2.getX() << " " << "\tpoint2_y = " << pt_test2.getY() << "\n\n";
		std::cout << "\t1.2 Checking whether the points are equal (isEqual)\n";
		if (pt_test1.isEqual(pt_test2))
		{
			std::cout << "\t\tThe points are equal\n\n";
		}
		else
		{
			std::cout << "\t\tThe points aren't equal\n\n";
		}
		std::cout << "\t1.3 Calculating the distance between points (getDistance)\n";
		std::cout << "\t\tDistance: " << pt_test1.getDistance(pt_test2) << "\n\n";
		std::cout << "\t1.4 Moving a point by a specified number of positions (move)\n";
		double k;
		std::cout << "\t\tInput a specified number of positions: ";
		std::cin >> k;
		if (!std::cin)
		{
			throw std::exception("input real number");
		}
		pt_test1.move(k);
		std::cout << "\t\tpoint1_x = " << pt_test1.getX() << " " << "\tpoint1_y = " << pt_test1.getY() << "\n\n";

		std::cout << "2. Testing functions\n\n";
		std::cout << "\t\t2.1 Input and output of point coordinates: ";
		if ((!input(std::cin, pt_test1)))
		{
			throw std::exception("input real number");
		}
		output(std::cout, pt_test1);
		std::cout << "\t2.2 Does the point lie in a circle of a given radius\n";
		double radius;
		std::cout << "\t\tEnter the radius: ";
		std::cin >> radius;
		if (!std::cin)
		{
			throw std::exception("input real number");
		}
		if (isPointInCircle(pt_func, radius))
		{
			std::cout << "\t\tThe point lies inside the circle\n\n";
		}
		else
		{
			std::cout << "\t\tThe point don't lies inside the circle\n\n";
		}

		std::cout << "3. Determine the coordinates of the point closest to the origin\n\n";
		std::cout << "Enter a few dots and end the input with a dot 0 0\n";
		if ((!input(std::cin, pt1)))
		{
			throw std::exception("input real number");
		}
		minim_distance = getStartDistance(pt1);
		while (endInput(pt1))
		{
			if (getStartDistance(pt1) < minim_distance)
			{
				minim_distance = getStartDistance(pt1);
				pt_ans = pt1;
			}
			if ((!input(std::cin, pt1)))
			{
				throw std::exception("input real number");
			}
		}
		std::cout << "\nMinimal distance: " << minim_distance;
		output(std::cout, pt_ans);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		exit(-1);
	}
	
	return 0;
}
bool isPointInCircle(Point point, double radius)
{
	return getStartDistance(point) <= radius;
}
bool input(std::istream& cin, Point& point)
{
	double coord = 0;
	cin >> coord;
	if (cin.fail())
	{
		return false;
	}
	point.setX(coord);
	cin >> coord;
	if (cin.fail())
	{
		return false;
	}
	point.setY(coord);
	return true;
}
void output(std::ostream& cout, Point& point)
{
	cout << "\t\tCoordinates: (" << point.getX() << ", " << point.getY() << ")\n";
}
bool endInput(Point& point) 
{
	if ((point.getX() == point.getY()) && (point.getX() == 0.0))
	{
		return false;
	}
	return true;
}
double getStartDistance(Point& point)
{
	double distance;
	distance = sqrt(pow(point.getX(), 2) + pow(point.getY(), 2));
	return distance;
}