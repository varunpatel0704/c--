#include <iostream>
using namespace std;

class a{  
    public:
    string main_home;
};

class b: private a{
    public:
    string gethome(){
        return main_home;
    }
    
    void sethome(string home){
        this->main_home = home;
    }
    
    string b_home;
};

class c: public a{
    public:
    string c_home;
};

int main(){
    a obja;
    obja.main_home = "New Vaibhav";
    cout<<"object a's main home "<<obja.main_home<<endl<<endl;
   
    b objb;
    objb.sethome("New Vaibhav");
    objb.b_home = "Home B";
    
    cout<<"object b's main home "<<objb.gethome()<<endl;
    cout<<"object b's second home "<<objb.b_home<<endl<<endl;

    c objc;
    objc.main_home = "New Vaibhav";
    objc.c_home = "Home c";
    cout<<"object c's main home "<<objc.main_home<<endl;
    cout<<"object c's second home "<<objc.c_home<<endl<<endl;


    return 0;
}