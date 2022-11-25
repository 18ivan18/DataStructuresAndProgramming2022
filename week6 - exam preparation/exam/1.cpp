#include <vector>
#include <exception>
#include <iostream>

template <typename T>
struct Node
{
    T value;
    Node<T> *next;
    Node(T value, Node *next = nullptr) : value(value), next(next) {}
};

template <typename T>
int getLen(Node<T> *list)
{
    int result = 0;
    while (list)
    {
        result++;
        list = list->next;
    }
    return result;
}

template <typename T>
Node<T> *reverse(Node<T> *head, int from, int to)
{
    Node<T> dummyHead(0, head), *prev = &dummyHead, *curr = head, *start, *startPrev, *next;
    for (size_t i = 0; i < from; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    start = curr;
    startPrev = prev;
    for (size_t i = 0; i < to - from + 1; i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start->next = curr;
    startPrev->next = prev;
    return dummyHead.next;
}

template <typename T>
Node<T> *reverseSublists(Node<T> *head, const std::vector<std::pair<int, int>> &intervals)
{
    int len = getLen(head);
    for (auto &&[i, j] : intervals)
    {
        if (i > j || i >= len || j >= len || i < 0 || j < 0)
        {
            throw std::length_error("Index out of bounds.");
        }
    }

    for (auto &&[i, j] : intervals)
    {
        head = reverse(head, i, j);
    }

    return head;
}

template <typename T>
void print(Node<T> *head)
{
    while (head)
    {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << '\n';
}

int main()
{
    Node<int> *head = new Node<int>(11, new Node<int>(4, new Node<int>(3, new Node<int>(7, new Node<int>(13, new Node<int>(4, new Node<int>(5)))))));
    print(head);
    // head = reverseSublists(head, {{4, 2}, {2, 5}, {5, 6}});
    // print(head);

    // head = reverseSublists(head, {{1, 3}, {2, 9}, {5, 6}});
    // print(head);

    head = reverseSublists(head, {{1, 3}, {2, 5}, {5, 6}});
    print(head);

    while (head)
    {
        Node<int> *del = head;
        head = head->next;
        delete del;
    }
}