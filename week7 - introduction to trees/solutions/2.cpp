#include <vector>
#include <stack>
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
#include <string>

std::vector<std::string> binaryTreePaths(TreeNode *root)
{
    if (root == nullptr)
    {
        std::vector<std::string> v;
        return v;
    }
    else if (root->left == nullptr && root->right == nullptr)
    {
        std::vector<std::string> v;
        v.push_back(std::to_string(root->val));
        return v;
    }

    std::vector<std::string> left = binaryTreePaths(root->left);
    for (int i = 0; i < left.size(); ++i)
    {
        left[i] = std::to_string(root->val) + "->" + left[i];
    }

    std::vector<std::string> right = binaryTreePaths(root->right);
    for (int i = 0; i < right.size(); ++i)
    {
        right[i] = std::to_string(root->val) + "->" + right[i];
    }

    std::vector<std::string> res;
    for (auto x : left)
    {
        res.push_back(x);
    }
    for (auto x : right)
    {
        res.push_back(x);
    }
    return res;
}
