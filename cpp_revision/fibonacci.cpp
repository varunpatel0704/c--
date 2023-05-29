#include <iostream>

using namespace std;

int fib(int n){

    // base case.
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    return fib(n-1) + fib(n-2);

}

int main(){
    cout << "5th term of fibonacci series is " << fib(5) << endl;

    return 0;
}