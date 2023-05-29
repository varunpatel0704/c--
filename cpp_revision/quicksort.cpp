#include <iostream>
using namespace std;


int partition(int *arr, int start, int end){
    // step 1: count the no of elements smaller than pivot i.e. arr[start] to find the pivot index.

    int count = 0;

    for (int i = start+1; i <= end; i++)
    {
        if(arr[i] < arr[start])
            count++;
    }
    
    // step 2: place the pivot element on its correct position.
    int pivotindex = start + count;
    swap(arr[start], arr[pivotindex]);


    // step 4: segregate the left and right parts such that left[i] < pivot element < right[j].
    int i = start, j = end;
    while (i < pivotindex && j > pivotindex)
    {
        if(arr[i] < arr[pivotindex] && i < pivotindex)
            i++;
        else if(arr[j] > arr[pivotindex] && j > pivotindex)
            j--;
        else if(i < pivotindex && j > pivotindex)
            swap(arr[i++], arr[j--]);
    }
    
    // step 5: return pivot index.
    return pivotindex;
}


void quicksort(int *arr, int start, int end){
    if(start < end){
        // step 1: create partition
        int p = partition(arr, start, end);

        // step 2: recursive calls.

        quicksort(arr, start, p-1);
        quicksort(arr, p+1, end);

    }

    else    
        return;
}

int main(){
    int arr[5] = {4, 2, 5, 1, 3};
    quicksort(arr, 0, 4);
    for (int i = 0; i<5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}