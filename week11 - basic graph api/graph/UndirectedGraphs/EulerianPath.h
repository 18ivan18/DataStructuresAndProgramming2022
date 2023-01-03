#ifndef EULERIAN_PATH
#define EULERIAN_PATH

#include "Graph.cpp"
#include "SimpleGraphProcessingAPI.cpp"
#include <exception>
#include <queue>
#include <stack>

class EulerianPath
{
private:
    struct Edge;
    std::stack<int> *path;

public:
    EulerianPath(const Graph &);
    bool hasEulerianPath();
    std::stack<int> eulerianPath();
    ~EulerianPath();
};

#endif
