#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> encountered;
    for(int i = 0; i<nums.size(); i++){
        if(encountered[nums[i]])
            return true;
        else
            encountered[nums[i]] = true;
    }
    return false;
}

int main(){
    
    return 0;
}