#include <iostream>
using namespace std;



int main(){

    int x = 5;
    int *p = &x;
    int *pcpy = p; // creates a copy of pointer p.

    cout << p << endl;
    cout << pcpy << endl;
    
    int **p2 = &p;

    cout << endl;
    
    cout <<"Adderess of x : "<< &x << endl;
    cout <<"Adderess of x : "<< p << endl;
    cout <<"Adderess of x : "<< *p2 << endl;

    cout << endl;

    cout <<"x: " <<x << endl;
    cout <<"x: " <<*p << endl;
    cout <<"x: " <<**p2 << endl;

    cout << endl;

    cout << "Address of p: " << &p << endl;
    cout << "Address of p: " << p2 << endl;
    
    cout << endl;
    return 0;
}