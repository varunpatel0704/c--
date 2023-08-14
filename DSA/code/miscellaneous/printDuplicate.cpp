#include <iostream>
using namespace std;

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,7};
    int ans=0;
    for(int i=0;i<10;i++){
        ans=ans^arr[i];
    }
    for(int i=1;i<10;i++){//XORing all integers from 1 to n-1 
        ans=ans^i;  // then XORing it to result 1.
    }
    
    cout<<"Duplicate element is: "<< ans << endl;

    return 0;
}