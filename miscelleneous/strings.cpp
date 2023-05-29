#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s1,s2,s3;
    vector <char> st1, st2;
    st1.push_back('a');
    st2=st1;
    cout<< (st2==st1)<<endl;
    s1="hello";
    cout<<s1.find("e");
    // cout<<"Please enter your name: ";
    // cin>>s1;
    // fflush(stdin);
    // cout<<"Enter your surname: ";
    // cin>>s2;

    // cout<<"Your full name is :"<<s1+" "+s2; 

    // cout<<"\nyour first name is: "<<s3.append(s1+s2,5,2);
    int n = 2;

    // while(n){
    //     fflush(stdin);
    //     getline(cin, s1);
    //     cout<<s1<<endl;
    //     n--;
    // }

   

    return 0;
}