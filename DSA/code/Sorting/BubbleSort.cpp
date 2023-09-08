#include <iostream>
using namespace std;

void printArr(int arr[], int len){
    
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<", ";
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
    
    int arr[6]={89, 21, 15, 9, -6, 7};
    // int arr[12]={2,1,1,3,1,0,1,3,2,0,0,1};
    cout<<"\nArray before sorting:  ";
    printArr(arr, 6);
    
    bubbleSort(arr, 6);
    
    cout<<"\nArray after sorting:  ";
    printArr(arr, 6);

    return 0;
}