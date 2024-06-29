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


//vertical traversal of tree
vector<int>verticalTraversal(TreeNode *root){
    map<int,map<int,vector<int>>>nodes;
    queue<pair<TreeNode *, pair<int , int>>>q;
    vector<int>result;

    if(root==nullptr)
        return result;

    q.push(make_pair(root,make_pair(0,0)));

    while (!q.empty()){ 
        pair<TreeNode*,pair<int,int>>temp = q.front();
        q.pop();

        TreeNode *frontNode = temp.first;
        int horizontal_line = temp.second.first;
        int vertical_Line = temp.second.second;

        nodes[horizontal_line][vertical_Line].push_back(frontNode->val);

        if(frontNode->left)
            q.push(make_pair(frontNode->left,make_pair(horizontal_line-1,vertical_Line+1)));
        if(frontNode->right)
            q.push(make_pair(frontNode->right,make_pair(horizontal_line+1,vertical_Line+1)));
    }
    
    for(auto i:nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                result.push_back(k);
            }
        }
    }

    return result;
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

    vector<int>result = verticalTraversal(root);
    for(auto i : result)
        cout<<" "<<i;
    return 0;
}