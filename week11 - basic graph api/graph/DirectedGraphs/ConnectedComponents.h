#ifndef STRONG_COMPONENTS
#define STRONG_COMPONENTS
#include "Digraph.cpp"

class ConnectedComponents
{
private:
    bool *visited;
    int *ids;
    int count;
    void dfs(const Digraph &, int);

public:
    ConnectedComponents(const Digraph &);
    bool connected(int, int) const;
    int numberOfComponents() const;
    ~ConnectedComponents();
};

#endif
