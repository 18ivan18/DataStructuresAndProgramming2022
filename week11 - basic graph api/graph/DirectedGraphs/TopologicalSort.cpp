#include "TopologicalSort.h"

TopologicalSort::TopologicalSort(const Digraph &G)
{
    visited = new bool[G.V()];
    for (int i = 0; i < G.V(); i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < G.V(); i++)
    {
        if (!visited[i])
        {
            dfs(i, G);
        }
    }
}

void TopologicalSort::dfs(const int &v, const Digraph &G)
{
    visited[v] = true;
    for (int w : G.adj(v))
    {
        if (!visited[w])
        {
            dfs(w, G);
        }
    }
    sorted.push(v);
}

std::stack<int> TopologicalSort::reversePost()
{
    return sorted;
}
TopologicalSort::~TopologicalSort()
{
    delete[] visited;
}