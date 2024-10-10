#include <iostream>
#include <iomanip>

using std::right;
using std::left;
using std::cout;
using std::cin;
using std::setw;

// Table de multiplication entière, pour nombres de 1 à 10
void whole_table()
{
    cout << "      ";
    // setw(x) : fait en sorte que le prochain truc affiché prenne l'espace de x caractères, peu importe ce qui est affiché
    for(int i = 1; i <= 10; i++) cout << setw(4) << left << i;
    cout << "\n    +----------------------------------------\n";
    for(int y = 1; y <= 10; y++) {
        cout << setw(3) << y << " | ";
        for(int x = 1; x <= 10;  x++){
            cout << setw(4) << x * y;
        }
        cout << std::endl;
    }
}

// Table de multiplication d'un chiffre donné
void partial_table()
{
    int nb;
    cout << "Veuillez donner un chiffre (Entre 1 et 9 inclus) : ";
    cin >> nb;
    
    if(nb < 1 || nb > 9){
        cout << "Nombre invalide !";
        return;
    }
    
    for(int i = 1; i <= 10; i++) cout << setw(3) << i;
    cout << '\n';
    for(int i = 1; i <= 10; i++) cout << setw(3) << i * nb;
}

int main(int argc, char const *argv[])
{
    int opt;
    while (true)
    {
        cout << "\nChoisissez une option :\n - 1 : Table de multiplication complète\n - 2 : Table de multiplication d'un nombre\n - 3 : Quitter\n > ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            whole_table();
            break;
        case 2:
            partial_table();
            break;
        case 3:
            return 0;
        default:
            cout << "Cette option est invalide !\n\n";
            break;
        }
    }
}

