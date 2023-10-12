#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int ,int> encountered;
    for(int i=0; i<nums.size(); i++){
        int x = nums[i];
        int y = target - x;
        if(encountered.count(y))
            return {i, encountered[y]};
        else
            encountered[x] = i;
    }

    return {};
}

int main(){

    return 0;
}