#include <iostream>
using namespace std;

int exp(int a, int b){

    if(b == 0){
        return 1;
    }

    if(b & 1){
        return a * exp(a*a, b>>1);
    }

    else
        return exp(a*a, b>>1);

}

int main(){
    int a = 3;
    int b = 5;

    cout << "3^5 = " << exp(3,4);
    return 0;
}