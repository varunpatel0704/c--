#include <iostream>
using namespace std;

void printArray(int arr[], int len){
    cout<<"printing the array"<<endl;
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nprinting done"<<endl;
    
}

int getMax(int arr[], int len){
    int max = INT32_MIN;
    for (int i = 0; i <len; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
    
}

int getMin(int arr[], int len){
    int min = INT32_MAX;
    for (int i = 0; i <len; i++)
    {
        if (arr[i]<min)
        {
            min=arr[i];
        }
    }
    return min;
    
}
int main(){
    int first[10]={1};
    for(int i=0;i<10;i++){
        cin>>first[i];
    }
    cout<<"Maximum is "<<getMax(first,10)<<endl;
    cout<<"Minimum is "<<getMin(first,10)<<endl;
    return 0;
}