#include "Point.cpp"

// Formule donnée par le prof
#define SHOELACE(x, y, x1, y1) (x*y1 - x1*y)

class Polygon {
    private:
    int len;
    Point2D vertices[20];
    public:
    Polygon(Point2D points[20], int size){
        for(int i = 0; i < size; i++){
            vertices[i] = points[i];
        }

        len = size;
    }

    // Shoelace formula
    float getArea() {
        float sum = 0;
        for(int i = 0; i < len - 1; i++){
            sum += SHOELACE(vertices[i].getX(), vertices[i].getY(), vertices[i+1].getX(), vertices[i+1].getY());
        }
        // On rajoute le point de fin et le point de départ, pour fermer la figure
        sum += SHOELACE(vertices[len-1].getX(), vertices[len-1].getY(), vertices[0].getX(), vertices[0].getY());
        return sum / 2;
    }
};

int main()
{
    Point2D tab1[4] = {Point2D(0,0), Point2D(1,0), Point2D(1,1), Point2D(0,1)};
    Point2D tab2[4] = {Point2D(0,0), Point2D(2,0), Point2D(2,1), Point2D(0,1)};
    Point2D tab3[3] = {Point2D(0,0), Point2D(1,0), Point2D(1,1)};
    
    Polygon carre = Polygon(tab1, 4);
    Polygon rectangle = Polygon(tab2, 4);
    Polygon triangle = Polygon(tab3, 3);


    float a = carre.getArea();

    std::cout << "Aire du carré : " << carre.getArea() << "\nAire du rectangle : " << rectangle.getArea() << "\nAire du triangle : " << triangle.getArea() << std::endl;
    return EXIT_SUCCESS;
}
