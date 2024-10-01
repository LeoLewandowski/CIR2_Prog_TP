#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string const HOME = std::getenv("HOME");
    string const FILE_NAME = HOME + "/test.txt";

    ifstream buffer(FILE_NAME);

    // read entire file into string
    if (buffer)
    {
        int charCount = 0, wordCount = 0, lineCount = 0;

        char c, pc = 'a';
        while (buffer.get(c))
        {
            std::cout << c;
            charCount++;
            if (c == '\n')
                lineCount++;
            if (isspace(pc) && !isspace(c))
                wordCount++;
            pc = c;
        }

        std::cout << "\n\nFichier lu : " << FILE_NAME
                  << "\nNombre de caractères : " << charCount
                  << "\nNombre de mots : " << wordCount
                  << "\nNombre de lignes : " << lineCount;
    }
}