#include <iostream>
using namespace std;

int getPivot(int arr[], int n){
    
    int start=0, end=n-1;
    int mid = start+(end-start)/2;

    while (start<end)
    {
        if (arr[mid]>arr[0])
        {
            start=mid+1;
        }

        else{

            end=mid;
        }
        
        mid = start+(end-start)/2;
    }
     
     return start;

}

int binarySearch(int arr[], int start, int end , int key){
    
    int mid=start+(end-start)/2;

    while (start<=end)
    {
        if (arr[mid]==key)
        {
            return mid;
        }

        else if (key>arr[mid])
        {
            start=mid+1;
        }

        else{
            end=mid-1;
        }

        mid=start+(end-start)/2;
        
    }

    return -1;

}

int main(){
    int arr[7]={7,9,10,11,5,6,7};
    int pivot=getPivot(arr,7);
    
    cout << "Pivot index is " << getPivot(arr, 7) << endl; 
    
    int key;
    cin>>key;
    
    if (key>=arr[pivot] && key<=arr[6])
    {
        cout<<"Key found on index "<<binarySearch(arr, pivot, 6, key);
    }

    else {

        cout<<"Key found on index "<<binarySearch(arr, 0, pivot-1, key);
    }
    
    return 0;
}