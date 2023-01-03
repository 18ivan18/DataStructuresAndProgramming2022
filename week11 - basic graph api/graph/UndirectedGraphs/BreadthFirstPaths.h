#ifndef BREADTH_FIRST_SEARCH
#define BREADTH_FIRST_SEARCH
#include "Graph.cpp"
#include <stack>

class BreadthFirstPaths
{
private:
    bool *visited;
    int *edgeTo;
    int start;

    void bfs(const Graph &, int);

public:
    BreadthFirstPaths(const Graph &, int);
    ~BreadthFirstPaths();

    bool hasPathTo(int);
    std::stack<int> pathTo(int);
};

#endif
