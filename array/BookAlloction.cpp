// You are given an array arr of integers where each element represents the number of pages in a book. There are n books and m students. The goal is to allocate all books to students such that each student gets at least one book and the maximum number of pages assigned to a student is minimized. Each book can be allocated to only one student, and each student can receive a contiguous sequence of books.

// [10,20,30,40]

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>&array , int n , int m, int mid){
    int studentCount = 1;
    int pageSum = 0;
    int ans = -1;

    for(int i =0;i<n;i++){
        if(pageSum+array[i]<=mid){
            pageSum += array[i];   
        }else{
            studentCount++;
            if(studentCount>m || array[i]>mid)
                return false;
            pageSum = array[i];    
        }
        if(studentCount>m)
            return false;
    }
    return true;
}

int allocateBooks(vector<int>&array , int n , int m){
    int start = 0;
    int sum = 0;
    for(int i : array)
        sum += i;
    int end = sum;
    int ans = -1;

    while(start<end){
        int mid = start + (end-start)/2;
        if(isPossible(array,n,m,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }   
    return ans;
}

int main(){
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();
    int m = 2; // Number of students
    
    int result = allocateBooks(arr, n, m);
    std::cout << "The minimum possible value of the maximum number of pages assigned to a student is: " << result << endl;
    
    return 0;
}