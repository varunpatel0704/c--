#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int sum=0, result=0;
    unordered_map<int, int>store;
    store[0]=1;
    int n = nums.size();
    
    for(int i=0; i<n; i++){
        sum += nums[i];
        int prefix = sum - k;
        if(store.count(prefix)){
            result += store[prefix];
        }

        store[sum]++;
    }   

    return result;
}

int main(){
    
    return 0;
}