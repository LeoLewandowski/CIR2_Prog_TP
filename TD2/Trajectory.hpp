#include "Point3D.hpp"
#include <iostream>

constexpr size_t numberOfPoints = 10;
class Trajectory
{
private:
    Point3D * points;
    int size;

public:
    Trajectory(Point3D newPoints[], int nb);

    void print();                    // print the coordinates of all points
    Point3D &getPoint(const int &n); // returns the reference of point n
    void addPoint(Point3D p);
    float getTotalDistance();

    ~Trajectory();
};