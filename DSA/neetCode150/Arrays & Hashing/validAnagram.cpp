#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char, int> charCount;
    for(int i=0; i < s.length(); i++){
        charCount[s[i]]++;
    }

    for(int i=0; i < t.length(); i++){
        charCount[t[i]]--;
    }

    for(auto i: charCount){
        if(i.second != 0)
            return false;
    }

    return true;        
}

int main(){
    
    return 0;
}