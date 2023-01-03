#ifndef TWO_COLOR
#define TWO_COLOR

#include "Graph.cpp";

class TwoColor
{
private:
    bool *marked;
    bool *color;
    bool isTwoColorable;

    void dfs(const Graph &, int);

public:
    TwoColor(const Graph &);
    ~TwoColor();

    bool isBipartite();
};

#endif