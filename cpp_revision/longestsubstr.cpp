#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> ans;
    for(int i = 0; i < s.length()-1; i++){
        map<char, bool> visited;
        visited[s[i]] = true;
        int j = i+1;
        while(j < s.length()){
            if(visited[s[j]] != true){
                visited[s[j]] = true;
                j++;
            }
            else    
                break;
        }
        int len = j-i;
        ans.push_back(len);
    }
    int Max = 1;
    for(int i = 0; i < ans.size(); i++){
        Max = max(ans[i], Max);
    }

    return Max;
}

int main(){
    
    string s1 = "pwwkew";
    int longest = lengthOfLongestSubstring(s1);

    cout<<"length of longest sub string " <<longest<<endl;

    return 0;
}