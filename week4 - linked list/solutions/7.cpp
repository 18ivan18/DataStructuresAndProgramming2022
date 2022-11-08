//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

// int size(ListNode *head)
// {
//     int size = 0;
//     while (head)
//     {
//         size++;
//         head = head->next;
//     }
//     return size;
// }

// ListNode *removeNthFromEnd(ListNode *head, int n)
// {
//     ListNode *curr = head;
//     int sz = size(head);
//     if (sz == 1)
//     {
//         return nullptr;
//     }
//     if (n == sz)
//     {
//         return head->next;
//     }
//     if (n == 1)
//     {
//         while (curr->next->next)
//         {
//             curr = curr->next;
//         }
//         delete curr->next;
//         curr->next = nullptr;
//         return head;
//     }
//     while (sz - n > 1)
//     {
//         curr = curr->next;
//         n++;
//     }
//     ListNode *toBeDeleted = curr->next;
//     curr->next = curr->next->next;
//     delete toBeDeleted;
//     return head;
// }

// [1->2->3->4->5]
// 2
// One pass through
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummyHead = new ListNode(), *slow = dummyHead, *fast = dummyHead;
    dummyHead->next = head;
    for (int i = 0; i < n + 1; i++)
    {
        fast = fast->next;
    }
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // delete the node
    slow->next = slow->next->next;
    return dummyHead->next;
}