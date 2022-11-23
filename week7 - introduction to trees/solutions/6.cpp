#include <iostream>
#include <string>
#include <stack>

struct Node
{
    char val;
    Node *left, *right;

    Node(char val) : val{val}, left{nullptr}, right{nullptr}
    {
    }
};

void inorderTraversalUtil(Node *node)
{
    if (!node)
    {
        return;
    }
    inorderTraversalUtil(node->left);
    std::cout << node->val;
    inorderTraversalUtil(node->right);
}

void inorderTraversalrRec(Node *root)
{
    inorderTraversalUtil(root);
}

int getPrio(char c)
{
    switch (c)
    {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;

    default:
        break;
    }
    throw "Invalid operation\n";
}

void combine(std::stack<char> &ops, std::stack<Node *> &stack)
{
    Node *root = new Node(ops.top());
    ops.pop();
    // right first, then left
    root->right = stack.top();
    stack.pop();
    root->left = stack.top();
    stack.pop();

    stack.push(root);
}

Node *expTree(const std::string &s)
{

    std::stack<char> ops;
    std::stack<Node *> stack;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            ops.push(ch);
        }
        else if (isdigit(ch))
        {
            // TODO: make 2 digit numbers
            stack.push(new Node(ch));
        }
        else if (ch == ')')
        {
            while (ops.top() != '(')
            {
                combine(ops, stack);
            }
            // pop left '('
            ops.pop();
        }
        else
        {
            while (!ops.empty() && getPrio(ops.top()) >= getPrio(ch))
            { // @note: must be >=, for test case "1+2+3+4+5"
                combine(ops, stack);
            }

            ops.push(ch);
        }
    }

    while (stack.size() > 1)
    {
        combine(ops, stack);
    }

    return stack.top();
}

int main()
{
    std::string expr = "2-3/(5*2)+1";
    Node *root = expTree(expr);
    inorderTraversalrRec(root);
}