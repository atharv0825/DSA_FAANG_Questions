#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int preSumRectangle(vector<vector<int>>nums, int l1 , int l2 , int r1 , int r2){
    int sum = 0;
    for (int i = 0; i < nums.size();i++){
        for (int j = 0; j < nums[0].size();j++){
            nums[i][j] += nums[i][j - 1];
        }
    }

    for (int i = l1; i <= l2;i++){
        if(r1!=0){
            sum += nums[i][r2] - nums[i][r1-1];
        }
        else{
            sum += nums[i][r2];
        }    
    }
    return sum;
}

int main(){
    vector<vector<int>> array;
    int row, col;
    cout << "Enter the row and column : ";
    cin >> row >> 
    col;
    array.resize(row, vector<int>(col));
    for (int i = 0; i < row;i++){
        for (int j = 0; j < col;j++){
            cout << "Enter For (" << i << "," << j << ") : ";
            cin >> array[i][j];
        }
    }
    int l1, l2, r1, r2;
    cout << "Enter (l1,r1) : ";
    cin >> l1 >> r1;
    cout << "Enter (l2,r2) : ";
    cin >> l2 >> r2;

    int sum = preSumRectangle(array, min(l1, l2), max(l1, l2), min(r1, r2), max(r1, r2));
    cout << "Sum (" << l1 << "," << r1 << ") to (" << l2 << "," << r2 << ") : " << sum;
}