#include <iostream>
using namespace std;

typedef struct employee   /*typedef is a keyword which allows us to use 
                        short form instead of "struct employee" everytime.*/
{
    int emp_id;
    float salary;
    char favchar;
}emp; //<===="emp is the shortform in this case for "struct employee"//

union money{
    int rice;
    char car;
    float pound;
};


int main(){
    enum meal{ breakfast, lunch, dinner};/*enum stores indices of respective elements as 
                                        integers but it is used to make program more readable*/ 
    cout<<breakfast<<endl;
    cout<<lunch<<endl;
    cout<<dinner<<endl;
    meal m3=breakfast;
    cout<<m3<<endl;
    if(m3==0){
     cout<<"true"<<endl;
    }
   
    union money m1;
    m1.car='d';//<---This will assign d to m1//
    cout<<m1.car<<endl;
    m1.car=101;//<----This will assign character corresponding to 101 ascii value
    cout<<m1.car<<endl;
    m1.rice=99;//<----This will override the value of m1//

    cout<<m1.rice<<endl;/*in union only one type of data can be used at a time since memory is shared among all variables*/

    
    cout<<m1.car<<endl;/*<---This will print the character corrensponding to ascii
                             value 99*/

    /*what is a structure??<=== A structure is a 
    user defined datatype which can hold mixed data in it such as int, char, float, etc*/
    emp tilak;
    tilak.emp_id=1;
    tilak.salary=1000000;
    tilak.favchar='T';
    
    emp electro;
    electro.emp_id=2;
    electro.salary=1000000;
    electro.favchar='V';

    cout<<"The value is:"<<electro.emp_id<<endl;
    cout<<"The value is:"<<electro.favchar<<endl;
    cout<<"The value is:"<<electro.salary<<endl;
    cout<<"The value is:"<<tilak.emp_id<<endl;
    cout<<"The value is:"<<tilak.favchar<<endl;
    cout<<"The value is:"<<tilak.salary<<endl;


    return 0;
}