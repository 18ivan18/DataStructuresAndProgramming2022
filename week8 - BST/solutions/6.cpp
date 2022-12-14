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

TreeNode *deleteMin(TreeNode *x)
{
    if (x->left == nullptr)
    {
        return x->right;
    }
    x->left = deleteMin(x->left);
    return x;
}
TreeNode *min(TreeNode *x)
{
    if (x->left == nullptr)
    {
        return x;
    }
    return min(x->left);
}
TreeNode *deleteNode(TreeNode *x, int key)
{
    if (!x)
    {
        return nullptr;
    }
    if (x->val == key)
    {
        auto toDelete = x;
        if (!x->left)
        {
            auto toReturn = x->right;
            delete toDelete;
            return toReturn;
        }
        if (!x->right)
        {
            auto toReturn = x->left;
            delete toDelete;
            return toReturn;
        }
        TreeNode *t = x;
        x = min(t->right);
        x->right = deleteMin(t->right);
        x->left = t->left;
        delete toDelete;
    }
    else if (x->val < key)
    {
        x->right = deleteNode(x->right, key);
    }
    else if (x->val > key)
    {
        x->left = deleteNode(x->left, key);
    }
    return x;
}