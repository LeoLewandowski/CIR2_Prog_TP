#include "Trajectory.hpp"

constexpr size_t numberOfPoints = 10;
class Trajectory
{
private:
    Point3D points[numberOfPoints];

public:
    // print the coordinates of all points
    void print()
    {
        for (int i = 0; i < numberOfPoints; i++)
        {
            points[i].print();
        }
    }

    // returns the reference of point n
    Point3D &getPoint(const int &n)
    {
        return points[n];
    }

    float getTotalDistance()
    {
        float distance = 0;
        for (int i = 0; i < numberOfPoints - 1; i++)
        {
            distance += points[i].distanceTo(points[i + 1]);
        }
        return distance;
    }
};