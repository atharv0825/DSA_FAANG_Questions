// sort the the 0s and 1s in given array
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class sortedArray{
public:
    vector<int> sortArray(vector<int> &nums) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        if (map.find(0) != map.end()){
            for (int i = 0; i < map[0]; i++){
                result.push_back(0);
            }
        }
        if (map.find(1) != map.end()) {
            for (int i = 0; i < map[1]; i++){
                result.push_back(1);
            }
        }

        return result;
    }
};

int main(){
    vector<int> array = {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0};
    sortedArray s;
    vector<int> result = s.sortArray(array);
    for (int nums : result)
    {
        cout << nums << " ";
    }
    return 0;
}
