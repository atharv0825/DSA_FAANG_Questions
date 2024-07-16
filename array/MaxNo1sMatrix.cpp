//there are given of 2D array each row is in sorted order so find max no of 1's
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int MAxNoof1s(vector<vector<int>>&nums){
    int maxOnes = INT16_MIN;
    int maxoneRow = -1;
    int column = nums[0].size();
    for (int i = 0; i < nums.size();i++){
        for (int j = 0; j < nums[i].size();j++){
            if(nums[i][j] == 1){
                int NoOfOnes = column - j;
                if(NoOfOnes > maxOnes){
                    maxOnes = NoOfOnes;
                    maxoneRow = i;
                }
                break;
            }
        }
    }
    return maxOnes;
}

int main(){
    vector<vector<int>> array;
    int row , column;
    cout << "Enter row and column: ";
    cin >> row >> column;
    array.resize(row, vector<int>(column));
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column;j++){
            cout << "Enter for (" << i << "," << j << ") : ";
            cin >> array[i][j];
        }
    }

    cout << "Max no of ones in rows :  " << MAxNoof1s(array);
}