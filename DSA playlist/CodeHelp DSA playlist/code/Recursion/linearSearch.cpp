#include <iostream>
using namespace std;

bool linSrch(int *arr, int key, int size){
    if (size == 0)
        return 0;
    
    if (arr[0] == key)
        return 1;
    
    return linSrch(arr+1, key, size-1);
    
}

int main(){
    int arr[5] = {1,27,31,4,58};
   
    cout << "58 Present? --> " << linSrch(arr, 58, 5) << endl;
    cout << "67 Present? --> " << linSrch(arr, 67, 5) << endl;
   
    return 0;
}