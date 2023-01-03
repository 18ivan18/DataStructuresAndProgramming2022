#include "EulerianCycle.h"

struct EulerianCycle::Edge
{
    int v;
    int w;
    bool isUsed;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
        isUsed = false;
    }

    // returns the other vertex of the edge
    int other(int vertex)
    {
        if (vertex == v)
        {
            return w;
        }
        else if (vertex == w)
        {
            return v;
        }
        throw new std::invalid_argument("Illegal endpoint");
    }
};

EulerianCycle::EulerianCycle(const Graph &G)
{
    cycle = nullptr;
    // necessary condition: all vertices have even degree
    // (this test is needed or it might find an Eulerian path instead of cycle)
    for (int v = 0; v < G.V(); v++)
    {
        if (SimpleGraphProcessingAPI::degree(G, v) % 2 != 0)
        // if (G.degree(v) & 1)
        {
            return;
        }
    }
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
    int s = SimpleGraphProcessingAPI::nonIsolatedVertex(G);
    // non recursive dfs
    std::stack<int> stack;
    stack.push(s);
    // greedily search through edges in iterative DFS style
    cycle = new std::stack<int>();
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
            edge->isUsed = true;
            stack.push(v);
            v = edge->other(v);
        }
        // push vertex with no more leaving edges to cycle
        cycle->push(v);
    }

    // check if all edges are used
    if (cycle->size() != G.E() + 1)
    {
        delete cycle;
        cycle = nullptr;
    }
    delete[] adj;
}

EulerianCycle::~EulerianCycle()
{
    delete cycle;
}

std::stack<int> EulerianCycle::eulerianCycle()
{
    return *cycle;
}

bool EulerianCycle::hasEulerianCycle()
{
    return cycle != nullptr;
}