#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector <int> ans;
        int firstrow=0;
        int lastrow=matrix.size()-1;
        
        int firstcol=0;
        int lastcol=matrix[0].size()-1;
        
        
        int count=0 , total=(lastrow+1)*(lastcol+1);
        while(count<total){
            
            //print first row.
            for(int i=firstcol; i<=lastcol and count<total; i++){
                ans.push_back(matrix[firstrow][i]);
                count++;
            }
            firstrow++;

            //print last col.
            for(int j=firstrow; j<=lastrow and count<total; j++ ){
                ans.push_back(matrix[j][lastcol]);
                count++;
            }
            lastcol--;

            //print last row.
            for(int k=lastcol; k>=firstcol and count<total; k--){
                ans.push_back(matrix[lastrow][k]);
                count++;
            }
            lastrow--;

            //print first col.
            for(int l=lastrow; l>=firstrow and count<total; l--){
                ans.push_back(matrix[l][firstcol]);
                count++;
            }
            firstcol++;
            
            
        }
        
        return ans;
        
    }

int main(){
    
    return 0;
}