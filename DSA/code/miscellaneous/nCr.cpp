#include <iostream>
using namespace std;

int nCr(int,int);
int factorial(int);



int main(){
    int n,r;
    cin>>n>>r;
    cout<<"Answer is "<<nCr(n,r);
    return 0;
}

int nCr(int n, int r){
    int num=factorial(n);
    int denom=factorial(r)*factorial(n-r);
    return num/denom;
}
int factorial(int n){
    int fact=1;
    for (int i = 1; i <=n; i++)
    {
        fact*=i;
    }
    return fact;
    
}