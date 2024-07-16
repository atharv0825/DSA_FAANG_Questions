#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> getRow(int n) {
    vector<int> result(n + 1, 1);
    for (int i = 2; i <= n;i++){
        for (int j = i - 1; j > 0;j--){
            result[j] += result[j - 1];
        }
    }
    return result;
}   

int main(){
    int n;
    cout << "Enter No : ";
    cin >> n;
    vector<int> result = getRow(n);

    for (int i = 0; i < result.size();i++){
        cout << " " << result[i];
        
    }
}

