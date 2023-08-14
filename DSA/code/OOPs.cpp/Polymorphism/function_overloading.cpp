#include <iostream>
using namespace std;

class funcOverload{
    public:
    
    void hello(){
        cout<<"Hello there"<<endl;
    }

    void hello(string name){
        cout<<"Hello "<<name<<endl;
    }
   
    void hello(string a, string b){
        cout<<a+b<<endl;
    }
   
    int hello(int n){
        cout<<"Hello "<<n<<endl;
        return 0;
    }

};

int main(){

        funcOverload one;
        one.funcOverload::hello();
        
        one.hello(90);
        
        one.hello("Electro");
        
        one.hello("Hello ", "Varun");

    return 0;
}