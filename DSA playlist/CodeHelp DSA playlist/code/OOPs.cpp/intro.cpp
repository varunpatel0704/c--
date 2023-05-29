#include <iostream>
using namespace std;

class gow{
    private: // access modifier "private".
        int level;  // private members cannot be accessed outside the class.
        int xp;

    public: // access modifier "public".
        string name;  // public members can be accessed outside the class.
        static int exploration;

        gow(){
            cout<<"Default constructor"<<endl;
        }

        gow(string name, int level, int xp){ // parameterized constructor.
            this->name=name;
            this->level=level; // "this" keyword is a pointer which points to the current object which has called this member.
            this->xp=xp;       // "this->level" is similar to "(*curr_obj).level"
        }
        
        gow(gow &temp){
           cout<<endl<<"copy constructor called"<<endl;
           this->name  = temp.name; // "temp" is the source, "this" is the destination
           this->level = temp.level;
           this->xp = temp.xp;
        }
        
        static int explore(){

            return exploration;
        }
        
        int getlvl(){
            return level;
        }
        int getxp(){
            return xp;
        }

        void setlevel(int lvl){
            level = lvl;
        }
        
        void setxp(int xp){
            this->xp = xp;  // "this" is a pointer to current object. used to differentiate b/w identifiers with same name.
        }
        
        void setname(string name){
            this->name=name;
        }
        
        void getstats(){
            cout<<"Name = "<<this->name<<endl;
            cout<<"Level = "<<level<<endl;
            cout<<"xp = "<<xp<<endl;
        }

        ~gow(){
            cout<<"default destructor called"<<endl; // this is called by default at the end 
        }                                            // of program to delete the static objects.
};
int gow::exploration = 54;
int main(){
    //static creation of object.
    gow boi;
    
    boi.name = "Loki";
    boi.setlevel(1);  // we have to use setter "setlevel()" since level is not a public member.
    boi.setxp(658);
    
    cout<<"Name = "<<boi.name<<endl;
    cout<<"Level = "<<boi.getlvl()<<endl; 
    cout<<"xp = "<<boi.getxp()<<endl;
    cout<<endl;

    // dynamic creation of object.
    gow *mimir = new gow();  // object created dynamically using default constructor.
    (*mimir).name="Mimir";
    mimir->setlevel(2);
    mimir->setxp(78);
    (*mimir).getstats();

    cout<<endl;
    
    gow *sindri = new gow("Sindri", 8, 1);  // object created dynamically using parameterized constructor.
    sindri->getstats();

    gow ghostofsparta("Kratos", 9, 1000);  // object created statically using parameterized constructor.
    ghostofsparta.getstats();
    

    gow kratos(ghostofsparta); // object created using copy constructor.
    cout<<"kratos created from ghostofsparta using copy constructor"<<endl;
    kratos.getstats();
   
    cout<<endl;
    kratos.setname("grumpy buddhho");
    
    kratos.getstats();
    ghostofsparta.getstats();
    
    cout<<endl;
    
    cout<<"exploration = "<<gow::exploration<<"%"<<endl;
    cout << "exploration = "<<gow::explore()<<"%"<<endl;
   
    delete sindri, mimir; // deleting dynamically created objects.
    return 0;
}