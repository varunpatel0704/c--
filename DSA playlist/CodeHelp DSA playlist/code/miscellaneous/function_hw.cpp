#include <iostream>
using namespace std;

int ap_term(int n){//<--function to find nth term of given A.P.
    return 3*n+7;
}

int no_bits(int a,int b){
    int count=0;
    while(a!=0 or b!=0){
        int bit=a&1;
        if (bit)
        {
            count++;
        }
        
        bit=b&1;
        if (bit)
        {
            count++;
        }
        
        b>>=1;
        a>>=1;
    }
    return count;
}

int term_fib(int n){
    int num1=0,num2=1,num3;
     if (n==1)
        {
            return num1;
        }
    if (n==2)
        {
            return num2;
        }
    
    for (int i = 3; i <=n; i++)
    {        
        num3=num1+num2;
        num1=num2;
        num2=num3;
    }
    return num3;
    
}

int main(){
    // int n;
    // cin>>n;
    // cout<<"nth term of A.P. is="<<ap_term(n)<<endl;
    
    // int a,b;
    // cin>>a>>b;
    // cout<<"number of 1 bits in a&b= "<<no_bits(a,b);

    int term;
    cin>>term;
    cout<<"nth term of fibonacci series is "<<term_fib(term);
    return 0;
}