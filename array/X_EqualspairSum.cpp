// there is given vector of size n and integer x check that there is pair in array equals integer
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPairExistThere(vector<int>&nums , int x){
    int low = 0;
    int high = nums.size()-1;

    while(low < high){
        int totalSum = nums[low] + nums[high];
        if(totalSum == x){
            return true;
        }
        else if(totalSum < x){
            low++;
        }
        else{
            high--;
        }
    }
    return false;
}

int main(){
    vector<int> array = {1, 2, 3, 4, 5};
    int target = 10;
    cout<<"Ans :  " << isPairExistThere(array, target);
    return 0;
}