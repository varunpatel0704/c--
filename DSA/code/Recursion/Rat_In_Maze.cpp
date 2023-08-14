#include <iostream>
#include <vector>
using namespace std;


bool notvisited(vector<vector<int>> &visited, int row, int col){
    if(visited[row][col] == 0){
        return true;
    }
    
    else{
        return false;
    }
}

bool issafe(vector<vector<int>> &m, int n, int row, int col)
                                    
{
    if((0<=row && row<n) && (0<=col && col<n) && (m[row][col] == 1)){
        return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int>> &m,vector<vector<int>> &visited,int n,
            int row,int col,string path,vector<string>& paths)
{
    if( row == n-1 && col == n-1){
        paths.push_back(path);
        return;
    }
    
    
    //down.
    int nextrow = row+1, nextcol=col;
    if(issafe(m,n,nextrow,nextcol) && notvisited(visited,nextrow,nextcol)){
        visited[row][col]=1;
        path.push_back('D');
//cout<<path<<endl;
        solve(m,visited,n,nextrow,nextcol,path,paths);
        
        //backtrack.
        path.pop_back();
        visited[row][col]=0;
    }
    //Right.
    nextrow = row, nextcol=col+1;
    if(issafe(m,n,nextrow,nextcol) && notvisited(visited,nextrow,nextcol)){
        visited[row][col]=1;
        path.push_back('R');
//cout<<path<<endl;
        solve(m,visited,n,nextrow,nextcol,path,paths);
        path.pop_back();
        visited[row][col]=0;
    }
    //left
    nextrow = row, nextcol=col-1;
    if(issafe(m,n,nextrow,nextcol) && notvisited(visited,nextrow,nextcol)){
        visited[row][col]=1;
        path.push_back('L');
//cout<<path<<endl;
        solve(m,visited,n,nextrow,nextcol,path,paths);
        path.pop_back();
        visited[row][col]=0;
    }
    
    //up.
    nextrow = row-1, nextcol=col;
    if(issafe(m,n,nextrow,nextcol) && notvisited(visited,nextrow,nextcol)){
        visited[row][col]=1;
        path.push_back('U');
//cout<<path<<endl;
        solve(m,visited,n,nextrow,nextcol,path,paths);
        path.pop_back();
        visited[row][col]=0;
    }
}

// vector<string> findPath(vector<vector<int>> &m, int n) {
//     vector<string> paths;
    
//     if(m[0][0]==0)
//         return paths;
    
//     int row=0, col=0;
//     vector<vector<int>> visited = m;
//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<n; j++){
//             visited[i][j] = 0;
//         }
//     }
//     string path;
//     solve(m,visited,n,row,col,path,paths);
//     //sort(ans.begin(), ans.end());
//     return paths;
// }
bool isopen(vector<vector<int>>& visited,
    vector<vector<int>>& m, int row, int col, int n){
        if((row >= 0 and row < n) && (col >= 0 and col < n) && m[row][col] == 1){
            if(visited[row][col] == 0)
                return true;
            else 
                return false;
        } 
        return false;
    }
    
    void findpath(vector<vector<int>> &m, vector<vector<int>> visited,
    vector<string>& ans, int row, int col, string path, int n)
    {
        // base case
        
        if(row == n-1 and col == n-1){
            ans.push_back(path);
            return;
        }
        visited[row][col] = 1;
        // down
        if(isopen(visited, m, row+1, col, n)){
            path.push_back('D');
cout<<'D'<<endl;            
            //visited[row+1][col] = 0;
            findpath(m, visited, ans, row+1, col, path, n);
            path.pop_back();
            //visited[row+1][col] = 1;
        }
        
        // right
        else if(isopen(visited, m, row, col+1, n)){
            path.push_back('R');
cout<<'R'<<endl;
           // visited[row][col+1] = 0;
            findpath(m, visited, ans, row, col+1, path, n);
            path.pop_back();
           // visited[row][col+1] = 1;
        }
        
        // left
        else if(isopen(visited, m, row, col-1, n)){
            path.push_back('L');
cout<<'L'<<endl;
           // visited[row][col-1] = 0;
            findpath(m, visited, ans, row, col-1, path, n);
            path.pop_back();
           // visited[row][col-1] = 1;
        }
        
        // up
        else if(isopen(visited, m, row-1, col, n)){
            path.push_back('U');
cout<<'U'<<endl;
           // visited[row-1][col] = 0;
            findpath(m, visited, ans, row-1, col, path, n);
            path.pop_back();
            //visited[row-1][col] = 1;
        }
        visited[row][col] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> visited(m);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        
        vector<string> ans;
        string path;
        int row = 0;
        int col = 0;
        findpath(m, visited, ans, row, col, path, n);
        return ans;
        
    }




int main(){
    vector<vector<int>> m = {{1,0,0,0},
                             {1,1,0,0},
                             {1,1,0,0},
                             {0,1,1,1}};
   
    vector<string>paths=findPath(m,4);
   
    for (int i = 0; i < paths.size(); i++)
    {
        cout<<paths[i]<<endl;
    }
    
    return 0;
}