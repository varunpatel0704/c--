#include <iostream>
using namespace std;

class operatorOverload{
    public:
    int val;
    void operator+ (){
        cout<<"'+' overloaded"<<endl;
    }

    int operator* (operatorOverload &temp){
        int value1 = this -> val;
        int value2 = temp.val;
        cout<<"'*' will act as '%' "<< value1 % value2 <<endl;
        return 0;
    }
};

int main(){
    
    operatorOverload a, b;
    a.val = 10;
    b.val = 12;

    a*b; // 10 % 12 --> remainder = 10.


    return 0;
}