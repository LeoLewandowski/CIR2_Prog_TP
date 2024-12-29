#include <iostream>
#include <set>

using namespace std;

int main()
{
    // Crée un tableau d'entiers
    int a[] = {7, 4, 9, 1, 3, 4, 8, 2, 7, 5, 3, 6, 10, 4, 8, 10, 1, 2};
    // Insère la "tranche" de tableau entre les indexs 0 et 17 dans le set
    // Comme il ne peut y avoir 2 éléments identiques dans un set, il n'y a pas de duplicata de chiffres
    // d'où le fait qu'il n'en reste que 10 à la fin
    set<int> s(&a[0], &a[17]);
    // Crée un itérateur depuis le début du set
    set<int>::iterator p = s.begin();
    // Tant que l'itérateur n'est pas terminé
    while (p != s.end())
        // Affiche l'élément actuel de l'itérateur
        // L'itérateur passe tout seul à l'élément suivant, pas besoin de faire quoi que ce soit
        cout << *p++ << " ";
    return 0;
}