//move zeros at end with maintaining relative order
//Note: that you must do this in-place without making a copy of the array.
#include<bits/stdc++.h>
using namespace std;

void moveZeros(vector<int>&nums){
    int size = nums.size();
    int i = 0;

    while (i<size)
    {
        if(nums[i] == 0)
            break;
        i++;    
    }

    for(int j = i+1;j<size;j++){
        if(nums[j] != 0){
            swap(nums[i],nums[j]);
            i++;
        }
    }
    return;
}

int main(){
    vector<int>nums = {0,1,0,3,12};
    moveZeros(nums);
    for(int i:nums){
        cout<<" "<<i;
    }
}