#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void commutativeSum(vector<int>&array){
    for (int i = 1; i < array.size();i++){
        array[i] += array[i - 1];
    }
    return;
}

int main(){
    vector<int>array = {1,2,3,4,5,6,7,8,9,10};
    commutativeSum(array);
    for (int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
}
