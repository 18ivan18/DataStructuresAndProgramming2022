#include "ConnectedComponents.h"

void ConnectedComponents::dfs(const Digraph &G, int v)
{
    visited[v] = true;
    ids[v] = count;
    for (int w : G.adj(v))
    {
        if (!visited[w])
        {
            dfs(G, w);
        }
    }
}

ConnectedComponents::ConnectedComponents(const Digraph &G)
{
    int n = G.V();
    visited = new bool[n];
    ids = new int[n];
    count = 0;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(G, i);
            count++;
        }
    }
}

bool ConnectedComponents::connected(int v, int w) const
{
    return ids[v] == ids[w];
}

int ConnectedComponents::numberOfComponents() const
{
    return count;
}

ConnectedComponents::~ConnectedComponents()
{
    delete[] visited;
    delete[] ids;
}