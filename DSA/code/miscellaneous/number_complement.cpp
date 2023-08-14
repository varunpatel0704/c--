#include <iostream>
#include <math.h>
using namespace std;
//code to convert decimal to binary.
int main(){
    int n;
    cin>>n;

    int ans=0;
    int i=0;

    while(n!=0){
        int bit=n&1;
        ans=(bit*pow(10,i))+ans;
        n=n>>1;
        i++;
    }
    cout<<"Answer is "<<ans<<endl;
    // int n,binary=0,complement=0,i=0;
    // cout<<"Enter the integer: ";
    // cin>>n;
    // while(n!=0){
    //     int bit=n&1;
    //     binary=(bit*pow(10,i))+binary;
    //     complement+=(!bit)*pow(10,i);
    //     n=n>>1;
    //     i++;
    // }
    // cout<<"binary of n = "<<binary<<endl;
    // cout<<"complement of n = "<<complement<<endl;
    return 0;
}