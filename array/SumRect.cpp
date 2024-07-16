//(l1,r1) and (l2,r2) is given from the array M X N so find the sum of the rectangle created by the that two co ordinates;
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int SumOfRectangle(vector<vector<int>>nums, int l1 , int l2  , int r1 , int r2){
    int sum = 0;
    for (int i = l1; i <= l2;i++){
        for (int j = r1; j <= r2;j++){
            sum += nums[i][j];
        }
    }
    return sum;
}

int main(){
    vector<vector<int>> array;
    int row, col;
    cout << "Enter the row and column : ";
    cin >> row >> col;
    array.resize(row, vector<int>(col));
    for (int i = 0; i < row;i++){
        for (int j = 0; j < col;j++){
            cout << "Enter For (" << i << "," << j << ") : ";
            cin >> array[i][j];
        }
    }
    int l1, l2, r1, r2;
    cout << "Enter ( l1,r1 ) : ";
    cin >> l1 >> r1;
    cout << "Enter ( l2,r2 ) : ";
    cin >> l2 >> r2;

    cout<<SumOfRectangle(array, min(l1,l2), max(l1,l2), min(r1,r2), max(r1,r2));

}