#include <random>
#include "Point3D.hpp"
#include <iostream>

// fill X Y Z with random values (from -20 to 20)
Point3D::Point3D()
{
    std::random_device rd;                         // obtain a random number from hardware
    std::mt19937 gen(rd());                        // seed the generator
    std::uniform_int_distribution<> distr(-20, 20); // define the range


    x = distr(gen);
    y = distr(gen);
    z = distr(gen);
}

// fill XYZ values
Point3D::Point3D(const float &newx, const float &newy, const float &newz) : x(newx), y(newy), z(newz)
{
}

// Setters and getters
void Point3D::setXYZ(const float &newx, const float &newy, const float &newz)
{
    x = newx;
    y = newy;
    z = newz;
}

void Point3D::setX(const float &newx)
{
    x = newx;
}

void Point3D::setY(const float &newy)
{
    y = newy;
}

void Point3D::setZ(const float &newz)
{
    z = newz;
}

float Point3D::getX()
{
    return x;
}

float Point3D::getY()
{
    return y;
}

float Point3D::getZ()
{
    return z;
}

// other methods
void Point3D::print()
{
    std::cout << "\nPoint3D(" << x << ", " << y << ", " << z << ")";
}; // prints the coordinates of the point

float Point3D::distanceTo(const Point3D &otherPoint3D)
{
    return sqrt(pow(x - otherPoint3D.x, 2) + pow(y - otherPoint3D.y, 2) + pow(z - otherPoint3D.z, 2));
}