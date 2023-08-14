#include <iostream>
#include <string>
using namespace std;

int adjacent(string s){
    int i=0, j=1;

    while(j<s.size()){

        if(s[i]==s[j]){
            return i;
        }

        i++, j++;
    }
    
    return -1;
    
}

string removeDuplicates(string s) {
    int i=0;
    while(adjacent(s) != -1) {
        cout << s << endl;
        s.erase(adjacent(s),2);   
    }
    
    return s;
    
}

int main(){
    string s1 = "looooooooooloooooool";
    //cout << adjacent(s1) << endl;
    string s2 = removeDuplicates(s1);
    cout << "Final ans -->"<< s2 << endl;
    return 0;
}