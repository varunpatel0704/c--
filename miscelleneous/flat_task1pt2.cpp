#include <iostream>
#include <vector>
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

int main(){
    vector<string> strings;
    string str;

    cout<<"Enter the space separated set of identifiers (enter '/stop' to terminate input stream): ";
    
    while(true){
        cin >> str;
        if(str == "/stop")
            break;
        strings.push_back(str);

    }

    // validate all the identifiers
    for(auto str: strings){
        bool isValid = validateString(str);
        if(!isValid){
            cout << "Error: invalid identifier [" << str << "];" << endl;
            break;
        }        
    }
    




    return 0;
}