struct Node
{
    int val;
    Node *next;
    Node(int x = 0, Node *next = nullptr) : val(x), next(next) {}
};

Node *insert(Node *head, int insertValue)
{
    Node *prev = head, *curr = prev->next;
    while (curr != head)
    {
        if (prev->val <= insertValue && curr->val >= insertValue)
        {
            break;
        }
        if (prev->val > curr->val && (prev->val <= insertValue || curr->val >= insertValue))
        {
            break;
        }

        prev = curr;
        curr = curr->next;
    }
    prev->next = new Node(insertValue, curr);
    return head;
}

#include <iostream>
void print(Node *head)
{
    Node *temp = head;
    do
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    } while (head != temp);
}

int main()
{
    Node *head2 = new Node(2, nullptr);
    Node *head1 = new Node(4, head2);
    Node *head = new Node(3, head1);
    head2->next = head;

    print(insert(head, 5));
    std::cout << std::endl;
}