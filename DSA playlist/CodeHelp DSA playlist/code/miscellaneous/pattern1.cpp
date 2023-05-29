#include <iostream>
using namespace std;

int main(){
      /*1
        23
        345
        4567
        */
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=2*i-1;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}



