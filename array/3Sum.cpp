#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<int>>SumOfTriplets(vector<int>&array , int target){
    vector<vector<int>> result;
    sort(array.begin(), array.end());
    int n = array.size();

    for (int i = 0; i < n - 2;i++){
        if(i>0 && array[i] == array[i+1]) continue;
        int left = i + 1;
        int right = n - 1;

        while(left<right){
            int cuurentSum = array[i] + array[left] + array[right];
            if(cuurentSum == target){
                result.push_back({array[i] , array[left] , array[right]});
                while (left < right && array[left] == array[left+1])
                    left++;
                while(left<right && array[right] == array[right-1])
                    right--;
                left++;
                right--;
            }
            else if(cuurentSum < target){
                left++;
            }
            else{
                right--;
            }
        }
    }
    return result;
}

int main(){
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 10;
    vector<vector<int>> result = SumOfTriplets(array, target);
    for(auto pairs : result){
        cout << "( " << pairs[0] << " , " << pairs[1] << " , " << pairs[2]<<" )"<<endl;
    }
    return 0;
}