#include "SymbolGraph.h"

#include <fstream>

// TODO: this is not the proper place of split
std::vector<std::string> split(std::string &s, const std::string &delimiter)
{
    std::vector<std::string> list;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);
    return list;
}

SymbolGraph::SymbolGraph(const std::string &stream, const std::string &delimiter)
{
    st = new ST<std::string, int>();
    std::ifstream is(stream); // First pass
    // Check if is is open correctly
    std::string line;
    while (is) // builds the index
    {
        std::getline(is, line);
        std::vector<std::string> a = split(line, delimiter); // by reading strings
        for (int i = 0; i < a.size(); i++)                   // to associate each
            if (!st->contains(a[i]))
            { // distinct string
                st->put(a[i], st->size());
            } // with an index.
    }
    is.close();
    for (std::string name : st->keys()) // to get string keys
    {
        // more accurate
        // if (int *res = st->get(name))
        // {
        //     int value = *res;
        //     keys[value] = name;
        // } else {
        //     throw
        // }
        keys[*st->get(name)] = name;
    }
    graph = new Graph(st->size());
    is.open(stream); // Second pass
    while (is)       // builds the graph
    {
        std::vector<std::string> a = split(line, delimiter); // by connecting the
        int *v = st->get(a[0]);                              // first vertex
        for (int i = 1; i < a.size(); i++)                   // on each line
            graph->addEdge(*v, *st->get(a[i]));              // to all the others.
    }
    is.close();
}

bool SymbolGraph::contains(const std::string &s) const
{
    return st->contains(s);
}

int SymbolGraph::index(const std::string &s)
{
    return *st->get(s);
}

std::string SymbolGraph::name(int v)
{
    return keys[v];
}

Graph *SymbolGraph::G()
{
    return graph;
}
