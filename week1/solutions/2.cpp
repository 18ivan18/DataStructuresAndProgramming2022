#include <functional>
#include <cassert>

bool isDivisible(int x, int y)
{
    return x % y == 0;
}

int countTuplesThatFullfilPredicate(int *arr, int size, bool (*pred)(int, int))
{
    int cnt = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            cnt += pred(arr[i], arr[j]);
            cnt += pred(arr[j], arr[i]);
        }
    }

    return cnt;
}

int main()
{
    int input[] = {1, 2, 3, 4},
        size = sizeof(input) / sizeof(input[0]), expected = 4;
    assert(expected == countTuplesThatFullfilPredicate(input, size, isDivisible));
}