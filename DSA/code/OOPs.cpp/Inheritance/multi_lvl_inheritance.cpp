#include <iostream>
using namespace std;

class A{
    public:
    int value_a;
};

class B: public A{
    public:
    int value_b;
};

class C: public B{
    public:
   
    int value_c(){
        return value_a + value_b;
    }
};

int main(){
    // A a1;
    // a1.value_a = 5;
    
    // B b1;
    // b1.value_b = 10;
    
    C c1;
    c1.value_a = 5;
    c1.value_b = 10;
    cout << "Value C = " << c1.value_c() << endl;
    
    return 0;
}