#include <iostream>
using namespace std;

int binarySearch(int arr[], int len, int target){

    // step1
    int start=0, end=len-1;

    //step2

    while(start<=end){
        int mid = start+(end-start)/2;

        //condition 1
        if(arr[mid] == target)
            return mid;
        
        //condition 2
        else if(arr[mid] < target)
            start = mid+1;
        
        else
            end = mid-1;
    }
    return -1;
}

int main(){
    
    int arr[5] = {1,4,5,8,9};
    
    cout<<"element found at index ->" <<binarySearch(arr, 5, 101) << endl;
    return 0;
}
