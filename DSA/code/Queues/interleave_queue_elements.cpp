#include <iostream>
#include <queue>
using namespace std;

void interLeaveQueue(queue < int > & q) {

    int n = q.size();
    vector <int> temp;
    
    for(int i = 0; i < n; i++){
        temp.push_back(q.front());
        q.pop();
    }

    int i = 0, j = n/2;
    while(j < n){
        q.push(temp[i]);
        q.push(temp[j]);
        i++, j++;
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << q.front() <<" ";
    //     q.pop();
    // }cout<<endl;
    interLeaveQueue(q);
    for (int i = 0; i < 4; i++)
    {
        cout << q.front() <<" ";
        q.pop();
    }
    
    return 0;
}