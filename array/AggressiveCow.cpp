#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>&stalls ,int k ,int mid){
    int cowCount = 1;
    int lastPosition = stalls[0];

    for(int i = 0;i<stalls.size();i++){
        if(stalls[i]-lastPosition>=mid){
            cowCount++;
            if(cowCount == k)
                return true;
            lastPosition = stalls[i];    
        }
    }
    return false;

}

int aggressiveCow(vector<int>&stalls , int k){ // 'k' is no of cows
    if(k>stalls.size())
        return 0;
    sort(stalls.begin(),stalls.end());    
    int start = 0;
    int maxStall = -1;
    for(int i = 0;i<stalls.size();i++){
        maxStall = max(maxStall , stalls[i]);
    }
    
    int end = maxStall;
    int ans = -1;

    while(start<=end){
        int mid = start + (end - start)/2;

        if(isPossible(stalls , k , mid)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end= mid -1;
        }
    }
    return ans;
}
int main(){
    vector<int>stalls = {0 ,3 ,4 ,7 ,10 ,9};
    int k = 4;

    int ans = aggressiveCow(stalls , k);

    cout<<ans;
}