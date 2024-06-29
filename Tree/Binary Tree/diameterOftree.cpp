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

pair<int,int>diameterFast(TreeNode *root){
    if(root==NULL){
        pair<int,int>p = make_pair(0,0);
        return p;
    }

    pair<int,int>left =  diameterFast(root->left);
    pair<int,int>right = diameterFast(root->right);
        
    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second +1;

    pair<int ,int>ans;
    ans.first = max(opt1,max(opt2,opt3));
    ans.second = max(left.second , right.second)+1;

    return ans;  
}

int diameter(TreeNode *root){
    
    return diameterFast(root).first;
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

    cout<<"Diameter of tree : "<<diameter(root);

    return 0;
}