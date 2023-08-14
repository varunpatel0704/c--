#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(vector<int> arr, int k) {
    // step1: create a max-heap for first k elements
    priority_queue<int> pq;
    
    for(int i = 0; i<k; i++)
        pq.push(arr[i]);
        
    // step2: now check if there are smaller 
    //        elements in the array, replace it with
    //        the top if found
    
    for(int i = k; i < arr.size(); i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    return pq.top();
}

int main(){
    
    return 0;
}