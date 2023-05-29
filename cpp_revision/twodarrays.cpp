#include <iostream>
using namespace std;

int main(){

    // this is a 2d array.

    int twoDarray[3][4];
    
    // taking input;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // int element;
            // cin>>element;
            // twoDarray[i][j] = element;
            cout<<"Enter ["<<i<<"]["<<j<<"] element"<<endl;
            cin>>twoDarray[i][j];
        }
        
    }
    
    // printing the array.
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<twoDarray[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}