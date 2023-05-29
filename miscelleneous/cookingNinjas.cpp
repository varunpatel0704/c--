#include <iostream>
using namespace std;

bool isPossible(int arr[], int len, int mid, int dishes){
    int cookcount=1, dishcount=1, time=0, i=0;
    while (dishcount<dishes)
    {
        if (time<=mid)
        {
            time+=arr[i]*dishcount;
            dishcount++;
        }
        
        else{
            cookcount++;
            i++;
            time=0;
            if (cookcount>len)
            {
                return false;
            }
            
        }
        

    }
    return true;
    
}

int minCookinTime(int arr[], int len, int dishes){
    int start=0, end=100000, ans=-1;
    // for (int i = 0; i < len; i++)
    // {
    //     end=max(end, arr[i]);
    // }
    // end=end*(dishes*(dishes-1))/2;
    int mid = start+(end-start)/2;
    while (start<=end)
    {
        if(isPossible(arr, len, mid, dishes)){
            ans=mid;
            end=mid-1;
        }

        else{
            start=mid+1;
        }
        mid = start+(end-start)/2;
    }
    
    return ans;
}

int main(){
    int arr[4]={1,2,3,4};
    cout<<"minimum time for 11 dishes "<<minCookinTime(arr,4,11);
    return 0;
}