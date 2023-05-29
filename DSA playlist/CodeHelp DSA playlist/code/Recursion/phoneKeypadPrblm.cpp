#include <iostream>
#include <vector>

using namespace std;

void findcomb(vector<string> ipstr, string opstr, int index, 
                 vector<string>& comb){
    
    // base case.
    if(index>ipstr.size()-1){
        comb.push_back(opstr);
        return;
    }
    
    
    
    string element = ipstr[index];
    
    for(int i=0; i<element.length(); i++){
        opstr.push_back(element[i]);
        findcomb(ipstr, opstr, index+1, comb);
        opstr.pop_back();
    }
    
        // creating combinations.
    
    
}

    
vector<string> letterCombinations(string digits) {
// generating input string for our recursive function.
    vector<string> keypad = {"","","abc","def","ghi","jkl",
                                "mno","pqrs","tuv","wxyz"};

    vector<string> ipstr;
    vector<string> comb;
    string opstr;
    
    if(!digits.length())
        return comb;
    
    for(int i=0; i<digits.length(); i++){
        int keyindex=digits[i]-'0';
        string element = keypad[keyindex];
        ipstr.push_back(element);
    }

    

    int index=0;

    findcomb(ipstr, opstr, index, comb);

    return comb;

}

int main(){
    
    return 0;
}