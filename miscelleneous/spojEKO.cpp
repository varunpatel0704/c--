#include <iostream>
#include<math.h>
using namespace std;

bool isPossible(int arr[], int len, int mid, int height){
	int sum=0;
	for(int i=0; i<len; i++){
		if(arr[i]>=mid){
			sum+=(arr[i]-mid);
		}
	}
	if(sum>=height){
		return true;
	}
	return false;
}

int minHeight(int arr[], int len, int height){
	
	int start=0, end=-1, ans=-1;
	
	for(int i=0; i<len; i++){
		end=max(arr[i],end);
	}
	
	int mid = start+(end-start)/2;
	
	while(start<=end){
		
		if(isPossible(arr, len, mid, height)){
			ans=mid;
			start=mid+1;
		}
		
		else{
			end=mid-1;
		}
		
		mid = start+(end-start)/2;
	}
	
	return ans;
}

int main() {
	
	
    long long int N, M;
    cin>> N >> M;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
    }
    
    cout<<minHeight(arr, N, M);

	return 0;
}