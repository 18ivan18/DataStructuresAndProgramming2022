#include "BST.h"
#include <cassert>
#include <iomanip>
#include <queue>

#include "./utils.cpp"

template <typename Key, typename Value>
struct BST<Key, Value>::Node
{
    Key key;
    Value value;
    Node *left = nullptr, *right = nullptr;
    int count = 1;

    Node(const Key &key, const Value &value) : key{key}, value{value}
    {
    }
};

template <typename Key, typename Value>
BST<Key, Value>::BST(const std::vector<std::pair<Key, Value>> &v)
{
    assert(isSorted(v));

    root = create(v, 0, v.size() - 1);

    // if (!isBST())
    // {
    // }
}

template <typename Key, typename Value>
typename BST<Key, Value>::Node *BST<Key, Value>::create(std::vector<std::pair<Key, Value>> vals, int start, int end)
{
    //create a node to store the value of arr acc. to its index
    Node *p;
    //go for the condition if it passes then go for other nodes
    //if not then simply return NULL
    if (start <= end)
    {
        int mid = (start + end) / 2;
        p = new Node(vals[mid].first, vals[mid].second); //store the value in Node of current mid of array
        p->left = create(vals, start, mid - 1);          //recursive call of function for its left child
        p->right = create(vals, mid + 1, end);           //recursive call of function for its right child
    }
    else
    {
        return nullptr; //if start>end then simply return nullptr then that nullptr be the child of Node
    }
    return p; //after execution of all recursive calls simply return p it is containing
              //the address of root node
}

template <typename Key, typename Value>
BST<Key, Value>::BST() : root{nullptr}
{
}

template <typename Key, typename Value>
void BST<Key, Value>::put(const Key &key, const Value &val)
{
    root = put(root, key, val);
}

template <typename Key, typename Value>
typename BST<Key, Value>::Node *BST<Key, Value>::put(Node *x, const Key &key, const Value &value)
{
    if (!x)
    {
        return new Node(key, value);
    }
    if (key < x->key)
    {
        x->left = put(x->left, key, value);
    }
    else if (key > x->key)
    {
        x->right = put(x->right, key, value);
    }
    else if (key == x->key)
    {
        x->value = value;
    }
    x->count = 1 + size(x->left) + size(x->right);
    return x;
}

template <typename Key, typename Value>
Value *BST<Key, Value>::get(const Key &key) const
{
    Node *x = root;
    while (x)
    {
        if (key < x->key)
        {
            x = x->left;
        }
        else if (key > x->key)
        {
            x = x->right;
        }
        else
        {
            return &x->value;
        }
    }
    return nullptr;
}

template <typename Key, typename Value>
bool BST<Key, Value>::contains(const Key &key) const
{
    return get(key);
}

template <typename Key, typename Value>
void BST<Key, Value>::remove(const Key &key)
{
    root = remove(key, root);
}

template <typename Key, typename Value>
typename BST<Key, Value>::Node *BST<Key, Value>::remove(const Key &key, Node *x)
{
    if (!x)
    {
        return nullptr;
    }
    if (x->key == key)
    {
        auto toDelete = x;
        if (!x->left)
        {
            auto toReturn = x->right;
            delete toDelete;
            return toReturn;
        }
        if (!x->right)
        {
            auto toReturn = x->left;
            delete toDelete;
            return toReturn;
        }
        Node *t = x;
        x = min(t->right);
        x->right = deleteMin(t->right);
        x->left = t->left;
        delete toDelete;
    }
    else if (x->key < key)
    {
        x->right = remove(key, x->right);
    }
    else if (x->key > key)
    {
        x->left = remove(key, x->left);
    }
    x->count = 1 + size(x->left) + size(x->right);
    return x;
}

template <typename Key, typename Value>
typename BST<Key, Value>::Node *BST<Key, Value>::min(Node *x)
{
    if (x->left == nullptr)
    {
        return x;
    }
    return min(x->left);
}

template <typename Key, typename Value>
typename BST<Key, Value>::Node *BST<Key, Value>::deleteMin(Node *x)
{
    if (x->left == nullptr)
    {
        return x->right;
    }
    x->left = deleteMin(x->left);
    x->count = 1 + size(x->left) + size(x->right);
    return x;
}

template <typename Key, typename Value>
BST<Key, Value>::~BST()
{
    del();
}

template <typename Key, typename Value>
void BST<Key, Value>::del()
{
    del(root);
}

template <typename Key, typename Value>
void BST<Key, Value>::del(Node *node)
{
    if (!node)
    {
        return;
    }
    del(node->left);
    del(node->right);
    delete node;
}

template <typename Key, typename Value>
void BST<Key, Value>::traverseInorder()
{
    traverseInorder(root);
    std::cout << std::endl;
}

template <typename Key, typename Value>
void BST<Key, Value>::traverseInorder(Node *node)
{
    if (!node)
    {
        return;
    }
    traverseInorder(node->left);
    std::cout << node->key;
    traverseInorder(node->right);
}

template <typename Key, typename Value>
int BST<Key, Value>::size(Node *x)
{
    if (!x)
    {
        return 0;
    }
    return x->count;
}

template <typename Key, typename Value>
void BST<Key, Value>::prittyPrint()
{
    printHelper(root);
}

template <typename Key, typename Value>
void BST<Key, Value>::printHelper(Node *node, int spaces)
{
    if (node != nullptr)
    {
        if (node->right)
        {
            printHelper(node->right, spaces + 4);
        }
        if (spaces)
        {
            std::cout << std::setw(spaces) << ' ';
        }
        if (node->right)
        {
            std::cout << " /\n"
                      << std::setw(spaces) << ' ';
        }
        std::cout << node->key << ":" << node->value << "\n ";
        if (node->left)
        {
            std::cout << std::setw(spaces) << ' ' << " \\\n";
            printHelper(node->left, spaces + 4);
        }
    }
}

// template <typename Key, typename Value>
// int BST<Key, Value>::rank(const Key &key) const
// {
//     return rank(key, root);
// }

// template <typename Key, typename Value>
// int BST<Key, Value>::rank(const Key &key, Node *x)
// {
//     if (x == nullptr)
//     {
//         return 0;
//     }
//     if (key < x->key)
//     {
//         return rank(key, x->left);
//     }
//     else if (key > x->key)
//     {
//         return 1 + size(x->left) + rank(key, x->right);
//     }
//     return size(x->left);
// }

template <typename Key, typename Value>
class BST<Key, Value>::iterator
{
    std::queue<BST<Key, Value>::Node *> v;

public:
    iterator(BST<Key, Value>::Node *root)
    {
        inOrder(root);
    }

    void inOrder(BST<Key, Value>::Node *root)
    {
        if (!root)
        {
            return;
        }
        inOrder(root->left);
        v.push(root);
        inOrder(root->right);
    }

    iterator &operator++()
    {
        v.pop();
        return *this;
    }

    iterator operator++(int)
    {
        iterator save = *this;
        ++(*this);
        return save;
    }

    std::pair<Key, Value> operator*()
    {
        return std::make_pair(v.front()->key, v.front()->value);
    }

    bool operator!=(const iterator &rhs)
    {
        if (v.empty() && rhs.v.empty())
        {
            return false;
        }
        if (v.empty() || rhs.v.empty())
        {
            return true;
        }
        return v.front() != rhs.v.front();
    }

    bool hasNext()
    {
        return !v.empty();
    }
};

template <typename Key, typename Value>
typename BST<Key, Value>::iterator BST<Key, Value>::begin()
{
    return iterator(root);
}

template <typename Key, typename Value>
typename BST<Key, Value>::iterator BST<Key, Value>::end()
{
    return iterator(nullptr);
}