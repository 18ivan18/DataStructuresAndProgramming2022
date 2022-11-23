#include <iostream>
#include <queue>

struct TreeNode
{
    int value;
    TreeNode *left = nullptr, *right = nullptr;

    TreeNode(int value) : value{value} {}
};

std::vector<std::vector<int>> levelOrderTraversal(TreeNode *node)
{

    std::queue<TreeNode *> q;
    if (node)
    {
        q.push(node);
    }
    std::vector<std::vector<int>> result;
    while (!q.empty())
    {
        int levelSize = q.size();
        std::vector<int> level;
        for (size_t i = 0; i < levelSize; i++)
        {
            TreeNode *root = q.front();
            q.pop();
            level.push_back(root->value);
            if (root->left)
            {
                q.push(root->left);
            }
            if (root->right)
            {
                q.push(root->right);
            }
        }
        result.push_back(level);
    }
    return result;
}

void print(std::vector<std::vector<int>> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << '[';
        for (size_t j = 0; j < v[i].size(); j++)
        {
            std::cout << v[i][j];
            if (j != v[i].size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i != v.size() - 1)
        {
            std::cout << ", ";
        }
    }

    for (auto i = v.begin(); i != v.end(); i++)
    {
        std::cout << '[';
        for (auto j = (*i).begin(); j != (*i).end(); j++)
        {
            std::cout << *j;
            if (j != (*i).end() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i != v.end() - 1)
        {
            std::cout << ", ";
        }
    }

    for (const std::vector<int> &i : v)
    {
        std::cout << '[';
        for (const int &val : i)
        {
            std::cout << val << " ";
        }
        std::cout << "], ";
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *TreeNode1 = new TreeNode(2);
    TreeNode *TreeNode2 = new TreeNode(3);
    TreeNode *TreeNode3 = new TreeNode(4);
    TreeNode *TreeNode4 = new TreeNode(5);
    TreeNode *TreeNode5 = new TreeNode(6);
    root->left = TreeNode1;
    root->right = TreeNode2;
    TreeNode1->left = TreeNode3;
    TreeNode1->right = TreeNode4;
    TreeNode2->left = TreeNode5;
    print(levelOrderTraversal(root));
    std::cout << std::endl;
}