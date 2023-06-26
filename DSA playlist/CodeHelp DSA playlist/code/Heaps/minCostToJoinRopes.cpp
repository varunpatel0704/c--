#include <iostream>
#include <queue>
using namespace std;

#define LL long long

//Function to return the minimum cost of connecting the ropes.
LL minCost(LL arr[], LL n) {

    // step 1: create a min heap.
    priority_queue< LL, vector<LL>, greater<LL> > minHeap; // <-- this is how minHeap is declared.
    
    // now insert all the elements of arr in min heap
    for(int i=0; i<n; i++)
        minHeap.push(arr[i]);
    
    // step 2: now start calculating the minimum cost.
    LL cost = 0;
    while(minHeap.size()>1){
        
        /* get two min values from heap by popping and them.
            push their sum back into heap. */
        
        LL a = minHeap.top();
        minHeap.pop();
        
        LL b = minHeap.top();
        minHeap.pop();
        
        minHeap.push(a+b);
        
        cost = cost + a+b;
    }
    return cost;
}

int main(){
    
    return 0;
}