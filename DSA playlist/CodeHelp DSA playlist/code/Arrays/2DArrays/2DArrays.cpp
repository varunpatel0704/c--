#include <iostream>
using namespace std;

void rowSum(int arr[3][3]){
    cout<<"\nprinting row wise sum of matrix\n";
    for(int row = 0; row < 3; row++){
        int sum=0;
        for(int col=0; col < 3; col++){
            sum+=arr[row][col];
        }
        cout<<sum<<endl;
    }

}

bool isPresent(int arr[3][3], int target){
    for(int row = 0; row < 3; row++){

        for(int col=0; col < 3; col++){

            if(arr[row][col]==target){

                return 1;
            } 
        }
    }
    

    return 0;
}

void print(int arr[3][3]){

    for(int row = 0; row < 3; row++){

        for(int col=0; col < 3; col++){

            cout << arr[row][col] << " ";
        }
        cout<<endl;
    }


}

int main(){
    int arr[3][3];
    cout<<"Enter the elements of 3x3 matrix " << endl;

    // for(int row = 0; row < 3; row++){

    //     for(int col=0; col < 3; col++){  // <-- taking input row wise. 

    //         cin >> arr[row][col];
    //     }
    //     cout<<endl;
    // }
    
    for(int col = 0; col < 3; col++){

        for(int row=0; row < 3; row++){  // <-- taking input coloumn wise. 

            cin >> arr[row][col];
        }
        cout<<endl;
    }

    print(arr);
    int element;
    cout<<"\nenter the element to search in the array ";
    cin>>element;

    if(isPresent(arr, element)){
        cout<<"element found";

    }

    else{

        cout<<"element not found ";
    }

    rowSum(arr);
    return 0;
}