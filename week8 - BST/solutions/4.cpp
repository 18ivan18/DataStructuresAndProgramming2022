/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
    while (root && root->val != val)
    {
        root = root->val < val ? root->right : root->left;
    }
    return root;
}

TreeNode *searchBST(TreeNode *root, int val)
{
    return (!root || root->val == val) ? root : root->val < val ? searchBST(root->right, val)
                                                                : searchBST(root->left, val);
}