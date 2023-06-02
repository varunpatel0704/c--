#include <iostream>
using namespace std;
  bool isPossible(int arr[], int len, int mid, int k){
    int painterCount=1, boardsum=0;
    for(int i=0; i<len; i++){
        if(boardsum+arr[i]<=mid){
            boardsum+=arr[i];
        }
        else{
            painterCount++;
            boardsum=0;
            boardsum+=arr[i];
            if(painterCount>k || boardsum>mid){
                return false;
            }
        }
    }
    return true;
}
    long long int minTime(int arr[], int n, int k)
    {
        // code here
        int start=0, end=0, ans=-1;
        for(int i=0; i< n; i++){
            end+=arr[i];
        }
        int mid = start+(end-start)/2;
        while(start<=end){
            if(isPossible(arr, n, mid, k)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid = start+(end-start)/2;
        }
            // return minimum time
        }
int main(){
    
    return 0;
}