#include <iostream>
using namespace std;

int main(){
    int marks[4]={95,69,97,56};
    cout<<"elemens of marks are: "<<endl;
    cout<<marks[0]<<endl;
    cout<<marks[1]<<endl;
    cout<<marks[2]<<endl;
    cout<<marks[3]<<endl;
    
    int marks2[4];
    marks2[0]=100;/*This is another way of assigning elements to array*/
    marks2[1]=58;
    marks2[2]=68;
    marks2[3]=78;
    /*printing elements of array using for loop*/
    cout<<"this is using for loop: "<<endl;
    for(int i=0; i<4; i++ ){
        cout<<"The value of element at "<<i
        <<" position is "<<marks2[i]<<endl;
    }

    int a=0;
    cout<<"this is using while loop :"<<endl;
    while(a<4){
         cout<<"The value of element at "<<a
        <<" position is "<<marks2[a]<<endl;
        a++;
    }
    cout<<"this is using do while loop :"<<endl;
    int b=0;
    do{
         cout<<"The value of element at "<<b
        <<" position is "<<marks2[b]<<endl;
        b++;
    }while(b<4);



    cout<<"the original value is: "<<marks2[3]<<endl;
    
    marks2[3]=45;/*changing the value of element at 3rd position*/
    cout<<"the new value is: "<<marks2[3]<<endl;
   
    //pointers and arrays//
    int*p=marks2;
    cout<<"The value of marks[0] i.e. p is "<<*p<<endl;
    cout<<"The value of marks[1] i.e. p+1 is "<<*(p+1)<<endl;/*this will show thw value of 
                                                     elements at respective indices*/
    cout<<"The value of marks[2] i.e. p+2 is "<<*(p+2)<<endl;
    cout<<"The value of marks[3] i.e. p+3 is "<<*(p+3)<<endl;

    cout<<*(p++)<<endl;//<----- increments value of p by one after printing//
    cout<<*(++p)<<endl;//<-----  again increases the value of p but this time before printing//

    return 0;  
}

