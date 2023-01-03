#include "ConnectedComponent.h"

ConnectedComponent::ConnectedComponent(const Graph &G)
{
    int size = G.V();
    marked = new bool[size];
    ids = new int[size];
    count = 0;

    for (int i = 0; i < size; i++)
    {
        marked[i] = false;
        ids[i] = i;
    }

    for (int v = 0; v < size; v++)
    {
        if (!marked[v])
        {
            dfs(G, v);
            count++;
        }
    }
}

ConnectedComponent::~ConnectedComponent()
{
    delete[] marked;
    delete[] ids;
}

int ConnectedComponent::getCount()
{
    return count;
}

int ConnectedComponent::id(int v)
{
    return ids[v];
}

bool ConnectedComponent::connected(int v, int w)
{
    return ids[v] == ids[w];
}

void ConnectedComponent::dfs(const Graph &G, int v)
{
    marked[v] = true;
    ids[v] = count;
    for (int w : G.adjacent(v))
    {
        if (!marked[w])
        {
            dfs(G, w);
        }
    }
}