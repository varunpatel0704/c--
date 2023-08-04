#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<bool>> &board, int n){
    int x = row, y = col;

    // check if another queen is present in same col
    while(x>=0){
        if(board[x][y])
            return false;
        x--;
    }

    // check if another queen is present in same upper left diagonal
    x = row, y = col;
    while(x>=0 && y>=0){
        if(board[x][y])  
            return false;
        x--, y--;
    }

    // check if another queen is present in same upper right diagonal
    x = row, y = col;
    while(x>=0 && y<n){
        if(board[x][y])  
            return false;
        x--, y++;
    }
    
    return true;
}

void solve(int n, vector<vector<bool>> &board, 
            vector<vector<string>> &ans, int row)
            
{   
    // process if all rows are not covered yet.
    if(0<= row && row < n){
        
        // try placing the queen in all the coloumns for given row.
        for(int col=0; col<n; col++){
            
            // place the queen if none of the queens are attacking
            if(isSafe(row, col, board, n)){
                board[row][col] = true;
    
                solve(n, board, ans, row+1);
                
                // backtrack
        
                board[row][col] = false;

            }
        }
        
    }

    else{
        // this section of function will be executed only when all the queens have been placed on the board.
        
        // we have a solution, hence generate the string corresponding to placement of queens.      
        vector<string> str;
        for(int i=0; i<n; i++){
            string temp="";

            for(int j=0; j<n; j++){

                if(board[i][j])
                    temp.push_back('Q');
                else
                    temp.push_back('.');
            }
            str.push_back(temp);
        }
        ans.push_back(str);
    }
}


vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<bool>> board(n, vector<bool>(n,0));
    int row=0;
    solve(n, board, ans, row);

    return ans;
}

int main(){
    
    return 0;
}