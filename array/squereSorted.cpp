//in the given non decreasing array , if we take square's of that array they are not sorted make it sorted.
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>sortSquares(vector<int>&nums){
    int left = 0;
    int right = nums.size()-1;
    int n = nums.size();
    vector<int>result(nums.size());
    int index = nums.size() - 1;
    while(left <= right){
        if(abs(nums[left]) < abs(nums[right])){
            result[index--] = (nums[right] * nums[right]);
            right--;
        }
        else{
            result[index--] = (nums[left]*nums[left]);
            left++;
        }
    }
    // sort(result.begin(), result.end());
    return result;
}

int main(){
    vector<int> nums = {-10,-4, 3, 5, 7, 9};
    vector<int>result = sortSquares(nums);
    for (int i = 0; i < result.size();i++){
        cout << result[i] << " ";
    }
    return 0;
}