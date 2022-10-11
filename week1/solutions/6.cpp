#include <cassert>
#include <iostream>
#include <cstring>

template <typename T>
void swap(T *xp, T *yp)
{
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(char **arr, int low, int high, int (*comparator)(char *, char *))
{
    char *pivot = arr[high]; // pivot
    int i = (low - 1);       // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (comparator(arr[j], pivot) < 0)
        {
            i++; // increment index of smaller element
            swap(arr + i, arr + j);
        }
    }
    swap(arr + i + 1, arr + high);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(char **arr, int low, int high, int (*comparator)(char *, char *))
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high, comparator);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1, comparator);
        quickSort(arr, pi + 1, high, comparator);
    }
}

void sort(char **arr, int n, int (*comparator)(char *, char *))
{
    quickSort(arr, 0, n - 1, comparator);
}

int comparator(char *str1, char *str2)
{
    return strcmp(str1, str2);
}

int main()
{
    char *input[] = {"i",
                     "love",
                     "eating",
                     "pizza"};
    int size = sizeof(input) / sizeof(input[0]);
    sort(input, size, comparator);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << input[i] << "\n";
    }
}