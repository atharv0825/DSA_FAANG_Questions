#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void traverseLeft(TreeNode *root , vector<int>&ans){
    if((root == nullptr)|| (root->left==nullptr&&root->right ==nullptr))
        return;
    ans.push_back(root->val);
    if(root->left)
        traverseLeft(root->left,ans);
    else    
        traverseLeft(root->right,ans);        
}

void traverseLeaf(TreeNode *root , vector<int>&ans){
    if(root==nullptr)
        return;

    if(root->left==nullptr && root->right == nullptr ){
        ans.push_back(root->val);
        return;
    }    

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(TreeNode *root , vector<int>&ans){
    if((root==nullptr)||(root->left==nullptr&&root->right==nullptr))
        return;

    if(root->right)
        traverseRight(root->right , ans);
    else
        traverseRight(root->left, ans);    

    ans.push_back(root->val);

}

vector<int>boundaryElement(TreeNode *root){ 
    vector<int>ans;    
    if(root==NULL)
        return ans;
    ans.push_back(root->val);    
    //left traverse    
    traverseLeft(root->left,ans);
    //Root left leaf traverse
    traverseLeaf(root->left,ans);
    //root right leaf traverse   
    traverseLeaf(root->right,ans); 
    //traverse right side of root
    traverseRight(root->right,ans);
    return ans;
}

int main(){
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

    vector<int>result = boundaryElement(root);
    for(auto i : result)
        cout<<" "<<i;
    return 0;
}