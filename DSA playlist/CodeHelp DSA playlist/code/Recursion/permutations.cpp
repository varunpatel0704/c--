#include <iostream>
#include <vector>
using namespace std;

void findperm(vector<int> nums, int index, vector<vector<int>>& ans){

        // base case.
        if(index>nums.size()-1){
            ans.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            findperm(nums, index+1, ans);
            
            // backtrack i.e. restoring previous permutation 
            // for next recursive call.
            
            swap(nums[index], nums[i]);
        }
    
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;        
        int index = 0;
        
        findperm(nums, index, ans);
        return ans;
        
    }

int main(){
    
    return 0;
}