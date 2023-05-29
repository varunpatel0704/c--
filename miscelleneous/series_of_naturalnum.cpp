#include <iostream>
using namespace std;

int main(){
    cout<<"This program will print the sum of first n natural numbers."<<endl;
    int n=0,sum=0,term;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    //for(int a=1; a<=n; a++){
        term=(n*(n+1))/2;
    //    sum+=term;
    //}
    cout<<"The sum is of first n natural numbers is:"<<term<<endl;
    return 0;
    
}