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

TreeNode *LCA(TreeNode *root , int n1 , int n2){
    if(root ==NULL)
        return NULL;
    if(root->val == n1 || root->val == n2)
        return root;

    TreeNode *leftAns = LCA(root->left , n1 , n2);
    TreeNode *rightAns = LCA(root->right, n1, n2);

    if(leftAns != NULL && rightAns!= NULL)
        return root;
    else if(leftAns != NULL && rightAns == NULL)
        return leftAns;            
    else if(leftAns == NULL && rightAns != NULL)
        return rightAns;
    else    
        return NULL;            
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

    TreeNode *ans = LCA(root , 10 , 8);
    if(ans!=NULL)
        cout<<"Lowest Common Ancestor is "<<ans->val;
    else
        cout<<"Lowest Common Ancestor is not found";    
    return 0;
}