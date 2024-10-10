#include "Shapes.cpp"
#include <iostream>

// Obligé d'utiliser ça car sqrt() n'est pas constexpr :(
double constexpr test(double x) {
    double curr = x, prev = 0;

    while (curr != prev) {
        prev = curr;
        curr = 0.5 * (curr + x / curr);
    }

    // curr = approximation de sqrt(x)
    return curr;
}

// Constexpr pour exécution à la compilation
constexpr double somme_inverses_carres(const int n)
{
    // Selon le problème de Bâle (https://fr.wikipedia.org/wiki/Probl%C3%A8me_de_B%C3%A2le)
    // On a sum(1/i²) pour i dans [1, +infini[ = pi²/6
    // On peut pas calculer réellent avec l'infini, mais on peut s'en approcher avec une limite
    // assez grande (ici, le paramètre n de la fonction)
    double sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += 1 / (float)(i * i);
    }

    return test(sum * 6);
}

int main()
{
    // Origine du repère
    Point2D origin = Point2D(0, 0);

    // Nombre total de points à placer au hasard dans le carré [-1,1] X [-1,1]
    int n = 100000;

    // Nombre total de points dans le disque x² + y² <= 1
    int m = 0;

    // On initialise le générateur de nombres aléatoires
    srand(time(NULL));

    // On génère n points au hasard dans le carré
    for (int i = 0; i < n; i++)
    {
        auto point = Point2D(((float)rand() / (RAND_MAX / 2)) - 1, ((float)rand() / (RAND_MAX / 2)) - 1);

        // Si le point est dans le cercle :
        if (point.distanceTo(origin) <= 1)
        {
            // Alors on ajoute à m
            m++;
        }
    }

    // Aire du carré : n = (2*r)² = 4*r²
    // Aire du cercle : m = pi*r²
    // m / n = (pi*r²) / (4*r²) = pi / 4
    // On en déduit donc : pi = 4 * m / n
    // Avec un assez grand nombre de points, on peut ainsi remplacer les aires par le nombre de points dispersés
    auto pi_monte_carlo = 4 * ((float)m / (float)n);

    // Code évalué à la compilation
    // Pi à partir de la somme des inverses des carrés
    constexpr auto pi_appprox_2 = somme_inverses_carres(20000);

    std::cout << "Monte-carlo : " << pi_monte_carlo << "\nSomme des carrés inverses : " << pi_appprox_2 << std::endl;
}