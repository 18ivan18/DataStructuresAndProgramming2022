#include <vector>
#include <iostream>

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right = nullptr) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root, std::vector<int> &arr)
{
    if (!root)
    {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

int kthBiggest(TreeNode *root, int k)
{
    std::vector<int> nums;
    inorder(root, nums);
    return nums.at(nums.size() - k);
    // smallest
    // return nums.at(k - 1);
}

#include <stack>

int kthSmallestStack(TreeNode *root, int k)
{
    std::stack<TreeNode *> stack;

    // O(n)
    while (true)
    {
        while (root)
        {
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        if (--k == 0)
        {
            return root->val;
        }
        root = root->right;
    }
}