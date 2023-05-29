#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end){
    // create copies of left and right sub arrays
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int mainIndex = start;

    // copy left part
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[mainIndex++];
    }
    
    // copy right part
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[mainIndex++];
    }

    // merge left and right parts into original array.
    int i = 0, j = 0;
    mainIndex = start;

    while(i < len1 && j < len2){

        if(left[i] < right[j])
            arr[mainIndex++] = left[i++];    

        else
            arr[mainIndex++] = right[j++];
            
    }

    while( i < len1 ){
        arr[mainIndex++] = left[i++];
    }

    while(j < len2){
        arr[mainIndex++] = right[j++];
    }

    delete []left;
    delete []right;
    
}

void mergeSort(int *arr, int start, int end){

    if(start < end){
        int mid = start + (end - start)/2;
        // sort left part
        mergeSort(arr, start, mid);

        // sort right part
        mergeSort(arr, mid+1, end);
        
        // merge left and right parts
        merge(arr, start, mid, end);
    }

    else
        return;

}

int main(){
    int arr[5] = {9,2,1,-9,3};
    mergeSort(arr, 0, 4);
    for (int i = 0; i<5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}