#pragma once
#include "Digraph.h"

Digraph::Digraph(int v) : vertices(v)
{
    adjacent = new std::list<int>[v];
    indegree_ = new int[v];
    edges = 0;
}

Digraph::Digraph(std::ifstream &is)
{
    int v, e, pairFirst, pairSecond;
    is >> v >> e;
    vertices = v;
    adjacent = new std::list<int>[vertices];
    indegree_ = new int[v];
    for (int i = 0; i < e; i++)
    {
        is >> pairFirst >> pairSecond;
        addEdge(pairFirst, pairSecond);
    }
}

Digraph::~Digraph()
{
    delete[] adjacent;
}

void Digraph::addEdge(int v, int w)
{
    adjacent[v].push_back(w);
    indegree_[w]++;
    edges++;
}

void Digraph::removeEdge(int v, int w)
{
    adjacent[v].remove(w);
    edges--;
}

std::list<int> Digraph::adj(const int &v) const
{
    return adjacent[v];
}

int Digraph::V() const
{
    return vertices;
}

int Digraph::E() const
{
    return edges;
}

int Digraph::outdegree(int v) const
{
    return adjacent[v].size();
}

int Digraph::indegree(int v) const
{
    return indegree_[v];
}

Digraph *Digraph::reverse()
{
    Digraph *R = new Digraph(vertices);
    for (int v = 0; v < vertices; v++)
    {
        for (int w : adj(v))
        {
            R->addEdge(w, v);
        }
    }
    return R;
}