#include "Trajectory.hpp"

using namespace std;

Trajectory::Trajectory(Point3D newPoints[], int nb)
{
    points = new Point3D[nb];
    size = nb;
    for (int i = 0; i < nb; i++)
    {
        points[i] = newPoints[i];
    }
}

// print the coordinates of all points
void Trajectory::print()
{
    std::cout << "\nListe des points : ";

    for (int i = 0; i < size; i++) points[i].print();

    std::cout << "\nLongueur totale : " << getTotalDistance() << endl;
}

// returns the reference of point n
Point3D &Trajectory::getPoint(const int &n)
{
    return points[n];
}

void Trajectory::addPoint(Point3D p)
{
    // On crée un nouvel array avec capacité de +1 par rapport à l'ancien
    Point3D *temp = new Point3D[size + 1];

    // Passe les points dans le nouvel array
    for (int i = 0; i < size; i++)
    {
        temp[i] = points[i];
    }

    // Ajoute le nouveau point au dernier emplacement
    temp[size] = p;

    // Supprime les anciens points
    delete[] points;

    // Définit le nouveau tableau comme étant le tableau de points
    points = temp;
}

float Trajectory::getTotalDistance()
{
    float distance = 0;
    for (int i = 1; i < size; i++)
    {
        distance += points[i - 1].distanceTo(points[i]);
    }
    return distance;
}

Trajectory::~Trajectory()
{
    // Supprime les points pour libérer la mémoire (le programme ne le fait pas tout seul)
    delete[] points;
}