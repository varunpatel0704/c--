#include <iostream>
using namespace std;

int fact(int a ){
    int factorial=1;
    for(int i=a; i>0;i--){
        factorial*=i;
    }
    return factorial;
}

int main(){
    int x;
    cout<<"This is test program to calculate factorial"<<endl;
    cout<<"Enter the number whose factorial is to be calculated: ";
    cin>>x;
    cout<<"The factorial is: "<<fact(x);
    
    return 0;
}