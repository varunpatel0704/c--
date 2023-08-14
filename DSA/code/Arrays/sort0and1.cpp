#include <iostream>
using namespace std;

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

void sortOne(int arr[], int n){
    int left=0, right=n-1;

    while (left<right)
    {
        /*while*/if(arr[left]==0 && left<right){
            left++;
        }
        /*while*/ else if(arr[right]==1 && left< right){
            right--;
        }
        // yaha tak aa gaye matlab arr[left]==1 and arr[right]==0 hai
        // toh ab dono ko swap karna padega.
        else if (left<right)
        {
            swap(arr[left],arr[right]);
            left++,right--;
        }
        
    }
    
}

int main(){
    int arr[8]={1,1,0,0,0,0,1,0};
    int n=8;

    cout<<"\nBefore sorting"<<endl;
    printArray(arr,8);
    
    sortOne(arr,8);
    
    cout<<"\n\nAfter sorting"<<endl;
    printArray(arr,8);
    
}