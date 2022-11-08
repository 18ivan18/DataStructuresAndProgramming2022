#include <set>
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// space: O(N)
// time: O(N)
ListNode *detectCycle(ListNode *head)
{
    std::set<ListNode *> set;
    while (head)
    {
        if (set.find(head) != set.end())
        {
            return head;
        }
        set.insert(head);
        head = head->next;
    }
    return nullptr;
}

// space: O(1)
// time: O(N)
ListNode *detectCycleConstMemory(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    // find the node that two pointers meet
    while (fast != nullptr)
    {
        slow = slow->next;
        if (fast->next == nullptr)
        {
            return nullptr;
        }
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (fast == nullptr)
    {
        return nullptr;
    }
    slow = head;
    // find the node where the cycle begins
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
