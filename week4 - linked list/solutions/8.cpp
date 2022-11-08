#include <stdio.h>
#include <stdlib.h>

// MACRO to calculate the number of elements in an array
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// A Linked List Node
struct Node
{
    int data;
    Node *next;
    Node *down;
};

// Helper function to insert a new node at the beginning of the linked list
void push(Node *&headRef, int data)
{
    Node *newNode = new Node{data, nullptr, headRef};

    headRef = newNode;
}

// Takes two lists sorted in increasing order and merge their nodes
// to make one big sorted list, which is returned
struct Node *sortedMerge(struct Node *a, struct Node *b)
{
    // base cases
    if (a == nullptr)
    {
        return b;
    }

    else if (b == nullptr)
    {
        return a;
    }

    Node *result = nullptr;

    // pick either `a` or `b`, and recur
    if (a->data <= b->data)
    {
        result = a;
        result->down = sortedMerge(a->down, b);
    }
    else
    {
        result = b;
        result->down = sortedMerge(a, b->down);
    }

    return result;
}

/*
    Split the given list's nodes into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    It uses the fast/slow pointer strategy
*/
void frontBackSplit(Node *source, Node *&frontRef,
                    Node *&backRef)
{
    // if the length is less than 2, handle it separately
    if (source == nullptr || source->down == nullptr)
    {
        frontRef = source;
        backRef = nullptr;
        return;
    }

    Node *slow = source;
    Node *fast = source->down;

    // advance `fast` two nodes, and advance `slow` one node
    while (fast != nullptr)
    {
        fast = fast->down;
        if (fast != nullptr)
        {
            slow = slow->down;
            fast = fast->down;
        }
    }

    // `slow` is before the midpoint in the list, so split it in two
    // at that point.
    frontRef = source;
    backRef = slow->down;
    slow->down = nullptr;
}

// Sort a given linked list using the merge sort algorithm
void mergesort(Node *&headRef)
{
    // base case — length 0 or 1
    if (headRef == nullptr || headRef->down == nullptr)
    {
        return;
    }

    Node *a, *b;

    // split `head` into `a` and `b` sublists
    frontBackSplit(headRef, a, b);

    // recursively sort the sublists
    mergesort(a);
    mergesort(b);

    // answer = merge the two sorted lists
    headRef = sortedMerge(a, b);

    // set next link to nullptr after merging
    headRef->next = nullptr;
}

// Helper function to print the flattened linked list
void printList(struct Node *node)
{
    while (node)
    {
        printf("%d —> ", node->data);
        node = node->down;
    }
    printf("nullptr");
}

// Iterative function to flatten and sort a given list
void flatten(struct Node *head)
{
    struct Node *curr = head;

    while (curr != nullptr)
    {
        struct Node *temp = curr;
        while (temp->down != nullptr)
        {
            temp = temp->down;
        }
        temp->down = curr->next;
        curr = curr->next;
    }
}

// Helper function to create a linked list with elements of a given vector
void createVerticalList(Node *&head, int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        push(head, arr[i]);
    }
}

int main()
{
    Node *head = nullptr;

    int arr1[] = {8, 6, 4, 1};
    int arr2[] = {7, 3, 2};
    int arr3[] = {9, 5};
    int arr4[] = {12, 11, 10};

    createVerticalList(head, arr1, SIZE(arr1));
    createVerticalList(head->next, arr2, SIZE(arr2));
    createVerticalList(head->next->next, arr3, SIZE(arr3));
    createVerticalList(head->next->next->next, arr4, SIZE(arr4));

    // flatten the list
    flatten(head);

    // sort the list
    mergesort(head);

    // print the flattened and sorted linked list
    printList(head);
}