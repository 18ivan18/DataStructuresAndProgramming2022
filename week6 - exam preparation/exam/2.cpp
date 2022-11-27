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
void print(Node<T> *head)
{
    while (head)
    {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << '\n';
}

template <typename T>
void balance(Node<T> *head)
{
    Node<T> *prev = head, *curr = head->next;
    if (!head || !head->next || !head->next->next)
    {
        return;
    }
    while (curr->next)
    {
        if (prev->value + curr->next->value == curr->value)
        {
            Node<T> *del = curr;
            curr = curr->next;
            prev->next = curr;
            delete del;
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
}

template <typename T>
bool makeTotal(Node<T> *head)
{
    Node<T> *prev = head, *curr = head->next;
    while (curr->next)
    {
        if (prev->value + curr->next->value != curr->value)
        {
            balance(head);
            return false;
        }
        prev = curr;
        curr = curr->next;
    }

    return true;
}

template <typename T>
void deleteList(Node<T> *head)
{
    while (head)
    {
        Node<int> *del = head;
        head = head->next;
        delete del;
    }
}

int main()
{
    Node<int> *head = new Node<int>(1, new Node<int>(-4, new Node<int>(-5, new Node<int>(-1, new Node<int>(4)))));
    print(head);
    std::cout << std::boolalpha << makeTotal(head) << '\n';
    print(head);

    Node<int> *head1 = new Node<int>(10, new Node<int>(5, new Node<int>(-5, new Node<int>(-15, new Node<int>(2)))));
    print(head1);
    std::cout << std::boolalpha << makeTotal(head1) << '\n';
    print(head1);

    deleteList(head);
    deleteList(head1);
}