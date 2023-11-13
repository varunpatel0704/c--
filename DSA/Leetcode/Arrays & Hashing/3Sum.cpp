#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    // sort the array so that we can use the two pointer approach.
    sort(nums.begin(), nums.end());

    // use set to store unique tiplets
    set<vector<int>> store;
    for(int i=0; i<nums.size(); i++){
        int j=i+1, k=nums.size()-1;
        int sum = nums[i];
        // fix the value of i and find j and k (essentially 2sum using two pointers).
        while(j<k){
            sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                store.insert({nums[i], nums[j], nums[k]});
                j++, k--;
            }
            else if(sum > 0)
                k--;
            else 
                j++;
        }
    }
    vector<vector<int>> ans;
    for(auto element: store){
        ans.push_back(element);
    }
    return ans;
    //brute force solution.
    // set<vector<int>> store;
    // for(int i=0; i<nums.size(); i++){
    //     int x = nums[i];
    //     unordered_map<int, bool> encountered;
    //     for(int j=i+1; j<nums.size(); j++){
    //         int y = nums[j];
    //         int z = -x-y;
    //         if(encountered[z]){
    //             vector<int> triplet({nums[i], nums[j], z});
    //             sort(triplet.begin(), triplet.end());
    //             store.insert(triplet);
    //         }
    //         encountered[y] = true;
    //     }
    // }
    // vector<vector<int>> ans;
    // for(auto element: store){
    //     ans.push_back(element);
    // }
    // return ans;
}

int main(){
    
    return 0;
}