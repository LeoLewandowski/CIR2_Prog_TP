#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        x = 0;
        cout << "1";
    }
    A(int px)
    {
        x = px;
        cout << "2";
    }
    A(const A &pa)
    {
        x = pa.x;
        cout << "3";
    }

protected:
    int x;
};
class B
{
public:
    B(const A &pa = A()) : a(pa) { cout << "4"; }
    B(const A &pa, int py)
    {
        a = pa;
        y = py;
        cout << "5";
    }

protected:
    A a;
    int y;
};
class C : public B
{
public:
    C(int pz = 1)
    {
        z = pz;
        cout << "6";
    }
    C(A pa) : B(pa)
    {
        z = 0;
        cout << "7";
    }
    C(const B &pb) : B(pb), a(1)
    {
        z = 0;
        cout << "8";
    }

protected:
    A a;
    int z;
};
int main()
{
    cout << "-- A --\n";
    // Crée un élément de type A vide (équivalent à `A a0();`) : cf. ligne 6
    A a0;
    cout << endl;
    // Crée un élément de type A en lui passant un int comme paramètre : cf. ligne 11
    A a1(3);
    cout << endl;
    // Crée un élément de type A en lui passant un autre élément de classe A comme argument : cf. ligne 16
    A a2(a1);
    cout << endl;
    // Crée un élément A à partir d'un autre élément A. Equivaut à faire `A a3(a2);` : cf. ligne 16
    A a3 = a2; 
    cout << endl;
    // Copie les éléments de a1 dans a3. a1 est déjà créé, ainsi LE CODE N'APPELLE PAS DE CONSTRUCTEUR
    a3 = a1;
    cout << endl;
    cout << "-- B --\n";
    // Constructeur ligne 29
    B b0(a0, 3); 
    cout << endl;
    // Constructeur ligne 28
    B b1(a1);
    cout << endl;
    // Constructeur ligne 28 : le paramètre `pa` une valeur par défaut, donc il peut être omis.
    // C'est ce qui se passe ici, c'est comme si on faisait `B b2();`
    B b2;
    cout << endl;
    cout << "-- C --\n";
    // C est une classe basée sur B : on construit ainsi d'abord B, puis C, d'où l'ordre d'affichage des nombres
    // Constructeur ligne 43
    C c0;
    cout << endl;
    // Constructeur ligne 48
    C c1(a1);
    cout << endl;
    // Constructeur ligne 53
    C c2(b2);
    cout << endl;
}