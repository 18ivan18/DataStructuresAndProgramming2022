#include "BreadthFirstPaths.h"
#include <queue>

BreadthFirstPaths::BreadthFirstPaths(const Graph &G, int start) : start(start)
{
    int graphSize = G.V();
    visited = new bool[graphSize];
    edgeTo = new int[graphSize];

    for (size_t i = 0; i < graphSize; i++)
    {
        visited[i] = false;
        edgeTo[i] = i;
    }

    bfs(G, start);
}

BreadthFirstPaths::~BreadthFirstPaths()
{
    delete[] visited;
    delete[] edgeTo;
}

bool BreadthFirstPaths::hasPathTo(int v)
{
    return visited[v];
}

std::stack<int> BreadthFirstPaths::pathTo(int v)
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

void BreadthFirstPaths::bfs(const Graph &G, int s)
{
    std::queue<int> q;
    visited[s] = true;
    q.push(s);
    int v;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (int w : G.adjacent(v))
        {
            if (!visited[w])
            {
                q.push(w);
                visited[w] = true;
                edgeTo[w] = v;
            }
        }
    }
}