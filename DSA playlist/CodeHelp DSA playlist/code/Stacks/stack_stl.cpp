#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack <int> s;
    s.push(3);
    s.push(5);
    s.push(7);

    cout << s.top() << endl;

    s.pop();

    cout <<"top most element is " << s.top() << endl;
    cout <<"size of stack is " << s.size() << endl;
    cout <<"size empty? --> " << s.empty() << endl;

    
    return 0;
}