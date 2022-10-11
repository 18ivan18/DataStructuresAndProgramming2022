#include <functional>
#include <cmath>
#include <cassert>

std::function<double(double)> compose(int n, double (*f)(double))
{
    return [=](double input)
    {
        int result = input;
        for (size_t i = 0; i < n; i++)
        {
            result = f(result);
        }
        return result;
    };
}

int main()
{
    // sqrt from cmath
    const auto &transformBytesUpwords = compose(10, sqrt);
    double kb1 = 1024, mb1 = transformBytesUpwords(kb1);
    double kb4 = 4096, mb4 = transformBytesUpwords(kb4);
    assert(mb1 = 1);
    assert(mb4 = 4);
}