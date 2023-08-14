#include <iostream>
using namespace std;

bool binarySearch(int * arr, int start, int end, int key){

    if(start > end)
        return 0;
    
    int mid = start + (end - start)/2;
    
    if(arr[mid] == key)
        return 1;
    
    if(arr[mid] > key)
        return binarySearch(arr, start, mid - 1, key);

    return binarySearch(arr, mid + 1, end, key);
}

int main(){
    int arr[5] = {2, 4, 7, 8, 19};
    cout << "4 Present? --> " << binarySearch(arr, 0, 4, 4) << endl;
    cout << "10 Present? --> " << binarySearch(arr, 0, 4, 10) << endl;
    return 0;
}