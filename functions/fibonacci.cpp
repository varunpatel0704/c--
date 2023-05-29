#include <iostream>
using namespace std;

int main(){
    int num1=1, num2=1, num3, n;
    cin>>n;
    cout<<"This is using for loop\n";
    cout<<num1<<" "<<num2<<" ";
    for(int i=3; i<=n; i++){  
        // cout<<" "<<num1<<" "<<num2<<" ";    // 1,1,2,3,5,8,13.....
        num3=num1+num2;
        cout<<num3<<" ";
        num1=num2;
        num2=num3;
    }
    
    return 0;
}