#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // Chemin vers le fichier
    string const HOME = std::getenv("HOME");
    string const FILE_NAME = HOME + "/test.txt";

    ifstream buffer(FILE_NAME);

    // Lis l'entièreté du fichier dans le buffer
    if (buffer)
    {
        int charCount = 0, wordCount = 0, lineCount = 0, specificLetterCount = 0;

        // Map pour garder la mémoire des lettres spécifiques comptées
        auto test = map<char, int>();

        char c, pc = 'a';
        // Tant que l'on récupère des caractères depuis le buffer
        while (buffer.get(c))
        {
            specificLetterCount = 0;
            charCount++;
            if (c == '\n')
                lineCount++;
            if (isspace(pc) && !isspace(c))
                wordCount++;
            pc = c;
            if (test.count(c) > 0) {
                specificLetterCount = test.at(c);
                test.erase(c);
            } 
            specificLetterCount++;
            test.insert({c, specificLetterCount});
        }

        std::cout << "\n\nFichier lu : " << FILE_NAME
                  << "\nNombre de caractères : " << charCount
                  << "\nNombre de mots : " << wordCount
                  << "\nNombre de lignes : " << lineCount << std::endl;
        for(auto pair : test) {
            std::cout << pair.first << " : " << pair.second << std::endl;
        }
    }
}