//Pascal Triangle 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>CreatePascalTriangle(int n){
    vector<vector<int>> pascal(n);
    for (int i = 0; i < n;i++){
        pascal[i].resize(i + 1);
        for (int j = 0; j <= i;j++){
            if (j == 0 || j==i){
                pascal[i][j] = 1;
            }
            else{
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            }
        }
    }
    return pascal;
}

int main(){
    int n;
    cout << "Enter No : ";
    cin >> n;
    vector<vector<int>> result = CreatePascalTriangle(n);

    for (int i = 0; i < n;i++){
        for (int j = 0; j <= i  ;j++){
            cout << " " << result[i][j];
        }
        cout << endl;
    }
}