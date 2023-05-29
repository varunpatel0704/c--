#include <iostream>
using namespace std;

/*Function prototyping
syntax==> type_name(arguments);

int sum(int a, int b);<---- Acceptable
int sum(int a, b); <---- Not acceptable*/
int sum(int ,int );//<---- Acceptable

//void g(void);<---- Acceptable
void g();

int main(){
    int num1, num2;//<===num1 and num2 are actual parameters
    cout<<"Enetr the first number: "<<endl;
    cin>>num1;
    cout<<"Enetr the second number: "<<endl;
    cin>>num2;
    cout<<"The sum is: "<<sum(num1,num2)<<endl;
    g();
    
    return 0;
}
int sum(int a, int b){
    /*formal parametrs a and b will be taking values 
    from actual parameters num1 and num2*/
    int c=a+b;
    return c;
}
void g(){
    cout<<"\nHello, goodmorning!";
}