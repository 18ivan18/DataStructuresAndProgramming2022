struct Node
{
    int data;
    Node *next;
};

void reverse(Node *&head, int m, int n)
{
    // base case
    if (m > n)
    {
        return;
    }

    Node *prev = nullptr; // the previous pointer
    Node *curr = head;    // the main pointer

    // 1. Skip the first `m` nodes
    for (int i = 1; curr != nullptr && i < m; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    // `prev` now points to (m-1)'th node
    // `curr` now points to m'th node

    Node *start = curr;
    Node *end = nullptr;

    // 2. Traverse and reverse the sublist from position `m` to `n`
    for (int i = 1; curr != nullptr && i <= n - m + 1; i++)
    {
        // Take note of the next node
        Node *next = curr->next;

        // move the current node onto the `end`
        curr->next = end;
        end = curr;

        // move to the next node
        curr = next;
    }

    /*
        `start` points to the m'th node
        `end` now points to the n'th node
        `curr` now points to the (n+1)'th node
    */

    // 3. Fix the pointers and return the head node

    if (start)
    {
        start->next = curr;
        if (prev != nullptr)
        {
            prev->next = end;
        }
        // when m = 1, `prev` is nullptr
        else
        {
            // fix the head pointer to point to the new front
            head = end;
        }
    }
}