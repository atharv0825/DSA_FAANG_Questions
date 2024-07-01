#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* mapParent(TreeNode *root, int target, unordered_map<TreeNode*, TreeNode*>& parentMap) {
    TreeNode *result = NULL;
    queue<TreeNode*> q;

    q.push(root);
    parentMap[root] = NULL;

    while (!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();

        if (temp->val == target)
            result = temp;
        if (temp->left) {
            q.push(temp->left);
            parentMap[temp->left] = temp;
        }
        if (temp->right) {
            q.push(temp->right);
            parentMap[temp->right] = temp;
        }
    }
    return result;
}

int burnTree(TreeNode *targetNode, unordered_map<TreeNode*, TreeNode*> parentMap) {
    queue<TreeNode*> q;
    unordered_map<TreeNode*, bool> visited;
    int count = 0;

    q.push(targetNode);
    visited[targetNode] = true;

    while (!q.empty()) {
        int size = q.size();
        bool flag = false;

        for (int i = 0; i < size; i++) {
            TreeNode* currentNode = q.front();
            q.pop();

            if (currentNode->left && !visited[currentNode->left]) {
                flag = true;
                q.push(currentNode->left);
                visited[currentNode->left] = true;
            }
            if (currentNode->right && !visited[currentNode->right]) {
                flag = true;
                q.push(currentNode->right);
                visited[currentNode->right] = true;
            }
            if (parentMap[currentNode] && !visited[parentMap[currentNode]]) {
                flag = true;
                q.push(parentMap[currentNode]);
                visited[parentMap[currentNode]] = true;
            }
        }
        if (flag) {
            count++;
        }
    }
    return count;
}

int timeToBurn(TreeNode *root, int target) {
    unordered_map<TreeNode*, TreeNode*> parentMap;
    TreeNode *targetNode = mapParent(root, target, parentMap);
    if (targetNode == NULL) return -1; // If the target node is not found
    return burnTree(targetNode, parentMap);
}

int main() {
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

    cout << "Enter Target : ";
    int target;
    cin >> target;

    int time = timeToBurn(root, target);
    if (time == -1) {
        cout << "Target node not found in the tree." << endl;
    } else {
        cout << "Time to burn tree : " << time << endl;
    }

    return 0;
}
