#include <iostream>
#include <string>
using namespace std;

bool isvalid(char ch){
    if((ch>='a' and ch<='z')||(ch>='A' and ch<='Z')||(ch>='0' and ch<='9')){
        return true;
    }
    return false;
}

char toLower(char ch){
    if((ch >= 'a' and ch <= 'z')||(ch >= '0' and ch <= '9')){
        return ch;
    }
    else{
        return(ch-'A'+'a');
    }
}
    
bool isPalindrome(string s) {
    
    string temp;
    //remove useless characters
    for(int i=0; i<s.size(); i++){

        if(isvalid(s[i])){
            
            temp.push_back(s[i]);
        }      
    }
    
    //convert into lower case.
    for(int j=0; j<temp.size(); j++){

        temp[j]=toLower(temp[j]);
    
    }
    
    int start=0, end=temp.size()-1;
    
    while(start<=end){
        if(temp[start]!=temp[end]){
            return false;
        }
        start++, end--;
    }
    return true;
    
}
int main(){
    string s="N2 i&nJA?a& jnI2n";
    cout<<"Palindrome -> "<<isPalindrome(s);
    
    return 0;
}