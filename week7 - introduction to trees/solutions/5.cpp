#include <iostream>
#include <string>
#include <queue>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode(char val) : val{val}, left{nullptr}, right{nullptr}
    {
    }
};

std::vector<int> rightSideView(TreeNode *root)
{
    //handle edge cases
    if (root == nullptr)
    {
        return {};
    }
    std::vector<int> solution;
    //create queue for BFS
    std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        //obtain the size of the queue to only check the nodes at each level
        int size = queue.size();
        while (size > 0)
        {
            TreeNode *current = queue.front();
            queue.pop();
            //if the left child is not nullptr it can be added to the tree
            if (current->left != nullptr)
            {
                queue.push(current->left);
            }
            //if the right child is not nullptr it can be added to the tree
            if (current->right != nullptr)
            {
                queue.push(current->right);
            }
            //if the element is the last one, it means that it's the right side view node
            if (size == 1)
            {
                solution.push_back(current->val);
            }
            size--;
        }
    }
    return solution;
}

int main()
{
}