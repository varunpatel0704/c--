#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    
    int start = 0, end = row * col - 1;
    int mid = start + (end-start)/2;
    
    while(start <= end){
        int i = mid/col;
        int j = mid%col;
        
        if(matrix[i][j]==target){
            return 1;
        }
        
        else if(matrix[i][j]<target){
            start=mid+1;
        }
        
        else{
            end=mid-1;
        }
        
        mid = start + (end-start)/2;
    }
    
    return 0;
}
int main(){
    vector < vector <int>> matrix;
    int m = 3, n = 4;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j]=3;
        }
        
    }

    cout << "Present? --> "<< searchMatrix(matrix, 4) << endl;
    return 0;
}

