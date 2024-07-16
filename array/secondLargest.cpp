#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class largestElement{
    public:
        int secondLargestElement(vector<int>&array){
            sort(array.begin(),array.end());
            int max = array.back();
            int secondMax = 0;
            for (int i = array.size() - 2; i >= 0;i--){
                if(array[i] != max && array[i]<max){
                    secondMax = array[i];
                    break;
                }
            }
            return secondMax;
        }
};

int main(){
    vector<int> array = {1, 2, 3, 5, 6, 7, 8,9};
    largestElement l;
    int result = l.secondLargestElement(array);
    cout << "Second largest Element : " << result << endl;
}