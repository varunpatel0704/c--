#include <iostream>
using namespace std;

bool isPresent(int arr[], int len, int key){
    for (int i = 0; i <len; i++)
    {
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
    
}

int main(){
    int arr[10]={5,7,12,-2,10,22,1,0,-2,69};
    int key;
    
    cout<<"Enter the key to be searched ";
    cin>>key;

    bool found=isPresent(arr,10,key);
    if(found){
        cout<<"Key found"<<endl;
    }
    else
    cout<<"Key not found"<<endl;
    return 0;
}