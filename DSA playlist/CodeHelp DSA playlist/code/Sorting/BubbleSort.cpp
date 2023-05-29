#include <iostream>
using namespace std;

void printArr(int arr[], int len){
    
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int len){
    bool swapped=false;
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
            
        }

        if (swapped==false)//<-- this is to optimise the code. break when the array is already sorted.
        {
            cout<<"\nalready sorted"<<endl;
            break;
        }
        
    }
    
    
    


}

int main(){
    
    int arr[5]={-3, 1, 7, 8, 9};
    
    cout<<"\nBefore sort "<<endl;
    printArr(arr, 5);
    
    bubbleSort(arr, 5);
    
    cout<<"\nAfter sort "<<endl;
    printArr(arr, 5);

    return 0;
}