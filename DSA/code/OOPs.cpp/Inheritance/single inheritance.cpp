#include <iostream>
using namespace std;

class animal{
    public:
    string sound;
   
};

class dog: private animal{
    public:
    void getsound(){
        cout<<"sound is "<<sound<<endl;
    }
};

int main(){
    dog german;
    german.getsound();
    return 0;
}