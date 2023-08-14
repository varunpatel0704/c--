#include <iostream>
using namespace std;

int main(){
    int arr[6]={5,1,7,0,34,-56};
    for(int i=0; i<6; i+=2){
        if(i+1<6){
            swap(arr[i],arr[i+1]);
        }
    }
    cout<<"swapped array is "<<endl;
    for(int j=0; j<6; j++){
        cout<<arr[j]<<" "<<endl;
    }
    return 0;
}