#include <vector>

template <typename T>
bool isSorted(const std::vector<T> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] > v[i + 1])
        {
            return false;
        }
    }
    return true;
}