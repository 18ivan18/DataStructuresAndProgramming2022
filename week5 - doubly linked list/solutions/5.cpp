// TODO: make it into a class
struct Node
{
    int data;
    Node *next, *random;

    // Constructor
    Node(int data) : data{data}, next{nullptr}, random{nullptr}
    {
    }
};

void reverse(Node *&head)
{
    Node *prev = nullptr; // the previous pointer
    Node *curr = head;    // the main pointer

    // traverse the list
    while (curr)
    {
        // tricky: note the next node
        Node *next = curr->next;

        curr->next = prev; // fix the `curr` node

        // advance the two pointers
        prev = curr;
        curr = next;
    }

    // fix the head pointer to point to the new front
    head = prev;
}

void setRandomNodes(Node *head)
{
    // Reverse the linked list
    reverse(head);

    // max points to the node with maximum value
    Node *max = head;
    head->random = nullptr;

    // start from the second node in the list
    Node *node = head->next;
    while (node)
    {
        // update random pointer of the current node to point to the
        // maximum value node so far
        node->random = max;

        // update max if the current node is greater
        if (max->data < node->data)
        {
            max = node;
        }

        // advance to the next node
        node = node->next;
    }

    // restore the linked list original order
    reverse(head);
}
