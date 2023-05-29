#include <iostream>
using namespace std;

void bubble(int * arr, int len){

    // base case.

    if(len == 0 || len == 1)
        return;

    for(int i = 0; i < len - 1; i++){
        if( arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    bubble(arr, len - 1);

}

int main(){
    int arr[5] = {9,1,2,7,3};
    bubble(arr,5);

    for (int i = 0; i<5; i++)
    {
        cout << arr[i];
    }
    
    return 0;
}