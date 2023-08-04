#include <iostream>
#include <vector>
using namespace std;

// using nested loops
string longestCommonPrefix(vector<string>& strs) {
    // approach 1: match the characters of each word using two nested loops.
    string ans="";
    for(int i=0; i<strs[0].size(); i++){ // pick the first string in the vector.
        char ch = strs[0][i];
        bool match = true;

        for(int j=1; j<strs.size(); j++){ // compare characters of first string with 
                                            // rest of the strings in the vector.
            if(strs[j].length() < i || strs[j][i] != ch){ // length of current string less the index of character we are comparing
                                                         // i.e. we can't compare it if it doesn't exist lol
                match = false;
                break;
            }

        }

        if(!match)
            break;
        else
            ans.push_back(ch);

        
    }
    return ans;
}

// using Trie....pending
class TrieNode{
    public:

    char ch;

    TrieNode* children[26]; // <-- array of pointers for 26 english alphabets, each pointer points to a child node if exists.
    bool isTerminal;
    int childCount;

    TrieNode(char ch){
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
            isTerminal = false;
            this->ch = ch;
            childCount=0;
        }
    }

    void insert(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        TrieNode* temp; // iterator to traverse the tree.
        int index = word[0] - 'a'; // the index at which child should be present in the array of pointers.
        
        // character present.
        if(root->children[index] != NULL){
            temp = children[index]; // point the iterator to the child then make recursive call to further search for string.
            insert(temp, word.substr(1));
        }

        // character not present.
        else{
            temp = new TrieNode(word[0]);
            root->children[index] = temp;
            insert(temp, word.substr(1));
        }
    }

    bool search(TrieNode* root, string word){
        if(word.length() == 0){
            return (root->isTerminal);
        }

        // character present, search further.
        TrieNode* child;
        int index = word[0] - 'a';
        if(root->children[index]){
            child = root->children[index];
            return search(child, word.substr(1));
        }

        else{
           return false;
        }
    }

    void remove(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }

        TrieNode* temp;
        int index = word[0] - 'a';
        
        // assuming that the word is guaranteed to exist in the trie.
        temp = root->children[index];
        remove(temp, word.substr(1));
        
    }
    
};
int main(){
    
    return 0;
}