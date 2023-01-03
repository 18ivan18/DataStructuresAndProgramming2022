#include "TwoColor.h"

void TwoColor::dfs(const Graph &G, int v)
{
    marked[v] = true;
    for (int w : G.adjacent(v))
    {
        if (!marked[w])
        {
            color[w] = !color[v];
            dfs(G, w);
        }
        else if (color[w] == color[v])
        {
            isTwoColorable = false;
        }
    }
}

TwoColor::TwoColor(const Graph &G)
{
    int size = G.V();
    marked = new bool[size];
    color = new bool[size];
    for (int i = 0; i < size; i++)
    {
        marked[i] = false;
    }
    for (int s = 0; s < size; s++)
    {
        if (!marked[s])
        {
            dfs(G, s);
        }
    }
}

TwoColor::~TwoColor()
{
    delete[] marked;
    delete[] color;
}

bool TwoColor::isBipartite()
{
    return isTwoColorable;
}