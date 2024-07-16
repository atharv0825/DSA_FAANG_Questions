#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>

using namespace std;

pair<int, int> findOccurrences(const vector<int>& nums, int target) {
    unordered_map<int, int> countMap;

    // Count occurrences of each element
    for (int num : nums) {
        countMap[num]++;
    }

    // Find first occurrence
    auto firstIter = find(nums.begin(), nums.end(), target);
    int firstOccurrence = (firstIter != nums.end()) ? distance(nums.begin(), firstIter) : -1;

    // If target not found, return (-1, -1)
    if (firstOccurrence == -1) {
        return make_pair(-1, -1);
    }

    // Calculate last occurrence
    int lastOccurrence = firstOccurrence + countMap[target] - 1;

    return make_pair(firstOccurrence, lastOccurrence);
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    int target = 3;

    pair<int, int> occurrences = findOccurrences(nums, target);

    if (occurrences.first != -1) {
        cout << "First occurrence of " << target << " is at index: " << occurrences.first << endl;
        cout << "Last occurrence of " << target << " is at index: " << occurrences.second << endl;
    } else {
        cout << "Target element not found in the array." << endl;
    }

    return 0;
}
