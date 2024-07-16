//matrix entered by the user try to find transpose of the matrix
//      0   1           0   1
// 0    10  20      0   10  30      (0,0)  (0,1)      there is change in I and J of every element 
// 1    30  40      1   20  40      (1,0)  (1,1)   
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>TransposeOfArray(vector<vector<int>>&nums, int row , int column){
    vector < vector<int>>result(column , vector<int>(row));
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column;j++){
            result[j][i] = nums[i][j];
        }
    }
    return result;
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

    vector<vector<int>>result = TransposeOfArray(array, row, column);

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column;j++){
            cout << " " << result[i][j];
        }
        cout << endl;
    }
}