#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool diffEqualsX(vector<int>& nums, int x){
    int low = 0;
    int high = 1;

    while(low < nums.size() && high < nums.size()){
        if(abs(nums[high] - nums[low]) == x){ 
        }
        else if(abs(nums[high] - nums[low]) < x){
            low++;
        }
        else{
            high++;
        }
    }
    return false;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 11}; 
    int target = 6;
    cout << "Answer: " << diffEqualsX(nums, target);
    return 0;
}
