#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {

    // check for duplicate elements in each row
    for(int i=0; i<9; i++){
        //create a hashmap each time you start traversing the row.
        unordered_map<char, bool> encountered;
        for(int j=0; j<9; j++){
            if(board[i][j] == '.')
                continue;
            if(encountered[board[i][j]])
                return false;
            else 
                encountered[board[i][j]] = true;
        }
    }

    // check for duplicate elements in each col
    for(int i=0; i<9; i++){
        //create a hashmap each time you start traversing the col.
        unordered_map<char, bool> encountered;
        for(int j=0; j<9; j++){
            if(board[j][i] == '.')
                continue;
            if(encountered[board[j][i]])
                return false;
            else 
                encountered[board[j][i]] = true;
        }
    }

    // now check each 3*3 matrix for duplicates.
    // create a 2D hashmap to store each grid and its elements.
    unordered_map<string, unordered_map<char, bool>> gridStore;

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.')
                continue;
            // extract grid-indices of current element to find which grid does it belong to.
            int x=i/3, y=j/3;
            string loc = to_string(x)+to_string(y);
            // check if the element is already present in the grid.
            if(gridStore[loc][board[i][j]])
                return false;
            else
                gridStore[loc][board[i][j]] = true;
        }
    }

    // all conditions checked, no violations found hence sudoku is valid.
    return true;
}

int main(){
    
    return 0;
}