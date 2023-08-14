#include <iostream>
using namespace std;

int main(){
    int arr[5]={2,-3,3,3,-2};
    int s=0;
    for(int i=0;i<5;i++){
        for (int j = i+1; j < 5; j++)
        {
            if (arr[i]+arr[j]==s)
            {
                cout<<arr[i]<<","<<arr[j]<<endl;
            }
            
        }
        
    }
    return 0;
}