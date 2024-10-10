#include <random>
#include <iostream>
#include "Point3D.hpp"

int main(){
    Point3D A;
    Point3D B(1, 2, 4);
    
    A.print();
    B.print();

    A.setXYZ(3, 5, 2);
    B.setX(7);
    B.setY(9);
    B.setZ(12);

    std::cout << "\nNew values :";

    A.print();
    B.print();

    std::cout << "\nGetting values for point A : " << A.getX() << ", " << A.getY() << ", " << A.getZ();

    std::cout << "\nDistance between points A and B : " << A.distanceTo(B) << "\n\n";

    return EXIT_SUCCESS;
}