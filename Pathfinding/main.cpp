#include "Graph.cpp"

int main(int argc, char const *argv[])
{
    // Create graph & link nodes
    array<string, 7> towns = {"Stuttgart", "Rotterdam", "Bordeaux", "Lisbon", "New York", "New Orleans", "Los Angeles"};
    Graph g(towns);

    g.link(0, 1, 0, 50);
    g.link(0, 2, 0, 70);
    g.link(0, 3, 0, 40);

    g.link(1, 4, 0, 60);
    g.link(2, 4, 0, 40);
    g.link(2, 5, 0, 50);
    g.link(3, 5, 0, 30);

    g.link(4, 6, 0, 80);
    g.link(5, 6, 0, 70);

    g.print(false);

    cout << "Maximum flow : " << fordFulkerson(g.capacityMatrix, 0, 6);

    return 0;
}
