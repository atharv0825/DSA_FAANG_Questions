#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x),left(NULL),right(NULL){}
};

TreeNode *find(TreeNode *root){
    TreeNode *predecessor = root->left;
    while(predecessor->right != NULL && predecessor->right != root){
        predecessor = predecessor->right;
    } 
    return predecessor;
}

void morrisTraversal(TreeNode *root){
    if(root==NULL)
        return;
        
    TreeNode *currentNode = root;

    while(currentNode!=NULL){
        if(currentNode->left == NULL){
            cout<<" "<<currentNode->data;
            currentNode = currentNode->right;
        }
        else{
            TreeNode *predecessor = find(currentNode);
            if(predecessor->right == NULL){
                predecessor->right = currentNode;
                currentNode = currentNode->left;
            }
            else{
                predecessor->right = NULL;
                cout<<" "<<currentNode->data;
                currentNode = currentNode->right;
            }
        }
    }    
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);
    root->right->right= new TreeNode(6);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->left->left->right = new TreeNode(7);

    morrisTraversal(root);
    return 0;
}