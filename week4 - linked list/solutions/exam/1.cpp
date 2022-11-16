#include <iostream>
#include <cassert>
#include <stack>

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

typedef Node<std::stack<int>> StackNode;

enum StackType
{
    Even,
    Odd,
    Mixed,
    Undefined
};

StackType typeOf(std::stack<int> s)
{
    bool isEven = true, isOdd = true;
    while (!s.empty())
    {
        if (s.top() % 2 == 0)
        {
            isEven = false;
        }
        else
        {
            isOdd = false;
        }
        s.pop();
    }
    if (!isEven && !isOdd)
    {
        return Mixed;
    }

    if (isEven)
    {
        return Even;
    }

    if (isOdd)
    {
        return Odd;
    }

    return Undefined;
}

std::stack<int> reverse(std::stack<int> s)
{
    std::stack<int> rev;
    while (!s.empty())
    {
        rev.push(s.top());
        s.pop();
    }
    return rev;
}

void concat(std::stack<int> &s1, std::stack<int> &s2)
{
    std::stack<int> rev = reverse(s2);
    while (!rev.empty())
    {
        s1.push(rev.top());
        rev.pop();
    }
}

void concat(StackNode *node)
{
    while (node && node->next)
    {
        StackType s1 = typeOf(node->data), s2 = typeOf(node->next->data);
        if ((s1 == Even && s2 == Even) || (s2 == Odd && s1 == Odd))
        {
            StackNode *toBeDeleted = node->next;
            concat(node->data, node->next->data);
            node->next = node->next->next;
            delete toBeDeleted;
            continue;
        }
        node = node->next;
    }
}

void print(StackNode *node)
{
    while (node)
    {
        std::stack<int> rev = reverse(node->data);
        while (!rev.empty())
        {
            std::cout << rev.top() << " ";
            rev.pop();
        }
        std::cout << std::endl;
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    std::stack<int> s1;
    s1.push(2);
    s1.push(4);
    s1.push(6);
    std::stack<int> s2;
    s2.push(8);
    s2.push(0);
    std::stack<int> s3;
    s3.push(5);
    s3.push(7);
    std::stack<int> s4;
    s4.push(9);
    s4.push(1);
    std::stack<int> s5;
    s5.push(2);
    s5.push(0);
    std::stack<int> s6;
    s6.push(2);
    s6.push(1);
    StackNode *n = new StackNode{s1, new StackNode{s2, new StackNode{s3, new StackNode{s4, new StackNode{s5, new StackNode{s6}}}}}};
    print(n);
    concat(n);

    print(n);
}