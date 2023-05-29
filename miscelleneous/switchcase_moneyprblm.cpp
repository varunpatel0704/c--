#include <iostream>
using namespace std;

int main(){
    int amt=1330;
    switch (1){
        case 1: 
            cout<<"number of 100rs notes="<<amt/100<<endl;
            amt=amt%100;
        case 2:
            cout<<"number of 50rs notes="<<amt/50<<endl;
            amt=amt%50;
        case 3:
            cout<<"number of 20rs notes="<<amt/20<<endl;
            amt=amt%20;
        case 4:
            cout<<"number of 10rs notes="<<amt/10<<endl;
            amt=amt%10;
        case 5: 
            cout<<"number of 1rs notes="<<amt<<endl;
            
        }
    return 0;
}   