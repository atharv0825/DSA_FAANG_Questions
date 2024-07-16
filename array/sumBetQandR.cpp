//given array of integer find integer of size n answer q quires where you need to print the sum of values in given range of indices from l to R
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int sumBetQandR_Quires(vector<int>&nums, int &quires){
    //cumulative sum
    for (int i = 1; i < nums.size();i++){
        nums[i] += nums[i - 1];
    }
    int result = 0;
    while (quires--){
        int low, high;
        cout << "Enter Quires range : ";
        cin >> low >> high;

        result = nums[high] - nums[low - 1];
        cout << "Sum : " << result << endl;
    }
    return 0;
}

int main(){
    vector<int> nums;
    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    nums.insert(nums.begin(),0);
    int quires;
    for(int i : nums){
        cout << " " << i;
    }
    cout<<"\nEnter no of quires : ";
    cin >> quires;
    sumBetQandR_Quires(nums, quires);
    return 0;
}