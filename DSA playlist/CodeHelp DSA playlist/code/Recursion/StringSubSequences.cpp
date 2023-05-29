#include <iostream>
#include <vector>
using namespace std;

void findsubsequences(string str, string substr, int index, vector<string>& set){
    // base case.
    if(index>str.size()-1){
    if(substr.length()>0){
        set.push_back(substr);
    }
    return;
    }


    // exclude.
    findsubsequences(str, substr, index+1, set);

    // include.
    char element = str[index];
    substr.push_back(element);

    findsubsequences(str, substr, index+1, set);

    }

    vector<string> subsequences(string str){

    string substr = "";
    vector <string> set;

    int index = 0;

    findsubsequences(str, substr, index, set);
    return set;

    }



int main(){
    
    return 0;
}