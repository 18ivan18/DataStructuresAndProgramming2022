#ifndef CYCLE
#define CYCLE
#include "Graph.cpp"

class Cycle
{
private:
    bool cycle;
    bool *marked;
    void dfs(const Graph &, int, int);

public:
    Cycle(const Graph &);
    bool hasCycle();
    ~Cycle();
};

#endif
