#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&arr){
    int n =  arr.size();
    for(int i =1;i<n;i++){
			int j = i-1;
			int x = arr[i];
			while(j>-1 && arr[j]>x){
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = x;
		}
}


int main(){
    vector<int>arr = {12,33,14,131,43,21,12};
    insertionSort(arr);
    for(int i : arr){
        cout<<" "<<i;
    }
}