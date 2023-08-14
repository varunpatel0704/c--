#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size){
    //base case.
    if (size == 0 || size == 1)
        return;
    
    for (int i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    
    bubbleSort(arr, size - 1);
}
int main(){
    int arr[6] = {10,5,1,-4,5,0};
    bubbleSort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout<<i[arr]<<" ";
    }
    cout << endl;

    return 0;
}