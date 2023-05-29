#include <iostream>
using namespace std;

class parent{
    public:
    void action(){
        cout<<"Parents run the house"<<endl;
    }
};

class child: public parent{
    public:
    void action(){
        cout<<"Children go to school"<<endl;
    }
};

int main(){

    child first;
    first.action();
    //first.parent::action();


    return 0;
}