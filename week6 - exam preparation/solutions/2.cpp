// *Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <stack>
#include <iostream>

bool isPalindrome(ListNode *head)
{
    if (!head->next)
    {
        return true;
    }
    ListNode *fast = head, *slow = head;
    std::stack<int> s;
    bool odd = false;
    while (fast)
    {
        s.push(slow->val);
        slow = slow->next;
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
        else
        {
            odd = true;
            break;
        }
    }
    std::stack<int> temp = s;

    if (odd)
    {
        s.pop();
    }

    while (slow)
    {
        if (slow->val != s.top())
        {
            return false;
        }
        s.pop();
        slow = slow->next;
    }
    return true;
}

int main()
{
    std::cout << std::boolalpha << isPalindrome(new ListNode(1, new ListNode(0, new ListNode(0, nullptr)))) << std::endl;
    std::cout << std::boolalpha << isPalindrome(new ListNode(1, new ListNode(0, new ListNode(0, new ListNode(1, nullptr))))) << std::endl;
    std::cout << std::boolalpha << isPalindrome(new ListNode(1, new ListNode(0, new ListNode(0, new ListNode(6, nullptr))))) << std::endl;
    std::cout << std::boolalpha << isPalindrome(new ListNode(1, new ListNode(0, new ListNode(1, nullptr)))) << std::endl;
}
