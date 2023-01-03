#include <iostream>
#include <string>
#include <fstream>
#include "Graph.cpp"
#include "BreadthFirstPaths.cpp"
#include "DepthFirstPaths.cpp"

using Paths = DepthFirstPaths;

int main(int argv, char *argc[])
{
    if (argv != 2)
    {
        std::cerr << "Usage: main <filename>n\n";
        return -1;
    }
    std::ifstream os(argc[1]);
    if (!os)
    {
        std::cerr << "Invalid file name\n";
    }
    Graph G(os);
    std::cout << G;
    Paths paths(G, 1);
    std::cout << "Has path to 5? " << std::boolalpha << paths.hasPathTo(5) << "\n"
              << "Has path to 2? " << std::boolalpha << paths.hasPathTo(2) << "\n";
    std::cout << "Path to 5: \n";
    std::stack<int> pathToFive = paths.pathTo(5);
    while (!pathToFive.empty())
    {
        std::cout << pathToFive.top() << " ";
        pathToFive.pop();
    }
    std::cout << "\n";
    std::stack<int> pathToTwo = paths.pathTo(2);
    while (!pathToTwo.empty())
    {
        std::cout << pathToTwo.top() << " ";
        pathToTwo.pop();
    }
    std::cout << "\n";
}