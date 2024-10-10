#include <iostream>

#define multiplier(a,b) ((a) * (b))

constexpr int multiplication(int x, int y){
    return x * y;
}

int main(void)
{
    int a, b;
    std::cout << "Entrez une valeur :" << std::endl;
    std::cin >> a;
    std::cout << "Entrez une autre valeur :" << std::endl;
    std::cin >> b;
    std::cout << multiplication(a + 1, b + 1) << std::endl;
}