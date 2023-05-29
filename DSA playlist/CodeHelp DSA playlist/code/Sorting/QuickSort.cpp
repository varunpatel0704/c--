#include <iostream>
using namespace std;

int partition(int *arr, int start, int end){

    int count = 0; // count of elements smaller then pivot(first) element.

    for (int i = start; i <= end; i++)
    {
        if(arr[i] < arr[start]) // if ith elements is smaller than pivot element then count++.
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]); // placing pivot on it's correct position.

    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] < arr[pivotIndex]){
            i++;
        }
       
        while(arr[j] > arr[pivotIndex]){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);  // all smaller elements on left side.
    }                                  // all greater elements on right side.
    
    return pivotIndex;
}

void quickSort(int *arr, int start, int end){
    if (start < end)
    {
        int pivot = partition(arr, start, end);

        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }

    else
        return;
    
}

void printArr(int *arr, int len){
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    
    int arr[5] = {49, 1, 901, 1, -7};
    int n = 5;
    //cout<<partition(arr, 0, 7);

    printArr(arr, n);
    
    quickSort(arr, 0, n-1);
    
    printArr(arr, n);

    return 0;
}