#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);
    int postfix = 1, prefix = 1;

    //first loop traverses nums from left to right hence calculating the prefix product.
    for(int i=0; i<nums.size(); i++){
        ans[i] = ans[i]*prefix;
        prefix = prefix*nums[i];
    }
    //second loop traverses nums from right to left hence calculating the prefix product.

    for(int i = nums.size()-1; i >= 0; i--){
        ans[i] = ans[i]*postfix;
        postfix = postfix*nums[i];
    }

    return ans;
}

int main(){
    
    return 0;
}