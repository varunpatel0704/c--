#include <iostream>
using namespace std;

void Merge(int *arr, int start, int mid, int end){
    int len1 = mid - start + 1;
    int len2 = end - mid;
    
    int *left = new int[len1];
    int *right = new int[len2];

    int mainIndx = start;
   
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[mainIndx++];
    }
   
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[mainIndx++];
    }
    
    mainIndx = start;
    int i = 0 ,j = 0;
    while(i < len1 && j < len2){
        if(left[i] < right[j])
            arr[mainIndx++] = left[i++];
        
        else
            arr[mainIndx++] = right[j++];
    }

    while (i < len1)
    {
        arr[mainIndx++] = left[i++];
    }
    
    while (j < len2)
    {
        arr[mainIndx++] = right[j++];
    }

    delete []left;
    delete []right;
    
}

// void Merge(int *arr, int start, int mid, int end){
//     // creating a temporary array to perform merging using dynamic memory
//     int *temp = new int[end - start + 1];
    
//     int i = start;
//     int j = mid + 1;
//     int k = start;
    
//     while (i <= mid && j <= end) // merging left and right part into temp.
//     {
//         if(arr[i] < arr[j]){
//             temp[k] = arr[i];
//             i++, k++;
//         }
        
//         else{
//             temp[k] = arr[j];
//             j++, k++;
//         }
//     }

//     while (i <= mid) // copying remaining left part.
//     {
//         temp[k] = arr[i];
//         k++, i++;
//     }
    
//     while (j <= end) // copying remaining right part.
//     {
//         temp[k] = arr[j];
//         k++, j++;
//     }
    
//     // copying temp into original arr.
//     for(int i = start; i <= end; i++){
//         arr[i] = temp[i];
//     }
    
//     delete []temp;
// }

void printArr(int *arr, int len){
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void MergeSort(int *arr, int start, int end){
    
    if(start < end){

        int mid = start + (end - start)/2;
        
        MergeSort(arr, start, mid); // sorting left part of the array.
        MergeSort(arr, mid + 1, end); // sorting right part of the array.
        
        Merge(arr, start, mid, end); // Merging left and right parts after sorting.

    }

    else
        return;

}

int main(){
    int arr[11] = {34,6,0,2,5,1,-6,76,-76,41,98};
    
    printArr(arr, 11);
    
    MergeSort(arr, 0, 10);

    printArr(arr, 11);

    return 0;
}