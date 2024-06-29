#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int inStart = 0;
        int inEnd = preorder.size() - 1;
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        TreeNode* ans = build(preorder, map, preIndex, inStart, inEnd);
        return ans;
    }

private:
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& map, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int inPos = map[root->val];
        root->left = build(preorder, map, preIndex, inStart, inPos - 1);
        root->right = build(preorder, map, preIndex, inPos + 1, inEnd);
        return root;
    }
};

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    vector<TreeNode*> currentLevel;
    currentLevel.push_back(root);
    while (!currentLevel.empty()) {
        vector<TreeNode*> nextLevel;
        for (TreeNode* node : currentLevel) {
            if (node) {
                cout << node->val << " ";
                nextLevel.push_back(node->left);
                nextLevel.push_back(node->right);
            } else {
                cout << "null ";
            }
        }
        currentLevel = nextLevel;
    }
    cout << endl;
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);

    printLevelOrder(root);

    return 0;
}
