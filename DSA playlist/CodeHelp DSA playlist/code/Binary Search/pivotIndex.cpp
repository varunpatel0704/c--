#include <iostream>
using namespace std;

int getPivot(int arr[], int n){
    
    int start=0, end=n-1;
    int mid = start+(end-start)/2;

    while (start<end)
    {
        if (arr[mid]>=arr[0])
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



int main(){
    
    int arr[7]={7,9,10,11,5,6,7};
    
    cout << "Pivot index is " << getPivot(arr, 7) << endl; 
   
    
    return 0;
}