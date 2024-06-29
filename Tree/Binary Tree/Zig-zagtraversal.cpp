#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// zig - zag traversal
vector<int> zigZagTraversal(TreeNode *root)
{
    // Code here
    vector<int> result;
    if (root == NULL)
        return result;

    bool direction = true;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            int index = (direction) ? i : size - 1 - i;
            ans[index] = temp->val;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        direction = !direction;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);

    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = zigZagTraversal(root);
    for (auto i : result)
        cout << " " << i;
    return 0;
}