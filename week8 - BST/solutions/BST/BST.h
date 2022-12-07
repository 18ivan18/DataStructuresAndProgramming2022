#ifndef BINARY_SERACH_TREE
#define BINARY_SERACH_TREE

#include <vector>
#include <iostream>

template <typename Key, typename Value>
class BST
{
private:
    struct Node;

    Node *root;

    void del();
    void del(Node *);

    Node *put(Node *, const Key &, const Value &);
    void traverseInorder(Node *);

    int size(Node *);
    int rank(const Key &, Node *);
    Node *remove(const Key &, Node *);
    Node *deleteMin(Node *);
    Node *min(Node *);

    Node *create(std::vector<std::pair<Key, Value>> vals, int start, int end);

    void printHelper(Node *node, int spaces = 0);

public:
    class iterator;

    BST();
    // sorted array!
    BST(const std::vector<std::pair<Key, Value>> &);
    void prittyPrint();
    bool contains(const Key &) const;
    // TODO: homework
    // int height() const;
    Value *get(const Key &) const;
    void put(const Key &, const Value &);
    void remove(const Key &);
    void traverseInorder();
    // TODO: homework
    void serialize(std::ostream &) const;
    // TODO: homework
    // bool isBST() const;
    int size();
    ~BST();
    // TODO: homework
    // Return number of keys less than x->key in the subtree rooted at x.
    // int rank(const Key &key) const;

    // TODO: homework
    //     Floor and ceiling. If a given key key is less than
    // the key at the root of a BST, then the floor of key
    // (the largest key in the BST less than or equal to
    // key ) must be in the left subtree. If key is greater
    // than the key at the root, then the floor of key
    // could be in the right subtree, but only if there is
    // a key smaller than or equal to key in the right
    // subtree; if not (or if key is equal to the key at the
    // root), then the key at the root is the floor of key .
    // Again, this description serves both as the basis
    // for the recursive floor() method and for an in-
    // ductive proof that it computes the desired result.
    // Interchanging right and left (and less and greater)
    // gives ceiling().

    // iterator
    iterator begin();
    iterator end();
};

#endif