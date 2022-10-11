#include <cassert>
#include <vector>

template <typename T>
std::vector<T> filter(const std::vector<T> &arr, bool (*op)(T))
{
    std::vector<T> filtered;
    for (const T &item : arr)
    {
        if (op(item))
        {
            filtered.push_back(item);
        }
    }

    return filtered;
}

bool isEven(int x)
{
    return x % 2 == 0;
}

void runTests()
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> filtered = filter(input, isEven);
    std::vector<int> expected = {2, 4};
    assert(filtered.size() == expected.size());
    int size = filtered.size();
    for (int i = 0; i < size; i++)
    {
        assert(filtered[i] == expected[i]);
    }
}

int main()
{
    runTests();
}
