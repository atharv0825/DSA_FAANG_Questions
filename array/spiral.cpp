#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void spiralOutputOfMatrix(vector<vector<int>>&nums){
    int left = 0;
    int right = nums[0].size() - 1;
    int top = 0;
    int bottom = nums.size() - 1;
    int direction = 0;
    while(left<=right && top<=bottom){
        if(direction == 0){
            for (int col = left; col <= right;col++){
                cout << " " << nums[top][col];
            }
            top++;
        }
        else if(direction == 1){
            for (int row = top; row <= bottom;row++){
                cout << " " << nums[row][right];
            }
            right--;
        }
        else if(direction == 2){
            for (int col = right; col >= left;col--){
                cout << " " << nums[bottom][col];
            }
            bottom--;
        }
        else{
            for (int row = bottom; row >= top; row--){
                cout << " " << nums[row][left];
            }
            left++;
        }

        direction = (direction + 1) % 4;
    }
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
    spiralOutputOfMatrix(array);
}