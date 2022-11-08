struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void deleteNode(ListNode *node)
{

    node->val = node->next->val;
    // 4 -> 1 -> 1 -> 9
    //      |
    //     node
    ListNode *tmp = node->next;
    node->next = node->next->next;
    // 4 -> 1 -> 9
    //      |
    //     node
    delete tmp;
}