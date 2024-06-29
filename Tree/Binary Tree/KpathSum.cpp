#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
        int sumK(Node *root , int target){
            int count =0;
            vector<int>path;
            solve(root, count , target , path);
            return count;
        }
    private:
        void solve(Node *root,int &count,int target,vector<int>path){
            if(root==NULL)
                return;

            path.push_back(root->data);

            solve(root->left,count,target,path);
            solve(root->right,count,target,path);

            int sum =0;
            int size = path.size()-1;
            for(int i =size;i>=0;i--){
                sum+=path[i];
                if(sum==target)
                    count++;
            }

            path.pop_back();
        }    
};



int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    
    int target = 10;
    
    Solution solution;
    int result = solution.sumK(root, target);
    
    cout << "Number of paths with sum " << target << ": " << result << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}