//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *prev = nullptr;
    ListNode *cur = head;
    int x = k;
    ListNode *testLen = head;
    while (testLen && x)
    {
        testLen = testLen->next;
        x--;
    }
    if (x != 0)
    {
        return head;
    }

    x = k;
    while (cur && x > 0)
    {
        ListNode *tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
        x--;
    }
    if (cur != nullptr)
    {
        head->next = reverseKGroup(cur, k);
    }
    return prev;
}