#include "Cycle.h"

void Cycle::dfs(const Graph &G, int v, int u)
{
    marked[v] = true;
    for (int w : G.adjacent(v))
    {
        if (!marked[w])
        {
            dfs(G, w, v);
        }
        else if (w != u)
        {
            cycle = true;
        }
    }
}

Cycle::Cycle(const Graph &G)
{
    int size = G.V();
    marked = new bool[size];
    cycle = false;
    for (int i = 0; i < size; i++)
    {
        marked[i] = false;
    }
    for (int v = 0; v < size; v++)
    {
        if (!marked[v])
        {
            dfs(G, v, v);
        }
    }
}

bool Cycle::hasCycle() { return cycle; }

Cycle::~Cycle() { delete[] marked; }
