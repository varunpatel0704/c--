#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

// naive approach: sort the array and then find the longest consecutive sequence.
// time complexity: O(nlogn) + O(n) = O(nlogn)
int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    map<int, bool> hashTable;
    for(int i=0; i<nums.size(); i++){
        hashTable[nums[i]] = true;
    }
    vector<int> store;
    for(auto element: hashTable){
        store.push_back(element.first);
    }
    int len=1, maxLen = 1;
    for(int i=0; i<store.size()-1; i++){
        if(store[i] == store[i+1]-1)
            maxLen = max(maxLen, ++len);
        else
            len = 1;
    }

    return maxLen;
}

//optimized approach: use a hashmap to store all the elements and then for each element having no immediate predecessor, try to find the longest consecutive sequence.
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0)
        return 0;

    unordered_map<int, bool> present;

    // store all the elements in an unordered map.
    for(int i=0; i<n; i++){
        present[nums[i]] = true;
    }

    // for each element, try to find the longest consecutive sequence.
    int maxLen = 1, len = 1;
    for(int i=0; i<n; i++){
        int curr = nums[i];
        if(present[curr-1]) // this condition is important because we basically want to ignore those elements which 
                              // are already consecutive to an element. We only want to consider those elements which 
                              // are at the beginning of a consecutive sequence, this way we only visit each element 
                              // at most twice and this reduces the complexity to O(N).
            continue;

        len = 1;
        while(present[curr+1]){
            curr += 1;
            len++;
        }
        maxLen = max(maxLen, len);
    
        
    }

    return maxLen;
}

int main(){
    
    return 0;
}