#ifndef KOSARAJU_SHARIR_STRONGLY_CONNECTED_COMPONENT
#define KOSARAJU_SHARIR_STRONGLY_CONNECTED_COMPONENT
#include "Digraph.h"

class KosarajuSharirSCC
{
private:
    bool *visited;
    int *ids;
    int count;
    void dfs(const Digraph &, int);

public:
    KosarajuSharirSCC(const Digraph &);
    bool stronglyConnected(int, int);
    int componentOf(int);
    ~KosarajuSharirSCC();
};

#endif
