#include <iostream>
using namespace std;

bool binarySearch(int *arr, int start, int end, int target){

    if(start > end)
        return false;
    
    int mid = start + (end-start)/2;

    if( mid == target)
        return true;
    
    else if ( mid < target){
        start = mid + 1;
        return binarySearch(arr, start, end, target);
    }
    else{
        end = mid - 1;
        return binarySearch(arr, start, end, target);
    }

}

bool linearSearch(int *arr, int len, int target){
    if(len == 0)
        return false;
    if(arr[0] == target)
        return true;
    else   
        return linearSearch(arr+1, len-1, target);
}

int getsum(int *arr, int len){

    // base case
    if(len == 0)
        return 0;
    
    return arr[0] + getsum(arr+1, len-1);

}

bool checksorted(int *arr, int len){

    if(len == 0 or len == 1)
        return true;

    if(arr[1] < arr[0])
        return false;
    
    else
        checksorted(arr+1, len-1);

}

int main(){
    int arr[5] = {1,2,3,4,5};
    cout << "sorted? -> " << checksorted(arr, 5) << endl;

    cout << "sum of given array is " << getsum(arr, 5) << endl;

    //cout << "is 10 present in given array? -> " << linearSearch(arr, 5, 10) << endl;
    cout << "is 10 present in given array? -> " << binarySearch(arr, 0, 4, 1) << endl;
    return 0;
}