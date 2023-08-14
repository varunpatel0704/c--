#include <iostream>
using namespace std;

int partition(int *arr, int start, int end){ 
    int count = 0;

    for (int i = start+1; i <= end; i++)
    {
        if(arr[i] < arr[start]) // finding count of all elements smaller than pivot.
            count++;
    }
    
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]); // placing pivot on it's correct position.
      
    int i = start, j = end;
    
    while (i<pivotIndex && j>pivotIndex) // arranging the elements so that all the elements 
                                         // before pivot are smaller than it and all the elements
                                         // after pivot are greater than it.
    {
        while(arr[i] < arr[pivotIndex]){
                i++;
        }
        while(arr[j]>arr[pivotIndex]){
                j--;
        }

        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    
    return pivotIndex;
}

void quickSort(int *arr, int start, int end){

    if (start < end)
    {
        int pivot = partition(arr, start, end); // creating partition and getting the pivot index.

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

    int arr[5] = {4, 1, 3, 9, 7};
    int n = 5;
    //cout<<partition(arr, 0, 7);

    printArr(arr, n);
    
    quickSort(arr, 0, n-1);
    
    printArr(arr, n);

    return 0;
}