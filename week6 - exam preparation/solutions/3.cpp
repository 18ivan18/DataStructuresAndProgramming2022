//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};
#include <iostream>

ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode *dummyHead = new ListNode();
    dummyHead->next = head;
    ListNode *pre = dummyHead;

    ListNode *pointer = head;
    ListNode *curr = pointer;

    int sum = 0, numberOfNodesInSequence = 0;
    bool hasDeleted = false;
    while (pointer)
    {
        sum = 0;
        curr = pointer;
        hasDeleted = false;
        numberOfNodesInSequence = 0;

        while (curr)
        {
            sum += curr->val;
            numberOfNodesInSequence++;
            if (sum == 0)
            {
                ListNode *toBeDeleted, *temp = pointer;

                pointer = curr->next;
                pre->next = pointer;

                for (int i = 0; i < numberOfNodesInSequence; i++)
                {
                    toBeDeleted = temp;
                    temp = temp->next;
                    delete toBeDeleted;
                }

                hasDeleted = true;
                break;
            }
            curr = curr->next;
        }
        if (!hasDeleted)
        {
            pointer = pointer->next;
            pre = pre->next;
        }
    }
    return dummyHead->next;
}

int main()
{
    ListNode *result = removeZeroSumSublists(new ListNode(1, new ListNode(2, new ListNode(-3, new ListNode(-3, new ListNode(1, nullptr))))));
    while (result)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
}