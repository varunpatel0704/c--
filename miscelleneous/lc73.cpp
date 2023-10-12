#include <iostream>
#include <vector>
// #include <pair>
#include <unordered_map>
using namespace std;

void setRow(vector<vector<int>> &matrix, int &row, int &col)
{
    for (int i = 0; i < matrix[0].size(); i++)
    {
        matrix[row][i] = 0;
    }
}

void setCol(vector<vector<int>> &matrix, int &row, int &col)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        matrix[i][col] = 0;
    }
}

vector<pair<int, int>> setZeroes(vector<vector<int>> &matrix)
{
    vector<pair<int, int>> loc;
    int rows = matrix.size(), cols = matrix[0].size();

    // locate all the zeroes in the matrix.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                cout<<"0 found at "<<i<<", "<<j<<endl;
                loc.push_back({i,j});
            }
        }
    }

    // now traverse the map and set the rows of all zeroes to zero.
    for (auto i : loc)
    {
        int x = i.first;
        int y = i.second;

        setRow(matrix, x, y);
        setCol(matrix, x, y);
    }

    return loc;
}

int main()
{
    vector<vector<int>> matrix = {{0,1,2,0},
                                  {3,4,5,2},
                                  {1,3,1,5}};
    vector<pair<int, int>>p = setZeroes(matrix);

    for(auto i: p){
        cout<<i.first<<", "<<i.second<<endl;
    }
    return 0;
}