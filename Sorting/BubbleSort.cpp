#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n = arr.size();
    for(int i =0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    vector<int>arr = { 12,33,14,131,43,21,12};
    bubbleSort(arr);
    for(int i : arr){
        cout<<" "<<i;
    }
}