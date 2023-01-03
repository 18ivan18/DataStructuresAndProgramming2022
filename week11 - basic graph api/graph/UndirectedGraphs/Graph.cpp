#include "Graph.h"
Graph::Graph(int v) : vertices(v), edges(0), adj(new std::list<int>[v]) {}

// 6 8
// 0 2
// 0 4
// 0 5
// 1 4
// 1 5
// 2 3
// 2 4
// 4 5
Graph::Graph(std::ifstream &is)
{
    int v, e, pairFirst, pairSecond;
    is >> v >> e;
    vertices = v;
    edges = 0;
    adj = new std::list<int>[v];
    for (size_t i = 0; i < e; i++)
    {
        is >> pairFirst >> pairSecond;
        addEdge(pairFirst, pairSecond);
    }
}

Graph::~Graph()
{
    delete[] adj;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
    edges++;
}

std::list<int> Graph::adjacent(int v) const
{
    return adj[v];
}

std::ostream &operator<<(std::ostream &os, const Graph &G)
{
    os << "Number of vertices is " << G.V() << " and number of edges is " << G.E() << "\n";
    for (size_t v = 0; v < G.V(); v++)
    {
        for (int w : G.adjacent(v))
        {
            os << v << " - " << w << "\n";
        }
    }

    return os;
}

int Graph::V() const { return vertices; }
int Graph::E() const { return edges; }