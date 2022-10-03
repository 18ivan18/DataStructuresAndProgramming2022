#include <iostream>

int resultOfCalculation(int (*op)(int, int),
                        int x, int y)
{
    return (*op)(x, y);
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int (*addPtr)(int, int);
    addPtr = &add;

    std::cout
        << resultOfCalculation(addPtr, 1, 2) << '\n';

    std::cout
        << resultOfCalculation(add, 1, 2) << '\n';
}