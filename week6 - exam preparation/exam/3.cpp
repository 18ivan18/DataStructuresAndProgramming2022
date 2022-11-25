#include <stack>
#include <string>
#include <cassert>
#include <iostream>

bool readAndDelete(std::stack<char> &stack, const std::string &str)
{
    int i = 0;
    std::stack<char> store;
    while (!stack.empty())
    {
        if (str[i] == stack.top())
        {
            i++;
        }
        else
        {
            store.push(stack.top());
        }
        stack.pop();
    }
    while (!store.empty())
    {
        stack.push(store.top());
        store.pop();
    }

    return i == str.length();
}

template <typename T>
void print(std::stack<T> s)
{
    while (!s.empty())
    {
        std::cout << s.top();
        s.pop();
    }
    std::cout << '\n';
}

void test1()
{
    std::stack<char> stack;
    stack.push('m');
    stack.push('o');
    stack.push('o');
    stack.push('f');
    stack.push('m');
    std::string string = "mom";
    assert(readAndDelete(stack, string));
    print(stack);
}

void test2()
{
    std::stack<char> stack;
    stack.push('y');
    stack.push('a');
    stack.push('d');
    stack.push('c');
    stack.push('c');
    std::string string = "car";
    assert(!readAndDelete(stack, string));
    print(stack);
}

int main()
{
    test1();
    test2();
}