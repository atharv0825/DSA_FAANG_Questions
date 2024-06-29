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

pair<bool,int>balanced(TreeNode *root){
    if(root == NULL){
        pair<bool,int>p = make_pair(true,0);
        return p;
    }

    pair<bool,int>left = balanced(root->left);
    pair<bool,int>right = balanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff =abs(left.second-right.second)<=1;

    pair<bool,int>ans;
    ans.second = max(left.second,right.second)+1;
    
    if(diff&&leftAns&&rightAns)
        ans.first = true;    
    else 
        ans.first = false;

    return ans;
}

bool balance(TreeNode *root){
    return balanced(root).first;
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

    if(balance(root)){
        cout<<"IT IS BALANCED TREE";
    }else{
        cout<<"IT IS NOT BALANCED TREE";
    }
    return 0;
}