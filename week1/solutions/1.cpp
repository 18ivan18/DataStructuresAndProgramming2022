#include <functional>
#include <cassert>
#include "reduce.cpp"

int next(int x)
{
    return x + 3;
}

int sumReduce(int *arr, int size, std::function<int(int)> next)
{
    return reduce(arr, size, add, 0, next);
}

int sum(int *arr, int size, int (*next)(int))
{
    int result = 0;
    for (size_t i = 0; i < size; i = next(i))
    {
        result += arr[i];
    }
    return result;
}

int main()
{
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        size = sizeof(input) / sizeof(input[0]), expected = input[0] + input[3] + input[6] + input[9];
    assert(expected == sum(input, size, next));
}