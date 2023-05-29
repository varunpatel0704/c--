#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int binary,number=0;
    cout<<"Enter the binary number: ";
    cin>>binary;
    int i=0,bit;
    while(binary!=0){
        bit=binary%10;
        if (bit==1)
        {
            number+=pow(2,i);
        }
        binary=binary/10;
        i++;        
    }
    cout<<number;
    return 0;
}