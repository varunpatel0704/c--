#include <iostream>
using namespace std;

void printArr(int arr[], int len){
    
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectSort(int arr[], int len){
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
    int arr[5]={7, 8, 1, 9, -3};
    
    cout<<"Before sort "<<endl;
    printArr(arr, 5);
    
    selectSort(arr, 5);
    
    cout<<"After sort "<<endl;
    printArr(arr, 5);
    
    return 0;
}