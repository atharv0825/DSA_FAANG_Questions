// merge two sorted array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>mergeSortedArray(vector<int>&nums1 , vector<int>nums2){
    int i=0, j=0;
    vector<int> result;
    while(i<nums1.size()&&j<nums2.size()){
        if(nums1[i] < nums2[j]){
            result.push_back(nums1[i]);
            i++;
        }
        else{
            result.push_back(nums2[j]);
            j++;
        }
    }
    while(i<nums1.size()){
        result.push_back(nums1[i]);
        i++;
    }
    while(j<nums2.size()){
        result.push_back(nums2[j]);
        j++;
    }

    return result;
}

int main(){
    vector<int> nums1 = {10,11};
    vector<int> nums2 = {1,6,13,24};

    vector<int> result = mergeSortedArray(nums1, nums2);

    for(int nums : result){
        cout << nums <<" ";
    }
    return 0;
}