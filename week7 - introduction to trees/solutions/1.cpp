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

std::vector<int> result;
void inorderTraversalUtil(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    inorderTraversalUtil(node->left);
    result.push_back(node->val);
    inorderTraversalUtil(node->right);
}

std::vector<int> inorderTraversalrRec(TreeNode *root)
{
    inorderTraversalUtil(root);
    return result;
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::stack<TreeNode *> st;
    TreeNode *node = root;
    while (node != nullptr || !st.empty())
    {
        while (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop();
        result.push_back(node->val);
        node = node->right;
    }
    return result;
}