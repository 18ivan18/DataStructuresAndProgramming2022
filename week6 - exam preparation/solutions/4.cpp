struct Node
{
    int val;
    Node *next;
    Node(int x = 0, Node *next = nullptr) : val(x), next(next) {}
};

Node *reverse(Node *head)
{
    Node *curr = head, *prev = nullptr, *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

#include <iostream>
void print(Node *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// 1 -> 2  3 -> 4
// 1 -> 2  4 -> 3
// 1 -> 4 -> 2 -> 3
Node *reorderList(Node *head)
{
    Node *fast = head, *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow;
    slow = slow->next;
    mid->next = nullptr;

    slow = reverse(slow);

    fast = head;

    while (slow)
    {
        Node *fastNext = fast->next, *slowNext = slow->next;
        fast->next = slow;
        slow->next = fastNext;
        fast = fastNext;
        slow = slowNext;
    }

    return head;
}

int main()
{
    Node *head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    Node *head1 = new Node(1, new Node(2, new Node(3, new Node(4))));

    print(reorderList(head));
    print(reorderList(head1));
}