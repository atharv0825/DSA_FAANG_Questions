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

vector<int> rightView(TreeNode *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> nodes;
    queue<pair<TreeNode *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<TreeNode *, int> temp = q.front();
        q.pop();

        TreeNode *currentNode = temp.first;
        int verticalLine = temp.second;

        nodes[verticalLine] = currentNode->val;

        if (currentNode->left)
            q.push(make_pair(currentNode->left, verticalLine + 1));
        if (currentNode->right)
            q.push(make_pair(currentNode->right, verticalLine + 1));
    }

    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(9);
    root->left->left->left->right = new TreeNode(10);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);
    root->right->right->right->right = new TreeNode(8);

    vector<int> result = rightView(root);
    for (auto i : result)
        cout << " " << i;
    return 0;
}