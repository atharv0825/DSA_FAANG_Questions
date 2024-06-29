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

bool isIdentical(TreeNode *r1, TreeNode *r2)
    {
        if(r1==NULL&&r2==NULL)
            return true;
        if(r1 != NULL && r2 == NULL)
            return false;
        if(r1 == NULL && r2 != NULL)
            return false;
        
    
        return (r1->val == r2->val)&&isIdentical(r1->left,r2->left)&&isIdentical(r1->right,r2->right);
    }

int main()
{
    TreeNode *root1 = nullptr;
    root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode *root2 = nullptr;
    root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    // root2->left->left = new TreeNode(4); 
    

    if(isIdentical(root1,root2)){
        cout<<"TREE IS IDENTICAL";
    }else{
        cout<<"TREE IS NOT IDENTICAL";
    }

    return 0;
}