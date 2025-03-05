// = == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==
/// \name allPermutationWithSTL.cpp
/// \version 1.1 (2020.2021)
/// \brief Algorithme combinatoire récursif
//=========================================================================
/* Remplacez l’include suivant par tous les #include de la STL nécessaires si
vous utilisez Visual Studio */
#include <bits/stdc++.h>
#include "Permut.cpp"

using namespace std;

int main()
{
    vector<string> towns = {"Lille", "Dunkerque", "Paris"};
    permutations(towns, 0, towns.size() - 1);
    return 0;
}