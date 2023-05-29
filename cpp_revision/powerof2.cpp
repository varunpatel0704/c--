#include <iostream>
using namespace std;


// recursive function for power of 2.

int pwr2(int n){
    // base case.
    if(n == 0){
        return 1;
    }

    return 2*pwr2(n-1);

}

int main(){
    cout << "2^4 = " << pwr2(4) << endl;
    return 0;
}