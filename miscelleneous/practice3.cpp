#include <iostream>
using namespace std;

void min_digit(int a, int b){
    if((a%10)<(b%10)){
        cout<<a;
    }
    else{
        cout<<b;
    }
}

int main(){
    int a, b;
    cout<<"Enter two 3 digit integer values";
    cin>>a>>b;
    min_digit(a,b);
    return 0;
}