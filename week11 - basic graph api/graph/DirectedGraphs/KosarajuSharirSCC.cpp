#pragma once
#include "KosarajuSharirSCC.h"
#include "TopologicalSort.cpp"

KosarajuSharirSCC::KosarajuSharirSCC(const Digraph &G)
{
    int n = G.V();
    visited = new bool[n];
    ids = new int[n];
    count = 0;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    TopologicalSort ts(G);
    std::stack<int> st = ts.reversePost();
    std::stack<int> temp;

    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }

    while (!temp.empty()) //TODO: int i : st -> iterate from bottom to top
    {
        int i = temp.top();
        temp.pop();
        if (!visited[i])
        {
            dfs(G, i);
            count++;
        }
    }
}

bool KosarajuSharirSCC::stronglyConnected(int w, int v)
{
    return ids[w] == ids[v];
}

KosarajuSharirSCC::~KosarajuSharirSCC()
{
    delete[] ids;
    delete[] visited;
}

void KosarajuSharirSCC::dfs(const Digraph &G, int v)
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

int KosarajuSharirSCC::componentOf(int v)
{
    return ids[v];
}