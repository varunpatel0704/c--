#include <iostream>
#include <string>
using namespace std;

bool isEqual(int arr1[], int arr2[]){
        
        for(int i = 0; i < 26; i++){
            
            if(arr1[i]!=arr2[i])
                return false;
            
        }
        
        return true;
        
    }
    
bool checkInclusion(string s1, string s2) {
    
    int count1[26]={0};
    for(int i = 0; i < s1.length(); i++){
        
        char ch = s1[i];
        int index = ch - 'a';
        count1[index]++; //<-- storing count of each character of s1.
        
    }
    
    int i=0, windowlen=s1.size();
    int count2[26]={0};
    
    while(i<windowlen and i<s2.length()){
        
        char ch = s2[i];
        int index = ch - 'a';
        count2[index]++;
        i++;
    }
    
    if(isEqual(count1, count2))         
        return true;
    
    while(i<s2.length()){
        
        char newchar = s2[i];
        int index = newchar - 'a';
        count2[index]++;  // <-- adding next character to window for comparision.
        
        char oldchar = s2[i-windowlen];
        index = oldchar - 'a';
        count2[index]--; // <-- removing old character from window since no longer needed.
        
        if(isEqual(count1, count2))         
            return true;
        
        i++;
    }
    
    return false;
    
}

int main(){
    string s1, s2;
    cout<<"Enter the string (without spaces) ";
    cin>>s2;
    cout<<"\nEnter the sub string(without spaces) ";
    cin>>s1;

    cout<<"\ns1 in s2? -->"<<checkInclusion(s1, s2);
    
    return 0;
}