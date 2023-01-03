#ifndef SYMBOL_GRAPH
#define SYMBOL_GRAPH

#include "RedBlackBST.cpp"
#include "Graph.cpp"
#include <string>
#include <vector>

#define ST RedBlackBST

class SymbolGraph
{
private:
    // Here ST is a symbol table, use any symbol table implementation you want, suggested to use the self-balancing tree implementation from last time
    ST<std::string, int> *st; // String -> index

    std::vector<std::string> keys; // index -> String

    Graph *graph; // the graph

    std::vector<std::string> split(std::string &, const std::string &);

public:
    SymbolGraph(const std::string &, const std::string &);

    bool contains(const std::string &) const;

    int index(const std::string &);

    std::string name(int v);

    Graph *G();
};
#endif