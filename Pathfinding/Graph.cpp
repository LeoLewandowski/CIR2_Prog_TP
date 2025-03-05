#include <array>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/// @class Graph
/// @brief
/// @tparam S
template <size_t _SIZE>
class Graph
{
private:
    int _maxTownLength = 0;

public:
    array<array<int, _SIZE>, _SIZE> capacityMatrix;
    array<array<float, _SIZE>, _SIZE> costMatrix;

    array<string, _SIZE> nodes;

    Graph(array<string, _SIZE> nodes) : nodes(nodes)
    {
        for (int i = 0; i < _SIZE; i++)
        {
            for (int j = 0; j < _SIZE; j++)
            {
                unlink(i, j);
            }
            if (nodes[i].length() > _maxTownLength)
                _maxTownLength = nodes[i].length();
        }
    }
    ~Graph() {};

    void link(size_t a, size_t b, float cost, int capacity)
    {
        costMatrix[a][b] = cost;
        capacityMatrix[a][b] = capacity;
    }

    void unlink(size_t a, size_t b)
    {
        costMatrix[a][b] = INFINITY;
        capacityMatrix[a][b] = 0;
    }

    void print(bool whatToPrint)
    {
        cout << setw(_maxTownLength) << (whatToPrint ? "Costs" : "Capacities");
        for (int j = 0; j < _SIZE; j++)
        {
            cout << " | " << nodes[j];
        }
        cout << endl;

        for (int i = 0; i < _SIZE; i++)
        {
            cout << setw(_maxTownLength) << left << nodes[i];
            for (int j = 0; j < _SIZE; j++)
            {
                cout << " | " << setw(nodes[j].length()) << left << (whatToPrint ? costMatrix[i][j] : capacityMatrix[i][j]);
            }
            cout << endl;
        }
    }
};

template <size_t _SIZE>
bool breadthSearch(array<array<int, _SIZE>, _SIZE> &graphCapacities, size_t s, size_t t, array<int, _SIZE> &predecessors)
{
    array<bool, _SIZE> nodeVisited;
    queue<size_t> file;

    predecessors.fill(-1);
    nodeVisited.fill(false);

    file.push(s);
    nodeVisited[s] = true;

    while (!file.empty())
    {
        size_t u = file.front();
        file.pop();

        for (size_t v = 0; v < _SIZE; v++)
        {
            if (!nodeVisited[v] && graphCapacities[u][v] > 0)
            {
                file.push(v);
                predecessors[v] = u;
                nodeVisited[v] = true;
            }
        }
    }
    return nodeVisited[t];
}

template <size_t _SIZE>
int fordFulkerson(array<array<int, _SIZE>, _SIZE> &graphCapacities, size_t s, size_t t)
{
    array<array<int, _SIZE>, _SIZE> residual(graphCapacities);
    array<int, _SIZE> predecessors;
    predecessors.fill(-1);

    int maxFlow = 0;

    while (breadthSearch(residual, s, t, predecessors))
    {
        int bestFlow = __INT_MAX__;
        for (size_t v = t; predecessors[v] != s; v = predecessors[v])
        {
            auto u = predecessors[v];
            bestFlow = min(bestFlow, residual[u][v]);
        }

        maxFlow += bestFlow;

        for (size_t v = t; predecessors[v] != s; v = predecessors[v])
        {
            auto u = predecessors[v];
            residual[u][v] -= bestFlow;
            residual[v][u] += bestFlow;
        }
    }

    return maxFlow;
}