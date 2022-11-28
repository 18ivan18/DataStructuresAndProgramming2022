#include <iostream>
#include <cassert>

class Node
{
public:
    int val;
    Node *prev = nullptr;
    Node *next = nullptr;
    Node *child = nullptr;
};

Node *flatten(Node *head)
{
    if (!head)
    {
        return nullptr;
    }
    Node *iter = head, *next = head->next;
    if (head->child)
    {
        head->next = flatten(head->child);
        head->next->prev = head;
        while (iter->next)
        {
            iter = iter->next;
        }

        if (next)
        {
            next->prev = iter;
        }

        head->child = nullptr;
    }
    iter->next = flatten(next);

    return head;
}

void print(Node *head)
{
    while (head->next)
    {
        std::cout << head->val << " ";
        head = head->next;
        assert(!head->child);
    }
    std::cout << head->val;

    std::cout << '\n';

    while (head->prev)
    {
        std::cout << head->val << " ";
        head = head->prev;
    }
    std::cout << head->val;
    std::cout << '\n';
}

int main()
{
    Node *head = new Node{1};
    Node *n2 = new Node{2};
    Node *n3 = new Node{3};
    Node *n4 = new Node{4};
    Node *n5 = new Node{5};
    Node *n6 = new Node{6};
    Node *n7 = new Node{7};
    Node *n8 = new Node{8};
    Node *n9 = new Node{9};
    Node *n10 = new Node{10};
    Node *n11 = new Node{11};
    Node *n12 = new Node{12};

    head->next = n2;

    n2->next = n3;
    n2->prev = head;

    n3->next = n4;
    n3->prev = n2;
    n3->child = n7;

    n4->next = n5;
    n4->prev = n3;

    n5->next = n6;
    n5->prev = n4;

    n6->prev = n5;

    n7->next = n8;

    n8->next = n9;
    n8->prev = n7;
    n8->child = n11;

    n9->next = n10;
    n9->prev = n8;

    n10->prev = n9;

    n11->next = n12;

    n12->prev = n11;

    head = flatten(head);
    print(head);
}