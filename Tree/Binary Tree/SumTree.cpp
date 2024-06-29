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

//method 1: 

void solve(TreeNode* root ,int sum , int &maxSum,int len ,int &maxLen){

    if(root==NULL){
        if(len>maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len==maxLen){
            maxSum = max(sum,maxSum);
        }
        return;
    }

    sum += root->val;

    solve(root->left,sum,maxSum,len+1,maxLen); 
    solve(root->right,sum,maxSum,len+1,maxLen); 
}

int sumOfRootToLeaf(TreeNode *root){
    int sum =0;
    int len =0;
    int maxLen =0;
    int maxSum = INT32_MIN;

    solve(root,sum,maxSum,len,maxLen);    

    return maxSum;
}

//Method 2:

pair<int,int>countSum(TreeNode * root){
    if(root==NULL){
        pair<int,int>p = make_pair(0,0);//(height , sum);
        return p;
    }

    pair<int,int>left =countSum(root->left);
    pair<int,int>right= countSum(root->right);

    pair<int,int>ans;
    if(left.first ==right.first){
        ans.first = left.first+1;
        ans.second = max(left.second,right.second)+root->val;
    }
    else if(left.first<right.first){
        ans.first=right.first+1;
        ans.second = right.second + root->val;
    }
    else{
        ans.first = left.first+1;
        ans.second = left.second+root->val;
    }

    return ans;
}   

int sumOfRootToLeaf2(TreeNode *root){
    return countSum(root).second;
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

    cout<<"Longest path sum : "<<sumOfRootToLeaf(root)<<endl;
    cout<<"Longest path sum : "<<sumOfRootToLeaf2(root)<<endl;

}