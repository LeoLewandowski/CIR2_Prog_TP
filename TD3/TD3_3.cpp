#include "Point.cpp"

// Vecteur en 2D pcq ratio
class Vecteur
{

private:
    float angle, magnitude;

public:
    Vecteur(Point2D A, Point2D B)
    {
        angle = atan2(A.getX() - B.getX(), A.getY() - B.getY());
        magnitude = A.distanceTo(B);
    }

    Vecteur(float newAngle, float newMagnitude)
    {
        angle = newAngle;
        magnitude = newMagnitude;
    }

    float getAngle(){
        return angle;
    }

    // Magnitude = norme
    float getMagnitude(){
        return magnitude;
    }

    // 2 vecteurs additionnés
    Vecteur operator +(const Vecteur v) {
        float x = cos(angle) * magnitude,
            y = sin(angle) * magnitude;
        
        float a = cos(v.angle) * v.magnitude,
            b = sin(v.angle) * v.magnitude;


        return Vecteur(Point2D(0,0), Point2D(x + a, y + b));
    }

    // Vecteur multiplié par un réel
    Vecteur operator *(const float x) {
        return Vecteur(angle, magnitude * x);
    }

    // Egalité des vecteurs
    bool operator ==(const Vecteur v) {
        return magnitude == v.magnitude
            && angle == v.angle;
    }
};

int main(){
    Vecteur u = Vecteur(0, 5);
    Vecteur v = u*3;
    std::cout << "V magnitude : " << v.getMagnitude() << std::endl;
    auto w = u + v;

    std::cout << "W magnitude : " << w.getMagnitude() << std::endl;
}