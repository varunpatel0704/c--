#include <iostream>
using namespace std;

int sum(int arr[], int len){
    //base case
    if (len == 0)
        return 0;
    
    if (len == 1) 
        return arr[0];
    
    int total = arr[0];
    int remainingPart = sum(arr+1, len-1);
    
    return total + remainingPart;

    
}

int main(){
    
    int arr[5] = {1,2,5,60,2};

    cout << "Sum is: " << sum(arr, 5);
    return 0;
}