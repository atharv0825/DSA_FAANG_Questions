// There are 2D matrix is given in sorted order so find the left most 1 in the matrix
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void findLeftMost1InRow(vector<vector<int>>&nums){
    int column = nums[0].size();
    int leftMost1Row = -1;
    int leftMost1Index = -1;
    for (int j = 0; j < nums.size();j++){
        for (int i = 0; i < column;i++){
            if(nums[j][i] == 1){
                leftMost1Row = j;
                leftMost1Index = i;
                break;
            }
            
        }
    }
    cout << "Left Most Row contains one : " << leftMost1Row << endl
         << "Left Most Index contains one : "<<leftMost1Index<<endl;
}
int main(){
    vector<vector<int>> array;
    int row , column;
    cout << "Enter the row And Column : ";
    cin >> row >> column;
    array.resize(row, vector<int>(column));
    for (int i = 0; i < row;i++){
        for (int j = 0; j < column;j++){
            cout<<"Enter for ("<<i<<","<<j<<"): ";
            cin >> array[i][j];
        }
    }

   findLeftMost1InRow(array);
    return 0;
}