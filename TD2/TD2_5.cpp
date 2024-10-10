#include <iostream>
#include "Trajectory.hpp"

using namespace std;

int main(){

    // Generate 4 random points
    Point3D tab[] = {Point3D(), Point3D(), Point3D(), Point3D()};

    Trajectory t(tab, 4);

    cout << "\nPoint n°2 :";

    t.getPoint(1).print();

    t.print();

    t.addPoint(Point3D());

    t.print();

    return EXIT_SUCCESS;
}