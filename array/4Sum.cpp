#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourPairs(vector<int> array, int target)
{
    vector<vector<int>> result;
    sort(array.begin(), array.end());
    int n = array.size();
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && array[i] == array[i - 1])
            continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && array[j] == array[j - 1])
                continue;
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                int currentsum = array[i] + array[j] + array[left] + array[right];

                if(currentsum == target){
                    result.push_back({array[i], array[j], array[left], array[right]});

                    while(left<right && array[left] == array[left+1])
                        left++;
                    while(left<right && array[right] == array[right-1])
                        right--;

                    left++;
                    right--;
                }
                else if(currentsum<target){
                    left++;
                }
                else{
                    right++;
                }
            }
        }
        return result;
    }
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5, -6, 7, 8, -9, 10};
    int target = 10;
    vector<vector<int>> result = fourPairs(array, target);
    for(auto i : result){
        cout << "( " << i[0] << "," << i[1] << "," << i[2] << "," << i[3]<<" )"<<endl;
    }
    return 0;
}
