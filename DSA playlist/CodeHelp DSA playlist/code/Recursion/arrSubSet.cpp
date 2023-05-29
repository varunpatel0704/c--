#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& nums, vector<int> subset, int index, vector<vector<int>>& powset){
    // base case.
    if(index>=nums.size()){
        
        // for (int i = 0; i < subset.size(); i++)
        // {
        //     cout<<subset[i]<<" ";
        // }
        // cout<<endl;
        powset.push_back(subset);
        return;            
    }  
    
    //exclude.
    solve(nums, subset, index+1, powset);
    
    //include.
    int currElement = nums[index];
    
    subset.push_back(currElement);
    solve(nums, subset, index+1, powset);


}

vector<vector<int>> subsets(vector<int>& nums) {
    
    vector<vector<int>> powset;
    vector<int> subset;
    
    int index=0;
    
    solve(nums, subset, index, powset);
    return powset;
}

int main(){
   
    vector<int>ques={1,2,3};
    vector<vector<int>> ans = subsets(ques);
    
    
    for(int i = 0; i<ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<",";
        }
        cout<<endl;
    }
    
    
    cout<<ans.size();
    return 0;
}