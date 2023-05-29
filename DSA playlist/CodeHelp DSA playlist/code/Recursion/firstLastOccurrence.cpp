#include <iostream>
using namespace std;

int firstOcc(int *arr, int start, int end, int key){

    if(start > end)
        return 0;
    
    int mid = start + (end - start)/2;
    
    if(arr[mid] == key){
        int ans = mid;
        return firstOcc(arr, start, mid - 1, key);
        
    }

    if(key > arr[mid])
        return firstOcc(arr, mid + 1, end, key);
    
    else
        return firstOcc(arr, start, mid - 1, key);

}

int main(){
    
    return 0;
}