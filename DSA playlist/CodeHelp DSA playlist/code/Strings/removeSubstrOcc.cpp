#include <iostream>
#include <string>
using namespace std;

string removeOccurrences(string s, string part) {
        
    while(s.length()!=0 and s.find(part)<s.length()){
        
        s.erase(s.find(part), part.length());
        
    }
    
    return s;
    
}

int main(){
    
    return 0;
}