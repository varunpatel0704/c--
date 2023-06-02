#include <iostream>
using namespace std;

int findPeak(int arr[], int n){
    int start=0;
    int end=n-1;

    int mid=start+(end-start)/2;

    while (start<end)
    {
        if (arr[mid]<arr[mid+1])
        {
            start=mid+1;
        }

        else{

            end=mid;
        }
        mid=start+(end-start)/2;
    }
    int peak=start;
    return peak;
    
}

int main(){
    int mountain[6]={3, 4, 8, 11, 6, 2};
    int peak=findPeak(mountain,6);
    cout<<"Peak element of given array is: "<<mountain[peak]<<endl;
    return 0;
}