#include <iostream>
using namespace std;

void getSum(int arr[3][3]){
    int max =-1, largest;
    for(int row = 0; row < 3; row++){
        int sum = 0;
        for(int col = 0; col < 3; col++){
            sum+=arr[row][col];
        }
        cout<<"sum of row no "<<row+1<<" is " <<sum<<endl;
        if(sum>max){
            max = sum;
            largest = row;            
        }
    }
    cout<<"row with largest sum is -> "<<largest+1<<endl;
}

int main(){
    int twoDarray [3][3] = { {7,8,9}, 
                             {1,2,3},
                             {4,5,6}};
    cout<<"row wise sum is"<<endl;
    getSum(twoDarray);
    return 0;
}       