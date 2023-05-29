#include <iostream>
using namespace std;

bool sortCheck(int arr[], int len){
    if (len == 0)   
        return 1;

    else if (arr[len-1]>arr[len-2])

        sortCheck(arr, len-1);

    else
        return 0;

    //return 0;
    
}

int main(){
    int arr[5] = {1,2,3,4,5};
    cout << "Sorted? --> " << sortCheck(arr, 5);
    return 0;
}