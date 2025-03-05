#include <string>
#include <vector>
#include <iostream>

using namespace std;

void permutations(vector<string> &villes, int start, int end)
{
    if (start == end)
    {
        for (auto i : villes)
            cout << i << ' ';
        cout << endl;
    }
    else
    {
        // Permutations made
        for (int i = start; i <= end; i++)
        {
            // echange des deux lettres
            swap(villes[start], villes[i]);
            // Appel Recursif
            permutations(villes, start + 1, end);
            // On revient à la situation précédente
            swap(villes[start], villes[i]);
        }
    }
}