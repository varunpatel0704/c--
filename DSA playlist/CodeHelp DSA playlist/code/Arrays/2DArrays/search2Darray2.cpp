#include <iostream>
#include <vector>
using namespace std;

bool recursiveSrchMat(vector <vector <int>> matrix, int row, int col, int target){
    // recursive solution.
        
    if ((row >= matrix.size()) || (col < 0))
        return false;
    
    int element = matrix[row][col];
    
    cout << element << endl;
    
    if (element == target)
        return true;
    
    if (target < element)
        return recursiveSrchMat(matrix, row, col - 1, target);
    
    else
        return recursiveSrchMat(matrix, row + 1, col, target);
}
    
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    int row = 0;
    int col = matrix[0].size() - 1; 
    
    return recursiveSrchMat(matrix, row, col, target);
}

//bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int row = matrix.size();
//     int col = matrix[0].size();
    
//     int rowindex = 0;
//     int colindex = col-1;
    
//     while(rowindex < row && colindex >= 0){
//         int element = matrix[rowindex][colindex];
        
//         if(element == target){
//             return 1;
//         }
        
//         else if(target < element){
//             colindex--;
//         }
        
//         else{
//             rowindex++;
//         }
        
//     }
    
//     return 0;
    
// }

int main(){
    vector < vector < int>> matrix = {{1,4,7,11,15},
                                      {2,5,8,12,19},
                                      {3,6,9,16,22},
                                      {10,13,14,17,24},
                                      {18,21,23,26,30}};
    
    //cout <<"5 Present? -->" << searchMatrix(matrix, 5) << endl;
    recursiveSrchMat(matrix, 0, matrix[0].size()-1, 5);
    return 0;
}