//merge two sorted array
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&nums1,int n,vector<int>&nums2,int m){
    nums1.resize(m+n);
    int pos1 = n-1;
    int pos2 = m-1;
    int start = m+n-1;

    while(pos1>=0&&pos2>=0){
        if(nums1[pos1]<=nums2[pos2]){
            nums1[start] = nums2[pos2];
            pos2--;
            start--;
        }
        else{
            nums1[start] = nums1[pos1];
            pos1--;
            start--;
        }
    }

    while (pos2>=0)
    {
        nums1[start] = nums2[pos2];
        pos2--;
        start--;
    }
    

}

int main(){
    vector<int>nums1 = {10,20,30,40};
    vector<int>nums2 = {15,25,35,45};

    merge(nums1,nums1.size(),nums2,nums2.size());

    for(int i : nums1)
        cout<<i<<" ";

    return 0;    
}