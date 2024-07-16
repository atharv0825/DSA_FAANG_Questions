#include<iostream>
#include<vector>
using namespace std;

class calculate{
public:
    int difference(vector<int>& array){
        int differ = 0;
        for (int i = 0; i < array.size(); i++){
            if(i % 2 == 0){
                differ += array[i];
            }
            else{
                differ -= array[i];
            }
        }
        return differ;
    }
};

int main(){
    calculate c;
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int diff = c.difference(array);
    cout << diff;
    return 0;
}
 