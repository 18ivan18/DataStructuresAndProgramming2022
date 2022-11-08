#include <vector>
#include <queue>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *dummyHead = new ListNode(), *curr = dummyHead;
    while (l1 || l2)
    {
        if (!l1)
        {
            curr->next = l2;
            l2 = l2->next;
        }
        else if (!l2)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            if (l1->val > l2->val)
            {
                curr->next = l2;
                l2 = l2->next;
            }
            else
            {
                curr->next = l1;
                l1 = l1->next;
            }
        }
        curr = curr->next;
    }

    return dummyHead->next;
}
