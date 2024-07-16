//Given an 2d array matrix rotate the given matrix in 90 degrees;
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void RotateTheArray(vector<vector<int>>&nums , int n ){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i;j++){
            swap(nums[j][i], nums[i][j]);
        }
    }

    for (int i = 0; i < n;i++){
        reverse(nums[i].begin(), nums[i].end());
    }
}

int main(){
    vector<vector<int>>array;
    int n;
    cout<<"Enter the Row And column : ";
    cin >> n;
    array.resize(n, vector<int>(n));

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cout<<"Enter for ("<<i<<","<<j<<") :";
            cin >> array[i][j];
        }
    }

    RotateTheArray(array , n);
    
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cout << " " << array[i][j];
        }
        cout << endl;
    }
}
