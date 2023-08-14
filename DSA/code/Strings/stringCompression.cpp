#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
        
        int i=0, ansIndex=0;
        while(i<chars.size()){
            
            int j=i+1;
            
            while(j<chars.size() and chars[i]==chars[j]){
                j++;
            }
            
            chars[ansIndex]=chars[i];
            ansIndex++;
            
            int count = j-i;
            
            if(count>1){
                
                string cnt=to_string(count);
                for(char ch: cnt){
                    chars[ansIndex++]=ch;       
                    //ansIndex++;
                }                
            }
            
            i=j;
            
        }
        
        return ansIndex;
        
    }

int main(){
    
    return 0;
}