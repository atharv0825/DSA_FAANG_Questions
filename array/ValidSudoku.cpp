#include<iostream>
#include<algorithm>
#include<vector>
#include <set>
using namespace std;

class solution{
    public:
        bool checkInBox(vector<vector<char>>&nums , int startRow , int startCol){
            set<char> st;

            for (int row = 0; row < 3;row++){
                for (int col = 0; col < 3;col++){
                    char curr = nums[row + startRow][col + startCol];

                    if(st.find(curr)!=st.end()){  //st.find(curr)!=st.end() :- this is condition this may true or false 
                        return false;
                    }

                    if(curr != '.')
                        st.insert(curr);
                        
                }
            }
            return true;
        }

        bool checkInRow(vector<vector<char>>&nums , int row ){
            set<char> st;
            for (int col = 0; col < nums[0].size();col++){
                if(st.find(nums[row][col]) != st.end())
                    return false;
                if(nums[row][col] != '.')
                    st.insert(nums[row][col]);
            }
            return true;
        }

        bool checkInCol(vector<vector<char>>&nums , int col){
            set<char> st;
            for (int row = 0; row < nums.size();row++){
                if(st.find(nums[row][col]) != st.end())
                    return false;
                if(nums[row][col]!='.')
                    st.insert(nums[row][col]);
            }
            return true;
        }
        bool checkEverything(vector<vector<char>>&nums , int row , int col){
            return checkInBox(nums, row-row%3, col-col%3) && checkInCol(nums, col) && checkInRow(nums, row);
        }
        bool ValidSudoku(vector<vector<char>>&nums){
            for (int row = 0; row < nums.size();row++){
                for (int col = 0; col < nums[row].size();col++){
                    if(!checkEverything(nums, row , col)){
                        return false; 
                    }
                }
            }
            return true;
        }
};

int main(){
    vector<vector<char>> Sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '7', '7', '9'}
    };
    solution s;
    cout << (s.ValidSudoku(Sudoku) ? "TRUE" : "FALSE");
}