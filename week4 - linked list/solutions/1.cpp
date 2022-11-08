#include <stack>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    std::stack<ListNode *> st;
    while (head)
    {
        st.push(head);
        head = head->next;
    }
    ListNode *dummyHead = new ListNode(), *curr = dummyHead;
    while (!st.empty())
    {
        curr->next = st.top();
        st.pop();
        curr = curr->next;
    }
    curr->next = nullptr;
    // delete dummyHead
    return dummyHead->next;
}

ListNode *reverseListRec(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *temp = reverseListRec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
}

// Recursive function to reverse a given linked list. It reverses the
// given linked list by fixing the head pointer and then `.next`
// pointers of every node in reverse order
void recursiveReverse(struct ListNode *head, struct ListNode **headRef)
{
    ListNode *first;
    ListNode *rest;

    // empty list base case
    if (!head)
    {
        return;
    }

    first = head;       // suppose first = {1, 2, 3}
    rest = first->next; // rest = {2, 3}

    // base case: the list has only one node
    if (rest == nullptr)
    {
        // fix the head pointer here
        *headRef = first;
        return;
    }

    // recursively reverse the smaller {2, 3} case
    // after: rest = {3, 2}
    recursiveReverse(rest, headRef);

    // put the first item at the end of the list
    rest->next = first;
    first->next = nullptr; // (tricky step — make a drawing)
}

// Reverse a given linked list. The function takes a pointer
// (reference) to the head pointer
void reverse(struct ListNode **head)
{
    recursiveReverse(*head, head);
}

void reverse(ListNode *&head)
{
    ListNode *previous = nullptr; // the previous pointer
    ListNode *current = head;     // the main pointer

    // traverse the list
    while (current != nullptr)
    {
        // tricky: note the next node
        ListNode *next = current->next;

        current->next = previous; // fix the current node

        // advance the two pointers
        previous = current;
        current = next;
    }

    // fix the head pointer to point to the new front
    head = previous;
}

// use this one
// the best
ListNode *reverseIterative(ListNode *head)
{
    ListNode *curr = head, *prev = nullptr, *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}