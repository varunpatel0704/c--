#include <iostream>
#include <vector>
using namespace std;

bool check(vector <int> ans, int start, int end){ // logic for palindrome check
                                                  // same logic for string as well

    if(start > end)
        return true;
    if(ans[start]!=ans[end])
        return false;
    return check(ans, start+1, end-1);
}

bool checkPalindrome(long long N)
{    
    //long long int ans = 0 , i = 0;
    vector <int> ans;
	while(N){
        int bit = N&1;
//         ans = bit*pow(10,i) + ans;
//         i++;
//         N>>=1;
        ans.push_back(bit);
        N=N>>1;
    }
    //string str = to_string(ans);
    //return check(str, 0, str.length() -1);
    return check(ans, 0, ans.size()-1);
}    

int main(){
    
    return 0;
}