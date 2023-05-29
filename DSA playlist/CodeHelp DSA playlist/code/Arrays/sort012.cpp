#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    
    int arr[8]={0,2,1,1,0,2,0,2};
    int left=0, right=7;

    cout<<"\nArray without sorting"<<endl;
    
    while (left<right)
    {
        while ((arr[left]==0 or arr[left]==1) and (left<right))
        {
            left++;
        }

        while (arr[right]==2 and left<right)
        {
            right--;
        }

        if (left<right)
        {
            swap(arr[left],arr[right]);
            left++,right--;
        }
        
    }
    left=0, right=7;
    cout<<"\nArray after phase 1"<<endl;
    printArray(arr,8);

    while(left<right){
        
        while (arr[right]==2)
        {
            right--;
        }
        
        while (arr[left]==0 and left<right)
        {
            left++;
        }
        
        while (arr[right]==1 and left<right)
        {
            right--;
        }

        if (left<right)
        {
            swap(arr[left],arr[right]);
            left++,right--;
        }
        
    }
    cout<<"\nArray after phase 2"<<endl;
    printArray(arr,8);
    cout<<"\nSorting complete"<<endl;
    return 0;
}