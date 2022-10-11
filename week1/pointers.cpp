#include <iostream>

void swap(int first, int second)
{
    int firstCopy = first;
    first = second;
    second = firstCopy;
}

void swap(int *first, int *second)
{
    int firstCopy = *first;
    *first = *second;
    *second = firstCopy;
}

int main()
{
    int foo = 5;
    int *pFoo = &foo; // & operator takes the address of a variable
    int **ppFoo = &pFoo;
    std::cout << "foo: " << foo << " pFoo: " << pFoo << " ppFoo: " << ppFoo << '\n';

    int *pBar = *ppFoo;
    int bar = *pFoo;
    int baz = **ppFoo;
    std::cout << "pBar: " << pBar << " bar: " << bar << " baz: " << baz << '\n';

    int *i = new int();
    int *i1 = new int(5);
    int *i2 = new int{5};
    int *i3 = new int[5];
    std::cout << *i << " " << *i1
              << " " << *i2
              << " " << *i3 << '\n';

    delete i;
    delete i1;
    delete i2;
    delete[] i3;

    float *f = new float(), *f1 = f;
    *f = 3.14f;
    std::cout << *f1 << '\n';
    *f1 = 10.1f;
    std::cout << *f << '\n';
    delete f;

    int a = 5, b = 10;
    swap(a, b);
    // not swapped
    std::cout << a << " " << b << '\n';

    swap(&a, &b);
    // swapped
    std::cout << a << " " << b << '\n';
}