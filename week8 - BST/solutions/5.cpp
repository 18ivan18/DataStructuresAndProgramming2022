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

// recusion
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (!root)
    {
        return new TreeNode(val);
    }
    if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

// iteration 1
TreeNode *insertIntoBST1(TreeNode *root, int val)
{
    if (!root)
    {
        return new TreeNode(val);
    }
    TreeNode *curNode = root;
    while (true)
    {
        if (curNode->val > val)
        {
            if (!curNode->left)
            {
                curNode->left = new TreeNode(val);
                break;
            }
            curNode = curNode->left;
        }
        if (curNode->val < val)
        {
            if (!curNode->right)
            {
                curNode->right = new TreeNode(val);
                break;
            }
            curNode = curNode->right;
        }
    }
    return root;
}

// iteration 2
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (!root)
    {
        return new TreeNode(val);
    }
    TreeNode *curNode = root;
    TreeNode *preNode = 0;
    while (!curNode)
    {
        preNode = curNode;
        if (curNode->val > val)
        {
            curNode = curNode->left;
        }
        else
        {
            curNode = curNode->right;
        }
    }
    if (preNode->val > val)
    {
        preNode->left = new TreeNode(val);
    }
    else
    {
        preNode->right = new TreeNode(val);
    }
    return root;
};