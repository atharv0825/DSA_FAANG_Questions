#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void arrangeArray(vector<int>& array){
    int low = 0;
    int high = array.size()-1;

    while(low < high){
        if(array[low]%2 == 1 && array[high]%2 == 0){
            swap(array[low] , array[high]);
            low++;
            high--;  // Error: Decrease high only if it's valid
        }

        if(array[low]%2==0){
            low++;
        }
        if(array[high]%2==1){
            high--;  // Error: Decrease high only if it's valid
        }
    }
}

int main(){
    vector<int> array ;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    arrangeArray(array);
    for(int i=0 ; i<array.size();i++){
        cout << array[i] << " ";
    }
    return 0;
}
