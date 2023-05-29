#include <iostream>
using namespace std;

int exp(int a, int b){
    // base case.
    
    if(!b) // b == 0
        return 1;

    if(b&1){ //
        return a * exp(a*a, b>>1);
    }
    
    else
        return exp(a*a, b>>1);

}

int main(){
    int a;
    int b;
    cin >> a >> b;
    cout << "a ^ b = " << exp(a, b) << endl;
    return 0;
}