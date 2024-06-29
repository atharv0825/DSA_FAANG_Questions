#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode *root){
    if(root == nullptr)
        return 0;
    int opt1 = height(root->left);
    int opt2 = height(root->right);

    int ans = max(opt1 , opt2)+1;
    return ans;     
}


int main(){
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

    cout<<" Height of Tree :-  "<<height(root);
    return 0;
}