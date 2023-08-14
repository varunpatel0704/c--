#include <iostream>
#include <queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
                                                 
                                                 
    vector <long long> ans;
    deque <long long> dq;
    
    // process the first window
    for(int i = 0; i < k; i++){
        if(arr[i] < 0)
            dq.push_back(i);
    }
    
    // check if any negative integer is present in the window.
    if(dq.size() > 0)
        ans.push_back(arr[dq.front()]);
    else
        ans.push_back(0);
        
    // process remaining windows.
    for(int i = k; i < n; i++){
        // make space for new element by deleting old element from dq.
        if(!dq.empty() && i - dq.front() >= k){
            dq.pop_front();
        }
        
        // if current element is negative then push it into dq.
        if(arr[i] < 0)
            dq.push_back(i);
        
        // now again check if any negative integer is present in the window.
        if(dq.size() > 0)
            ans.push_back(arr[dq.front()]);
        else
            ans.push_back(0);
    }
    
    return ans;
 }

int main(){
    
    return 0;
}