#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int mostNegativePrefix = 0;
    int prefixSum=0, n = nums.size(), ans=-10e9;

    for(int i=0; i<n; i++){
        prefixSum += nums[i];

        int temp = prefixSum - mostNegativePrefix;
        ans = max(temp, ans);
        
        mostNegativePrefix = min(mostNegativePrefix, prefixSum);
    }

    return ans;
}

int main(){
    
    return 0;
}