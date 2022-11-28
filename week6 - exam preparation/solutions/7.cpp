#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

void print(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << '\n';
}

void deleteList(ListNode *head)
{
    while (head)
    {
        ListNode *del = head;
        head = head->next;
        delete del;
    }
}

ListNode *partition(ListNode *head, int x)
{
    ListNode firstHalfHead, secondHalfHead, *firstHalf = &firstHalfHead,
                                            *secondHalf = &secondHalfHead;
    while (head)
    {
        if (head->val < x)
        {
            firstHalf->next = head;
            firstHalf = firstHalf->next;
        }
        else
        {
            secondHalf->next = head;
            secondHalf = secondHalf->next;
        }
        head = head->next;
    }
    firstHalf->next = secondHalfHead.next;
    secondHalf->next = nullptr;
    return firstHalfHead.next;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    print(head);
    head = partition(head, 3);
    print(head);

    deleteList(head);
}