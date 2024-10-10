#include <iostream>
#include "Trajectory.hpp"

using namespace std;

int main(){

    Point3D tab[] = {Point3D(1,0,4), Point3D(9,3,6), Point3D(2,7,3), Point3D(3,0,-4)};

    Trajectory t(tab, 4);

    cout << "\nPoint n°2 :";

    t.getPoint(1).print();

    t.print();

    t.addPoint(Point3D(5,-7,-9));

    t.print();

    return EXIT_SUCCESS;
}