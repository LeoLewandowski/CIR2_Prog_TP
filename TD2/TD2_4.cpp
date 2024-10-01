#include <random>
#include <iostream>

class Point3D
{
private:
    float x, y, z; // private attributes
public:
    // constructors

    // fill X Y Z with random values (from 0 to 100)
    Point3D()
    {
        std::random_device rd;                         // obtain a random number from hardware
        std::mt19937 gen(rd());                        // seed the generator
        std::uniform_int_distribution<> distr(25, 63); // define the range

        x = gen();
        y = gen();
        z = gen();
    }

    // fill XYZ values
    Point3D(const float &newx, const float &newy, const float &newz)
    {
        x = newx;
        y = newy;
        z = newz;
    }

    // Setters and getters
    void setXYZ(const float &newx, const float &newy, const float &newz)
    {
        x = newx;
        y = newy;
        z = newz;
    }
    void setX(const float &newx)
    {
        x = newx;
    }
    void setY(const float &newy)
    {
        y = newy;
    }
    void setZ(const float &newz)
    {
        z = newz;
    }
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    float getZ()
    {
        return z;
    }
    // other methods
    void print()
    {
        std::cout << "\nPoint3D(" << x << ", " << y << ", " << z << ")";
    }; // prints the coordinates of the point
    float distanceTo(const Point3D &otherPoint3D)
    {
        return sqrt(pow(x - otherPoint3D.x, 2) + pow(y - otherPoint3D.y, 2) + pow(z - otherPoint3D.z, 2));
    }
};

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