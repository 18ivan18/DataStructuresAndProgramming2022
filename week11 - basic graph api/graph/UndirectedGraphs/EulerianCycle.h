#ifndef EULERIAN_CYCLE
#define EULERIAN_CYCLE
#include <stack>
#include <queue>
#include "graph.cpp"
#include "SimpleGraphProcessingAPI.cpp"

class EulerianCycle
{
private:
    std::stack<int> *cycle;
    struct Edge;
    int nonIsolatedVertex(const Graph &);

public:
    EulerianCycle(const Graph &);
    std::stack<int> eulerianCycle();
    bool hasEulerianCycle();
    ~EulerianCycle();
};

#endif
