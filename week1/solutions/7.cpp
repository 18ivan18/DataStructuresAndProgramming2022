#include <cassert>
#include <iostream>

int f(int x)
{
    return x + 1;
}

int g(int x)
{
    return x * 2;
}

int switchsum(int n, int x, int (*f)(int), int (*g)(int))
{
    int prev = f(x);
    int result = prev;
    for (int i = 1; i < n; i++)
    {
        prev = (i % 2 == 0) ? f(prev) : g(prev);
        result += prev;
    }
    return result;
}

int main()
{
    assert(switchsum(1, 2, f, g) == 3);  // f(2) = 2 + 1 = 3
    assert(switchsum(2, 2, f, g) == 9);  // f(2) + g(f(2)) = (2 + 1) + (2 + 1) * 2 = 3 + 6 = 9
    assert(switchsum(3, 2, f, g) == 16); // f(2) + g(f(2)) + f(g(f(2)))= (2 + 1) + (2 + 1) * 2 + ((2 + 1) * 2) + 1 = 3 + 6 + 7 = 16
    assert(switchsum(4, 2, f, g) == 30);
}
