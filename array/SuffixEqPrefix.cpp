//partition of a array into two sub array the sum of prefix sub array is equals to the suffix sub array
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool prefixEqualsSuffix(vector<int> &nums){
    int totalSum = 0;
    for (int i = 0; i < nums.size();i++){
        totalSum += nums[i];
    }

    int prefixSum = 0;
    int suffixSum = 0;

    for (int i = 0; i < nums.size();i++){
        prefixSum += nums[i];
        suffixSum = totalSum - prefixSum;
        if(prefixSum == suffixSum){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    if(prefixEqualsSuffix(nums)){
        cout << "There is suffix equals to prefix" << endl;
    }
    else{
        cout << "There is no suffix equals to prefix" << endl;
    }
    return 0;
}