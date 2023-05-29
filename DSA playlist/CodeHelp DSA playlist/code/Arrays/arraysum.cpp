#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &c){
    
    for(int i=0; i<c.size()/2; i++){
        swap(c[i], c[c.size()-i-1]);
    }
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i = n-1, j = m - 1;
    int sum = 0, carry = 0;
    vector <int> ans;
    while(i >= 0 and j >= 0){
        sum = a[i--] + b[j--] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    
    while(i >= 0){
        sum = a[i--] + carry;
        carry = sum / 10;
        sum%=10;
        ans.push_back(sum);
    }
    
    while(j >= 0){
        sum = b[j--] + carry;
        carry = sum / 10;
        sum%=10;
        ans.push_back(sum);
        }
    
    while(carry!=0){
        sum = carry;
        carry = sum/10;
        sum%=10;
        ans.push_back(sum);
    }
   reverse(ans);
    return ans;
}

int main(){
    
    return 0;
}