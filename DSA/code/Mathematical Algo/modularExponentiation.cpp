#include <iostream>
using namespace std;

// iterative method for binary exponentiation.
long long int modularExponentiation(long long int x, long long int n, long long int m) {
	long long int result = 1;
    
    while(n!=0){
        if(n&1){
            result = (result*x)%m;
        }
        x = (x*x)%m;
        n>>=1;
    }
    return result;
}

int main(){
    
    return 0;
}