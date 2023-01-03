#include <iostream>
// #include "Digraph.cpp"
// #include "TopologicalSort.cpp"
// #include "ConnectedComponents.cpp"
#include "KosarajuSharirSCC.cpp"
#include "TwoSAT.cpp"
#include <fstream>

// example input: (aV~b)^(~aVb)^(~aV~b)^(aV~c)
// output: Is solvable? true
//         a-false b-false c-false

// example input: (xVy)^(yV~x)^(~xV~y)
// output: Is solvable? true
//         x-false y-true

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./main conjunctive normal form\n";
        return 1;
    }
    // std::ifstream in(argv[1]);
    // if (!in)
    // {
    //     // error
    //     std::cout << "Failed opening file\n";
    //     return 1;
    // }
    // Digraph G(in);
    // // G.removeEdge(7, 8);
    // in.close();

    // for (int v = 0; v < G->V(); v++)
    // {
    //     for (int w : G->adj(v))
    //     {
    //         std::cout << v << "-" << w << std::endl;
    //     }
    // }

    // TopologicalSort ts(G);
    // std::stack<int> sorted = ts.reversePost();
    // while (!sorted.empty())
    // {
    //     int v = sorted.top();
    //     sorted.pop();
    //     std::cout << v;
    //     if (!sorted.empty())
    //     {
    //         std::cout << "->";
    //     }
    // }
    // std::cout << std::endl;

    // ConnectedComponents cc(G);
    // std::cout << cc.numberOfComponents() << " Are 2 and 6" << std::boolalpha << cc.connected(2, 6) << "\n";

    // KosarajuSharirSCC scc(G);
    // std::cout << "sc 6 7 ? " << std::boolalpha << scc.stronglyConnected(6, 7) << " sc 9 10? " << scc.stronglyConnected(9, 10) << "\n";

    try
    {
        TwoSAT ts(argv[1]);
        std::cout << "Is solvable? " << std::boolalpha << ts.isSatisfiable() << "\n";
        if (ts.isSatisfiable())
        {
            for (int i = 0; i < ts.getAssignment().size(); i++)
            {
                std::cout << ts.getAssignment()[i].first << std::boolalpha << "-" << ts.getAssignment()[i].second << " ";
            }
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // delete G;
}