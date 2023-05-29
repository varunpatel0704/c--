#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int num;
    cout<<"Enter the value of num: ";
    cin>>num;
    if(1<=num and num<=1000){
        int arr[num];
        for(int i=0; i<num;i++){
            cout<<"Enter the element: ";
            int temp;
            cin>>temp;
            
            if(1<=temp and temp<=10000){
                arr[i]=temp;
            }
        }
        int x=0;
        while(x<num){
            cout<<arr[x]<<" ";
            x++;
        }
    }

    return 0;
}