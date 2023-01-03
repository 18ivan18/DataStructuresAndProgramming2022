#ifndef DEPTH_FIRST_PATHS
#define DEPTH_FIRST_PATHS
#include "Graph.cpp"
#include <stack>

class DepthFirstPaths
{
private:
    bool *visited;
    int *edgeTo;
    int start;

    void dfs(const Graph &, int); // recurvise
    // void iterativeDFS(const Graph &, int);

public:
    DepthFirstPaths(const Graph &, int);
    ~DepthFirstPaths();

    bool hasPathTo(int);
    std::stack<int> pathTo(int);
};

#endif
