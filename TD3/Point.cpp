#include <random>
#include <iostream>
class Point2D
{
protected:
    float x, y; // private attributes
public:
    // constuctors
    Point2D()
    {
        std::random_device rd;                          // obtain a random number from hardware
        std::mt19937 gen(rd());                         // seed the generator
        std::uniform_int_distribution<> distr(-20, 20); // define the range
        x = distr(gen);
        y = distr(gen);
    } // fill X Y Z with random values (from -20 to 20)
    Point2D(const float &newx, const float &newy)
    {
        x = newx;
        y = newy;
    }
    // Setters and getters
    void setXY(const float &newx, const float &newy)
    {
        x = newx;
        y = newy;
    }
    void setX(const float &newx)
    {
        x = newx;
    }
    void setY(const float &newy)
    {
        y = newy;
    }
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    // other methods
    void print()
    {
        std::cout << "\nPoint2D(" << x << ", " << y << ")";
    }
    float distanceTo(const Point2D &point)
    {
        return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
    }
};
class Point3D : Point2D
{
private:
    float z; // private attributes
public:
    // constuctors
    Point3D()
    {
        std::random_device rd;                         // obtain a random number from hardware
        std::mt19937 gen(rd());                        // seed the generator
        std::uniform_int_distribution<> distr(-20, 20); // define the range
        x = distr(gen);
        y = distr(gen);
        z = distr(gen);
    }
    Point3D(const float &newx, const float &newy, const float &newz) : Point2D(newx, newy)
    {
        z = newz;
    }
    // Setters and getters
    void setXYZ(const float &newx, const float &newy, const float &newz)
    {
        setXY(newx, newy);
        z = newz;
    }
    void setZ(const float &newz)
    {
        z = newz;
    }
    float getZ()
    {
        return z;
    }
    // other methods
    void print()
    {
        std::cout << "\nPoint3D(" << x << ", " << y << ", " << z << ")";
    }
    float distanceTo(const Point3D &point)
    {
        return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2) + pow(z - point.z, 2));
    }
};