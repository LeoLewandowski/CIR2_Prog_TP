#include <string>
using namespace std;

class Ville
{
private:
    float x, y;
    string name;

public:
    Ville(float x, float y, string name) : name(name), x(x), y(y)
    {
    }
    ~Ville() {}
};
