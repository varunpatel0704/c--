#include <iostream>
using namespace std;
    
int firstOcc(int arr[], int n, int key){
    int start=0;
    int end=n-1;
    int ans=-1;
    int mid=start+(end-start)/2;

    while (start<=end)
    {
        if (arr[mid]==key)
        {
            ans=mid;
            end=mid-1;
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
    return ans;
}
int lastOcc(int arr[], int n, int key){
    int start=0;
    int end=n-1;
    int ans=-1;
    int mid=start+(end-start)/2;

    while (start<=end)
    {
        if (arr[mid]==key)
        {
            ans=mid;
            start=mid+1;
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
    return ans;
}

int main(){
    
    int even[6]={1,2,3,3,3,5};
    int odd[5]={2,2,15,15,16};

    cout<<"First occurrence of 3 in even is "<< firstOcc(even, 6, 3)<< endl;
    cout<<"Last occurrence of 3 in even is "<< lastOcc(even, 6, 3)<< endl;
    
    cout<<"First occurrence of 15 in odd is "<< firstOcc(odd, 5, 15)<< endl;
    cout<<"Last occurrence of 15 in even is "<< lastOcc(odd, 6, 15)<< endl;
    return 0;
}   