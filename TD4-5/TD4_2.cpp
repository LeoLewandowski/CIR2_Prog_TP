#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <limits>
#include <vector>

using namespace std;

class Fraction
{
private:
    int dividende, diviseur;

public:
    Fraction(int a, int b)
    {
        dividende = a;
        // Erreur si le diviseur est un 0
        if (b == 0)
            throw;
        diviseur = b;
    }

    bool isPositive()
    {
        return dividende < 0 && diviseur > 0 || diviseur < 0 && dividende > 0;
    }

    void print()
    {
        cout << dividende << "/" << diviseur;
    }

    bool operator==(Fraction other)
    {
        return dividende == other.dividende && diviseur == other.diviseur;
    }

    bool operator!=(Fraction other)
    {
        return dividende != other.dividende || diviseur != other.diviseur;
    }

    bool operator<(Fraction other)
    {
        return (double)dividende / (double)diviseur < (double)other.dividende / (double)other.diviseur;
    }

    bool operator>(Fraction other)
    {
        return (double)dividende / (double)diviseur > (double)other.dividende / (double)other.diviseur;
    }

    bool operator<=(Fraction other)
    {
        return *this == other || *this < other;
    }

    bool operator>=(Fraction other)
    {
        return *this == other || *this > other;
    }
};

int main(int argc, char const *argv[])
{
    // Chemin vers le fichier
    string const HOME = std::getenv("HOME");
    string const FILE_NAME = HOME + "/fracs.txt";

    ifstream buffer(FILE_NAME);

    string line;
    int dividende, diviseur;
    // Inutilisé ; sert juste à récupérer le slash qui divise les fractions
    char slash;

    multiset<Fraction> collection;
    vector<Fraction> vec;

    while (buffer >> dividende >> slash >> diviseur)
    {
        cout << dividende << " et " << diviseur << endl;
        collection.emplace(Fraction(dividende, diviseur));
    }

    for (auto p = collection.begin(); p != collection.end(); p++)
    {
        cout << "Fraction : ";
        Fraction f = (*p);
        f.print();
        cout << endl;
    }

    Fraction max = Fraction(-std::numeric_limits<int>::infinity(), 1);

    return 0;
}
