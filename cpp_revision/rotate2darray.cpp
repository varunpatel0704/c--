#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < row; col++){
            // int temp = matrix[col][row];
            // matrix[col][row] = matrix[row][col];
            // matrix[col][row] = temp;
            swap(matrix[row][col], matrix[col][row]);
        }
    }
}
void print(vector<vector<int>> matrix){
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};

    print(matrix);
    cout<<endl;
    rotate(matrix);
    print(matrix);
    return 0;
}