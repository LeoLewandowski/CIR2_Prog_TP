#include "Point.cpp"
#include <stdlib.h>
#include <iostream>

enum struct Color : unsigned char
{
	blue = 0,
	green = 1,
	orange = 2,
	brown = 3
};

struct Shape_cpp
{
	static unsigned global_count_;
	unsigned count_;
    Color color_;

	Shape_cpp() {
        color_ = Color::blue;
    }
	virtual float get_area() = 0;
	virtual void print_data() = 0;
	virtual ~Shape_cpp() = 0;
};

struct Rectangle : Shape_cpp
{
	Point2D A, B;

    Rectangle(const float &length, const float &width);
	float get_area() {
        return abs(A.getX() - B.getX()) * abs(A.getY() - B.getY());
    }
	void print_data() {
        std::cout << "Rectangle : (" << A.getX() << ", " << A.getY() << "), (" << B.getX() << ", " << B.getY() << ")";
    }
};

struct Triangle : Shape_cpp
{
	Point2D A, B, C;
	float get_area();
	void print_data();
	Triangle(const Point2D &newA, const Point2D &newB, const Point2D &newC);
};

struct Circle : Shape_cpp
{
	Point2D center;
	float radius;
	float get_area();
	void print_data();
	Circle(const Point2D &newCenter, const float &radius);
};