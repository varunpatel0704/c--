#include <iostream>
using namespace std;

void char_check(char a, char b){
    if(a==b){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}

int main(){
    char x, z;
    cout<<"Enter two characters: ";
    cin>>x>>z;
    char_check(x,z);
    return 0;
}