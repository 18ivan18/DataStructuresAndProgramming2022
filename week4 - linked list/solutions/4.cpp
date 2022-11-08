
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode *merge(ListNode *left, ListNode *right)
{
    ListNode *result = new ListNode(), *curr = result;
    while (left && right)
    {
        if (left->val > right->val)
        {
            curr->next = right;
            right = right->next;
        }
        else
        {
            curr->next = left;
            left = left->next;
        }
        curr = curr->next;
    }
    while (left)
    {
        curr->next = left;
        left = left->next;
        curr = curr->next;
    }
    while (right)
    {
        curr->next = right;
        curr = curr->next;
        right = right->next;
    }
    return result->next;
}

// Top Down Merge Sort
// Time: O(nlogn)
// Space: O(logn), where n is the number of nodes in linked list.
// Since the problem is recursive, we need additional space to store the recursive call stack.
// The maximum depth of the recursion tree is logn
ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *fast = head, *slow = head, *temp = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        temp = slow;
        slow = slow->next;
    }
    temp->next = nullptr;
    ListNode *left = sortList(head);
    ListNode *right = sortList(slow);
    return merge(left, right);
}
