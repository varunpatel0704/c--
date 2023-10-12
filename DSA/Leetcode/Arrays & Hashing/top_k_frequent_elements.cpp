#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class compare{
    public: 
    bool operator() (pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for(auto i: nums)
        count[i]++;

    priority_queue<pair<int,int>, vector<pair<int, int>>, compare> minHeap;
    for(auto element: count){
        pair<int, int> item = {element.first, element.second};
        minHeap.push(item);
    
        if(minHeap.size() > k)
            minHeap.pop();                
    }

    vector<int> ans;
    while(!minHeap.empty()){
        ans.push_back(minHeap.top().first);
        minHeap.pop();
    }

    return ans;
}

int main(){
    
    return 0;
}