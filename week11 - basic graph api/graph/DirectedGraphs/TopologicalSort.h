#ifndef TOPOLOGICAL_SORT
#define TOPOLOGICAL_SORT
#include "Digraph.cpp"
#include <stack>

class TopologicalSort
{
private:
    bool *visited;
    std::stack<int> sorted;
    void dfs(const int &, const Digraph &);

public:
    TopologicalSort(const Digraph &);
    std::stack<int> reversePost();
    ~TopologicalSort();
};

#endif
