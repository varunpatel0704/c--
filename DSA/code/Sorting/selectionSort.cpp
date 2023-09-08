#include <iostream>
using namespace std;

void printArr(int arr[], int len){
    
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int len){
    for (int i = 0; i < len-1; i++)
    {
        int minIndex=i;
        for (int j = i+1; j < len; j++)
        {
            if (arr[minIndex]>arr[j])
            {
                minIndex=j;
            }
            
        }
        swap( arr[i],arr[minIndex]);
        
    }
    
}

int main(){
    // int arr[6]={78, 31, 1, 19, -3, 47};
    int arr[12]={2,1,1,3,1,0,1,3,2,0,0,1};
    cout<<"\nArray before sorting:  ";
    printArr(arr, 12);
    
    selectionSort(arr, 12);
    
    cout<<"\nArray after sorting:  ";
    printArr(arr, 12);

    return 0;
}