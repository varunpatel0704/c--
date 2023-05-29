#include <bits/stdc++.h> 
using namespace std;


int main(){
    // string test = " world";
    // test.insert(0,"hello",2,3);
    // cout<<test;
               //0123456789abcde
    string s1 = "this is example lol";
    string s2 = "an example";
    s1.replace(8,s2.length(),s2);
    cout<<s1;
    return 0;
}