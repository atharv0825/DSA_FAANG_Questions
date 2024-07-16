#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;


    vector<pair<int , int>>PairsOfTargetSum(vector<int>&array , int target){
        vector<pair<int, int>> result;
        unordered_map<int, int> index;

        for (int i = 0; i < array.size();i++){
            int complement = target - array[i];

            while (index.find(complement) != index.end())
            {
                result.push_back({index[complement], i});
                break;  
            }
            index[array[i]] = i;
        }
        return result;
    }


int main(){
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 8;
    vector<pair<int, int>> result = PairsOfTargetSum(array, target);
    for (auto pair : result) {
        cout << "(" << array[pair.first] << ", " << array[pair.second] << ")" << endl;
    }
}