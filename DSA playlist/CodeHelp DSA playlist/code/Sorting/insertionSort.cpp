#include <iostream>
using namespace std;

void printArr(int arr[], int len){
    
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertSort(int arr[], int len){

    for (int i = 1; i < len; i++)
    {
        int temp=arr[i];
        int j=i-1;
        while (arr[j]>temp and j >= 0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        
    }
    
    cout<<"\nsorted";


}

int main(){
    int arr[5]={7, 8, 1, 9, 3};
    
    cout<<"\nBefore sort "<<endl;
    printArr(arr, 5);
    
    insertSort(arr, 5);
    
    cout<<"\nAfter sort "<<endl;
    printArr(arr, 5);
    return 0;
}