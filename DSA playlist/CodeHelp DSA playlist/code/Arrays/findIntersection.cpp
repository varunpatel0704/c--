#include <iostream>
using namespace std;

int main(){
    
    int arr1[6]={1,2,2,3,3,4};
    int arr2[4]={2,2,3,3};
    
    int n=6,m=4;

    cout<<"Intersection using brute force approach"<<endl<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     int element=arr1[i];
    //     for (int j = 0; j < m;j++)
    //     {
    //         if (element==arr2[j])
    //         {
    //             cout<<element<<" ";
    //             arr2[j]=-1;
    //             break;
    //         }
            
    //     }
        
    // }

    cout<<"\n\nIntersection using optimized approach"<<endl<<endl;

    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++,j++;
        }
        
        else if(arr1[i]<arr2[j]){
            i++;
        }

        else{
            j++;
        }

    }
    return 0;
}