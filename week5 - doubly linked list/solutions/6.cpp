#include <vector>
#include <iostream>

struct Node
{
    int data;
    Node *link;
};

// Helper function to return XOR of `x` and `y`
Node *XOR(Node *x, Node *y)
{
    return (Node *)((uintptr_t)(x) ^ (uintptr_t)(y));
}

// Helper function to traverse the list in a forward direction
void traverse(Node *head)
{
    Node *curr = head, *prev = nullptr, *next;

    while (curr != nullptr)
    {
        std::cout << curr->data << " —> ";

        // `next` node would be xor of the address of the previous node
        // and current node link
        next = XOR(prev, curr->link);

        // update `prev` and `curr` pointers for the next iteration of the loop
        prev = curr;
        curr = next;
    }

    std::cout << "nullptr";
}

// Helper function to insert a node at the beginning of the XOR linked list
void push(Node *&headRef, int data)
{
    // allocate a new list node and set its data
    Node *newNode = new Node();
    newNode->data = data;

    // The link field of the new node is XOR of the current head and nullptr
    // since a new node is being inserted at the beginning
    newNode->link = XOR(headRef, nullptr);

    // update link value of the current head node if the linked list is not empty
    if (headRef)
    {
        // `headRef->link` is XOR of null and address of the next node.
        // To get the address of the next node, XOR it with nullptr
        headRef->link = XOR(newNode, XOR(headRef->link, nullptr));
    }

    // update the head pointer
    headRef = newNode;
}

int main()
{
    // input keys
    std::vector<int> keys = {1, 2, 3, 4, 5};

    Node *head = nullptr;
    for (int i = keys.size() - 1; i >= 0; i--)
    {
        push(head, keys[i]);
    }

    traverse(head);
}

/*

Drawbacks of XOR linked List:

An XOR linked list is similar to a doublylinked list but not completely equivalent to a doublylinked list. There are several disadvantages of an XOR linked list over a doubly-linked list, which is discussed below: 
1. A doubly-inked list is easy to code and maintain, but it is a little complex for an XOP linked list. 
2. XOR linked list is not supported by several languages such as Java, where conversion between pointers and integers is undefined. 
3. If a pointer to an existing middle node in an XOR linked list is provided, we can't delete that node from the list or insert a new node before or after it. On the other hand, this can be done easily with a doubly-linked 

*/