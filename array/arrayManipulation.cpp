#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// class manipulation
// {
// public:
//     vector<int> ArrayManipulation(vector<int> &arr)
//     {
//         vector<int> result;
//         unordered_map<int, int> indexMap;

//         for (int i = 0; i < arr.size(); i++)
//         {
//             indexMap[arr[i]]++;
//         }
//         for (auto pair : indexMap)
//         {
//             if (pair.second % 2 != 0)
//                 result.push_back(pair.first);
//         }
//         return result;
//     }

//     vector<pair<int, int>> findDuplicatePairs(const vector<int> &arr)
//     {
//         unordered_map<int, int> indexMap; // Map to store the last index of each element
//         vector<pair<int, int>> duplicatePairs;

//         for (size_t i = 0; i < arr.size(); ++i)
//         {
//             // If the element is found again, create a pair
//             if (indexMap.find(arr[i]) != indexMap.end())
//             {
//                 duplicatePairs.push_back(make_pair(arr[i], arr[i]));
//             }
//             // Update the index of the element
//             indexMap[arr[i]] = i;
//         }

//         return duplicatePairs;
//     }
// };

// int main()
// {
//     vector<int> array = {1, 2, 3, 1, 2, 3, 4, 5, 6, 4, 2};
//     manipulation m;
//     vector<int> result = m.ArrayManipulation(array);
//     for (int i = 0; i < result.size(); i++)
//     {
//         printf("%d ", result[i]);
//     }
//     vector<pair<int, int>> result1 = m.findDuplicatePairs(array);
//     for (auto pair : result1)
//     {
//         cout << "(" << pair.first << "," << pair.second << ")" << endl;
//     }
// }


int sortedArray(vector<int>&nums){
    int countOfZero = 0;

    for (int i = 0; i < nums.size();i++){
        if(nums[i] == 0){
            countOfZero++;
        }
    }
    for (int i = 0; i < nums.size();i++){
        if (i < countOfZero) {
            nums[i] = 0;
        }else{
            nums[i] = 1;
        }    
    }
    // return nums;
}


void sortArray(vector<int>nums){
    int left = 0;
    int right = nums.size() - 1;

    while(left<right){
        if(nums[left] == 1 && nums[right] == 0){
            nums[left++] = 0;
            nums[right--] = 1;
        }
        if(nums[left] == 0 ){
            left++;
        }
        if(nums[right] == 1 ){
            right--;
        }
    }
    return;
}

int main(){
    vector<int>nums = {1,1,1,0,0,0,0};
    sortedArray(nums);

    for (int i = 0; i < nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    sortArray(nums);
    for (int i = 0; i < nums.size();i++){
        cout << nums[i] << " ";
    }
    return 0;
}