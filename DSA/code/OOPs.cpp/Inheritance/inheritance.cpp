#include <iostream>
#include <string>
using namespace std;

class human{
    public:
        string name;
        int age;
        int height;
    // public:
        int getage(){
            return this->age;
        }
};

class male: public human{ // inheriting human class in public mode.
    string colour;
    public:
    void setcolour(string color){
        colour=color;
    }
    void origin(){
        cout<<"American fat dobber"<<endl;
    }
    void getcolour(){
        cout<<"colour is "<<this->colour<<endl;
    }
};

int main(){
    male m1;
    m1.name="noob";
    m1.age=78;
    m1.height=101;
    m1.setcolour("white");
    m1.origin();

    m1.getcolour();
    cout<<"name = "<<m1.name<<endl;
    cout<<"age = "<<m1.age<<endl;
    cout<<"height = "<<m1.height<<endl;
    return 0;
}