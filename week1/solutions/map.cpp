#include <cassert>

template <typename T>
T *map(T *arr, int size, T (*op)(T))
{
    T *map = new T[size];
    for (int i = 0; i < size; i++)
    {
        map[i] = op(arr[i]);
    }

    return map;
}

template <typename T>
void mapModify(T *arr, int size, T (*op)(T))
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = op(arr[i]);
    }
}

int square(int x)
{
    return x * x;
}

void runTests()
{
    int input[] = {1, 2, 3, 4, 5}, size = sizeof(input) / sizeof(input[0]);
    int *mapped = map(input, size, square);
    int expected[] = {1, 4, 9, 16, 25};
    for (int i = 0; i < size; i++)
    {
        assert(mapped[i] == expected[i]);
    }

    delete[] mapped;
}

int main()
{
    runTests();
}
