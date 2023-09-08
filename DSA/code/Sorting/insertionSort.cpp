#include <iostream>
using namespace std;

void printArr(int arr[], int len){
    
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

void insertionSort(int arr[], int len){

    for (int i = 1; i < len; i++){
        int temp = arr[i];
        int j = i-1;
        while (arr[j] > temp and j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    int arr[12]={2,1,1,3,1,0,1,3,2,0,0,1};
    
    cout<<"\nArray before sorting:  ";
    printArr(arr, 12);
    
    insertionSort(arr, 12);
    
    cout<<"\nArray after sorting:  ";
    printArr(arr, 12);

    return 0;
}