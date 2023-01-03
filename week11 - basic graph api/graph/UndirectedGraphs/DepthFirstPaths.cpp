#include "DepthFirstPaths.h"

DepthFirstPaths::DepthFirstPaths(const Graph &G, int s)
{
    start = s;
    int graphSize = G.V();
    visited = new bool[graphSize];
    edgeTo = new int[graphSize];

    for (size_t i = 0; i < graphSize; i++)
    {
        visited[i] = false;
        edgeTo[i] = i;
    }

    dfs(G, start);
}

DepthFirstPaths::~DepthFirstPaths()
{
    delete[] visited;
    delete[] edgeTo;
}

bool DepthFirstPaths::hasPathTo(int v)
{
    return visited[v];
}

std::stack<int> DepthFirstPaths::pathTo(int v)
{
    std::stack<int> result;
    if (!hasPathTo(v))
    {
        return result;
    }
    for (size_t x = v; x != start; x = edgeTo[x])
    {
        result.push(x);
    }
    result.push(start);
    return result;
}

void DepthFirstPaths::dfs(const Graph &G, int v)
{
    visited[v] = true;

    for (int w : G.adjacent(v))
    {
        if (!visited[w])
        {
            dfs(G, w);
            edgeTo[w] = v;
        }
    }
}