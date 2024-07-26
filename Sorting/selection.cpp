#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr){
    int n = arr.size();
    int k;
    for(int i = 0;i<n-1;i++){
        for(int j = k = i;j<n;j++){
            if(arr[j]<arr[i])
                k = j;
        }

        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

int main(){
    vector<int>arr = {12,33,14,131,43,21,12};
    selectionSort(arr);
    for(int i : arr){
        cout<<" "<<i;
    }
}