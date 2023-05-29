#include <iostream>
#include <vector>
using namespace std;

class DC{
    
    private:
    // by default class members are marked as private.
    int budget;
    vector<string> cast;

    public:
    
    DC(){
        cout<<"custom constructor called"<<endl;
    }
    // constructor overloading is allowed.
    
    DC(int budget, string project){
        this->budget = budget;
        this->project = project;
        cout<<"object initialized"<<endl;
    }
    

    // custom destructor.
    ~DC(){
        cout << "hap!!" << endl;
    }
    string project;
    
    void getproject(){
        cout<<project<<endl;
    }

    int getbudget(){
        return this->budget;
    }

    void setbudget(int value){
        budget = value;
    }

};

class theBatman: public DC{
    public:
    string kills;

};

int main(){
    // creating a static object.
    DC theFlash;
    theFlash.project = "tras";
    theFlash.setbudget(700);
    cout<<"the flash has a budget of " <<theFlash.getbudget() << endl;
    cout<<"the flash project name -> " <<theFlash.project<<endl;
    
    DC mos(300, "garbage");
    cout<<mos.project<<endl;

    DC* hapsiAdam = new DC(-1, "rip");
    cout << hapsiAdam->project <<endl;
    // in case of dynamic object, destructor is called only when object is deleted manually.
    delete hapsiAdam;

    theBatman chapeman;
    chapeman.kills = "bov lalchi";
    // project is a public member from class DC
    chapeman.project = "bov paisa che, chapeman > crazy ";
    cout<<chapeman.project<<endl;
    

    return 0;
}