#include <iostream>
using namespace std;

int volume(int length, int height, int breadth){
    return length*breadth*height;
}
int volume(int radius, int height /*int length*/){
    return radius*height/*length*/;
}

int main(){
    int a=10, b=20, c=5;
    cout<<"The volume is: "<<volume(a,b,c)<<endl;
    return 0;
}