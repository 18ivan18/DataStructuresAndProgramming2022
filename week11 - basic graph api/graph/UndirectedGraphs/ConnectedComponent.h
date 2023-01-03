#ifndef CONNECTED_COMPONENT
#define CONNECTED_COMPONENT
#include "Graph.cpp"

class ConnectedComponent
{
private:
    bool *marked;
    int count;
    int *ids;

    void dfs(const Graph &, int);

public:
    ConnectedComponent(const Graph &G);

    int getCount();
    int id(int v);
    bool connected(int, int);

    ~ConnectedComponent();
};

#endif
