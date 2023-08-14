#include <iostream>
using namespace std;

class first{
    public:
        void func(){
            cout<<"Inside first"<<endl;
        }

};

class second{
    public:
        void func(){
            cout<<"Inside second"<<endl;
        }

};

class third: public first, public second{
    public:
};

int main(){
    third obj;
    // obj.func(); <- inheritance ambiguity. Functions of same name in both parent classes.
    obj.second::func(); // <- scope resolution operator necessary to tell which function is being used.


    return 0;
}