#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextLargerElement(vector<int> arr, int n){
        
    vector<int> ans(n);
    stack <int> s;
    // start traversing the array.
    for(int i = 0; i < arr.size(); i++){
        
        // check if current element can be the NGE for elements in stack.

        
        // we are using indices of elements instead of 
        // their values to make the code easier 
        // hence s.top() represents the index of element in the arr.
        
        while(!s.empty() && (arr[i] > arr[s.top()])){  // same logic for Next Smaller Element except there will be '<' sign instead of '>'
            ans[s.top()] = arr[i];
            s.pop();
        }
        
        // curr element is smaller than s.top(); -> push curr into stack
        s.push(i);
    
    }
    
    // some elements may not have NGE; -> assign -1 to them.
    while(!s.empty()){
        ans[s.top()] = -1;
        s.pop();
        
    }
    
    return ans;
}

int main(){
    
    return 0;
}