#include <iostream>
#include <stack>
using namespace std;

int countRev (string str) // my solution
{   
    if(str.length()%2 != 0)
        return -1;

    int revcnt = 0;
    stack <char> s;

    for(int i = 0; i < str.length(); i++){

        char ch = str[i];
        
        // incoming -> opening bracket 
        if(ch == '{')
            s.push(ch);

        // incoming -> closing bracket
        else{
            
            // s.top is open bracket. Therefore match
            // found and no need to reverse.
            if(!s.empty() && s.top() == '{')
                s.pop();
            
            // stack is empty, reverse the current bracket
            // and insert into stack, also increment revcnt.
            else if(s.empty()){
                s.push('{');
                revcnt++;
            }   
        }
    }

    // stack may contain pairs of open brackets
    // therefore we will reverse one bracket from each pair 
    // and pop the pair from stack and 
    // also increment the revcnt 
    while(!s.empty()){
        s.pop();
        s.pop();
        revcnt++;
    }

    return revcnt;
}

int findMinimumCost(string str) {
    // Write your code here
    if(str.length()%2 == 1){
        return -1;
    }

    stack <char> s;
    // remove valid part of string.
    for(int i = 0; i < str.size(); i++){
      char ch = str[i];
      // open bracket.
      if(ch == '{'){
          s.push(ch);
      }
      
      // closed bracket.
      else{
          // corresponding open bracket present at stack top.
          // therefore pop.
          if(!s.empty() && s.top() == '{'){
              s.pop();
          }

          // if no open bracket found then simply push current 
          // bracket into stack.
          else{
              s.push(ch);
          }
      }
    }

    int cnt_open = 0, cnt_closed = 0;
    // find count of open and closed brackets in the stack.
    while(!s.empty()){
      if(s.top() == '{'){
        cnt_open++;
      }

      else{
        cnt_closed++;
      }
      s.pop();
    }

    int ans = ((cnt_open+1)/2) + ((cnt_closed+1)/2);
    return ans;
}

int main(){
    
    return 0;
}