#pragma once
class Point
{
private:
	double x;
	double y;
	double epsilon = 0.000000000;
public:
	Point(); 
	Point(double x, double y);
	Point(const Point& ob);
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;
	bool isEqual(const Point& ob);
	double getDistance(const Point& ob);
	void move(double k);
};

