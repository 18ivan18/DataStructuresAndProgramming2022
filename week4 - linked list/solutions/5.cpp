//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummyHead = new ListNode(), *curr = dummyHead;
    bool carry = false;
    while (l1 || l2)
    {
        curr->next = new ListNode();
        curr = curr->next;
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        curr->val = (x + y + carry) % 10;
        carry = (x + y + carry) / 10;
        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
    }
    if (carry)
    {
        curr->next = new ListNode(1);
    }
    return dummyHead->next;
}
