#include <iostream>
using namespace std;

int findUnique(int arr[], int len){
    int ans=0;
    for (int i = 0; i < len; i++)
    {
        ans=ans^arr[i];
    }
    return ans;
    
}

int main(){
   
    int arr[7]={0,2,1,0,1,2,9};
    cout<< "Unique element is "<< findUnique(arr,7);

    return 0;
}