#include <vector>
#include <stdlib.h>

/*
The O(log N) search time is very nice. But, there is a problem: 
how do we implement insertions and removals efficiently, but in a 
way so that they maintain the structure of the multi-level list? This 
turns out to be quite a problem. AVL and red-black trees resolve it by tricky rebalancing operations.

Skip lists take an entirely different approach: a probabilistic
 one. Instead of ensuring that the level-2 list skips every 
 other node, a skip list is designed in a way that the level-2
  list skips one node on average. In some places, it may skip 
  two nodes, and in other places, it may not skip any nodes. 
  But overall, the structure of a skip list is very similar to 
  the structure of a sorted multi-level list.

Find the element in the set that is closest to some given value, in O(log N) time.
Find the k-th largest element in the set, in O(log N) time. Requires a simple  augmentation of the the skip list with partial counts.
Count the number of elements in the set whose values fall into a given range, in O(log N) time. Also requires a simple augmentation of the skip list.
*/

class Skiplist
{
private:
    struct ListNode
    {
        int val;
        ListNode *next = nullptr;
        ListNode *down = nullptr;
        ListNode(){};
        ListNode(int v, ListNode *n, ListNode *d) : val(v), next(n), down(d) {}
    };

    ListNode dummy;
    ListNode *head;

public:
    Skiplist() : head(&dummy)
    {
    }

    bool search(int target)
    {
        for (ListNode *node = head; node; node = node->down)
        {
            while (node->next && node->next->val < target)
            {
                node = node->next;
            }
            if (node->next && node->next->val == target)
            {
                return true;
            }
        }
        return false;
    }

    void add(int num)
    {
        std::vector<ListNode *> preNodes;
        for (ListNode *node = head; node; node = node->down)
        {
            while (node->next && node->next->val < num)
            {
                node = node->next;
            }
            preNodes.push_back(node);
        }

        bool rnd = true;
        ListNode *down = nullptr, *pre = nullptr;
        while (rnd && !preNodes.empty())
        {
            pre = preNodes.back();
            pre->next = new ListNode(num, pre->next, down);
            down = pre->next;
            preNodes.pop_back();
            rnd = rand() % 2;
        }
    }

    bool erase(int num)
    {
        bool found = false;
        for (ListNode *node = head; node; node = node->down)
        {
            while (node->next && node->next->val < num)
            {
                node = node->next;
            }
            if (node->next && node->next->val == num)
            {
                found = true;
                ListNode *p = node->next;
                node->next = p->next;
                delete p;
            }
        }
        return found;
    }
};