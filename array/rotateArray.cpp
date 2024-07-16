#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class rotateArray{
    public:
    vector<int> rotatedArray(vector<int> &array, int k){
        vector<int> result;
        int n = array.size();
        k = k % n;
        int j = 0;
        for (int i = n - k; i < n; i++){
            result.push_back(array[i]);
        }
        for (int i = 0; i < n; i++){
            result.push_back(array[i]);
        }
        return result;
    }
};

int main(){
    rotateArray r;
    vector<int> array = {1, 2, 3, 4, 5};
    int k = 6;
    vector<int> result = r.rotatedArray(array, k);
    for (int i = 0; i < array.size(); i++){
        cout << " " << result[i];
    }
}