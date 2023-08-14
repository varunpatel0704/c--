#include<iostream>
#include<stack>
#include<queue>

using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    
    // step 1: empty first k elements into a stack
    stack<int> s;
    int n = q.size();
    
    for(int i = 0; i < k; i++){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    // step 2: pop elements from stack and insert back into q at the rear
    while(!s.empty()){
        int top = s.top();
        s.pop();
        q.push(top);
    }
    
    // step 3: pop elements from the q front and insert back at the rear
    for(int i = 0; i < n-k; i++){
        int front = q.front();
        q.pop();
        q.push(front);
    }
    
    return q;
}

int main(){
    return 0;
}