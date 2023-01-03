#include "EulerianPath.h"
#include <iostream>

struct EulerianPath::Edge
{
    int v, w;
    bool isUsed;
    int other(int);
    Edge(int, int);
};

EulerianPath::Edge::Edge(int v, int w) : v(v), w(w), isUsed(false) {}

int EulerianPath::Edge::other(int vertex)
{
    if (vertex == v)
    {
        return w;
    }
    else if (vertex == w)
    {
        return v;
    }
    else
        throw new std::invalid_argument("Illegal endpoint");
}

EulerianPath::EulerianPath(const Graph &G) : path(nullptr)
{
    // find vertex from which to start potential Eulerian path:
    // a vertex v with odd degree(v) if it exits;
    // otherwise a vertex with degree(v) > 0
    int oddDegreeVertices = 0;
    int s = SimpleGraphProcessingAPI::nonIsolatedVertex(G);
    for (int v = 0; v < G.V(); v++)
    {
        if (SimpleGraphProcessingAPI::degree(G, v) % 2 != 0)
        {
            oddDegreeVertices++;
            s = v;
        }
    }

    // graph can't have an Eulerian path
    // (this condition is needed for correctness)
    if (oddDegreeVertices > 2)
    {
        return;
    }

    // special case for graph with zero edges (has a degenerate Eulerian path)
    if (s == -1)
    {
        s = 0;
    }

    // create local view of adjacency lists, to iterate one vertex at a time
    // the helper Edge data type is used to avoid exploring both copies of an edge v-w
    std::queue<Edge *> *adj = new std::queue<Edge *>[G.V()];

    for (int v = 0; v < G.V(); v++)
    {
        int selfLoops = 0;
        for (int w : G.adjacent(v))
        {
            // careful with self loops
            if (v == w)
            {
                if (selfLoops % 2 == 0)
                {
                    Edge *e = new Edge(v, w);
                    adj[v].push(e);
                    adj[w].push(e);
                }
                selfLoops++;
            }
            else if (v < w)
            {
                Edge *e = new Edge(v, w);
                adj[v].push(e);
                adj[w].push(e);
            }
        }
    }
    // initialize stack with any non-isolated vertex
    std::stack<int> stack;
    stack.push(s);

    // greedily search through edges in iterative DFS style
    path = new std::stack<int>;
    while (!stack.empty())
    {
        int v = stack.top();
        stack.pop();
        while (!adj[v].empty())
        {
            Edge *edge = adj[v].front();
            adj[v].pop();
            if (edge->isUsed)
            {
                continue;
            }
            // here I leak some memory
            edge->isUsed = true;
            stack.push(v);
            v = edge->other(v);
        }
        // push vertex with no more leaving edges to path
        path->push(v);
    }

    // check if all edges are used
    if (path->size() != G.E() + 1)
    {
        delete path;
        path = nullptr;
    }
    delete[] adj;
}

bool EulerianPath::hasEulerianPath()
{
    return path != nullptr;
}

std::stack<int> EulerianPath::eulerianPath()
{
    return *path;
}

EulerianPath::~EulerianPath()
{
    delete path;
}