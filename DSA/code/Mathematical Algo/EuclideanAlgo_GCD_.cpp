#include <iostream>
using namespace std;

int gcd(int a, int b){
    
    if(a==0){
        return b;
    }

    if(b==0){
        return a;
    }

    while(a!=b){

        if(a>b){
            a = a-b;
        }

        else{
            b = b-a;
        }

    }
    
    return a;
}

int GCD(int a, int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    
    if(a<=b)
        return GCD(a, b-a);
    else   
        return GCD(a-b, b);
}
int main(){
    int a = 24, b = 72;
    // cout << "HCF of 24 and 72 is " << gcd(24, 72) << endl;
    cout << "HCF of 24 and 72 is " << GCD(24, 72) << endl;
    return 0;
}