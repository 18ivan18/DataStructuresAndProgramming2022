#include <cassert>
#include <string>
#include <functional>

std::function<int(int)> plus(int x)
{
    return [=](int arg)
    { return arg + x; };
}

template <typename T, typename U>
U reduce(T *arr, int size, U (*op)(T, U), U initial, std::function<int(int)> next = plus(1))
{
    U result = initial;
    for (int i = 0; i < size; i = next(i))
    {
        result = op(arr[i], result);
    }

    return result;
}

int add(int a, int b)
{
    return a + b;
}

std::string append(int a, std::string b)
{
    return b.append(std::to_string(a));
}

void runTests()
{
    std::function<int(int)> plus1 = plus(1);
    assert(1 == plus1(0));
    assert(2 == plus1(1));

    std::function<int(int)> plus5 = plus(5);
    assert(5 == plus5(0));
    assert(6 == plus5(1));

    int input[] = {1, 2, 3},
        size = sizeof(input) / sizeof(input[0]), expected = 6, initial = 0;
    int reduced = reduce(input, size, add, initial);
    assert(reduced == expected);

    std::string initial1, expected1 = "123";
    std::string reduced1 = reduce(input, size, append, initial1);
    assert(reduced1 == expected1);
}
