#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

bool validateString(string &str){
    if(!((str[0] == '_') || (str[0]>='a' && str[0] <= 'z') || (str[0]>='A' && str[0] <= 'Z')))
        return false;
    for (int i = 0; i < str.size(); i++){
        if(!((str[0] == '_') || (str[0]>='a' && str[0] <= 'z') || (str[0]>='A' && str[0] <= 'Z')))
            return false;
    }

    return true;    
}

string validateIdentifiers(vector<string> &strings){
    // validate all the identifiers
    for(auto str: strings){
        bool isValid = validateString(str);
        if(!isValid)        
            return str;              
    }

    return "1";
}

int main(){
    vector<string> strings;
    string str;
    unordered_map<string, bool> indentifiers;

    cout<<"Enter the space separated set of identifiers (enter '/stop' to terminate input stream): ";
    
    while(true){
        cin >> str;
        if(str == "/stop")
            break;
        strings.push_back(str);

    }

    string result = validateIdentifiers(strings);
    if(result != "1")
        cout << "Error: invalid identifier [" << result << "];" << endl;
    else    
        cout << "All indentifiers are valid" << endl;
    
    
    //  take the expression as input from user.
    cout << "Enter the expression: ";
    cin >> str;
    
    vector<char> operators = {'*', '/', '+', '-', '%'};
    stack<char> st;


    int i = 0, j = 0;
    // while (j < str.size()){
    //     if(str[j] != )
    // }
    
    for(auto symbol: str){
        if (count(operators.begin(), operators.end(), symbol)){ // arithmetic operator encountered
            char top = st.top();

            if(count(operators.begin(), operators.end(), top))
                cout << "Error: invalid expression (adjacent occurence of operators is not allowed);" << endl;
            
            
            
        }

        else{

        }
        
    }





    return 0;
}