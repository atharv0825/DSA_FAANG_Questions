// Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>&boards, int noOfBoards , int k , int mid){
    int painterCount = 1;
    int areaSum = 0;

    for(int i =0;i<noOfBoards;i++){
        if(boards[i]+areaSum <= mid){
            areaSum += boards[i];
        }
        else{
            painterCount++;
            if(painterCount>k || boards[i] > mid)
                return false;
            areaSum = boards[i];   
        }
        if(painterCount > k)
            return false;
    }
    return true;
}

int findLargestMinDistance(vector<int>&boards , int k){
    int start =0;
    int sum = 0;

    for(int i : boards){
        sum += i;
    }

    int end = sum;
    int ans = -1;
    
    while(start<=end){
        int mid = start+(end-start)/2;
        if(isPossible(boards,boards.size(),k,mid)){
            ans = mid ;
            end = mid -1;
        }
        else{
            start = mid +1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {10, 20, 30, 40};
    int k = 2; //no of painters
    
    int result = findLargestMinDistance(arr,k);
    std::cout << "area of the minimum time to get this job done of painting all the "<< arr.size()<<" boards under a constraint that any painter will only paint the continuous sections of boards: " << result << endl;
    
    return 0;
}