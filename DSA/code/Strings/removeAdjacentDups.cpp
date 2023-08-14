#include <iostream>
#include <string>

//some test cases not passed.
using namespace std;

 string removeDuplicates(string s) {
  
    int run=0;
    while(run<s.size()){
        
        int i=0, j=1;
       
        while(j<s.size()){
            
            if(s[i]==s[j]){                                 //"aaaaaaaaaa"
                                                            // 0123456789
                s.erase(i,2);
            }
            
            i++, j++;
        }

        run++;
    }
    int i=0, j=1;
    if(s[i]==s[j]){
        s.erase(i,2);
    }
    return s;    
}

int main(){
    string s="aaaaaaaaaa";
    cout<<removeDuplicates(s);
    return 0;
}