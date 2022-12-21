#include "AVLTree.h"
#include <iostream>
#include "string"

int main()
{
    AVLTree<std::string, int> *avl = new AVLTree<std::string, int>();
    for (int i = 0; std::cin.good(); i++)
    {
        std::string key;
        std::cin >> key;
        avl->put(key, i);
    }
    for (std::string s : avl->keys())
    {
        std::cout << s << " " << *avl->get(s);
    }
    std::cout << std::endl;
    delete avl;
}