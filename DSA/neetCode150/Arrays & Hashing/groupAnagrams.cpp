#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagrams;

        /* anagrams are words with same letters but in different order.
           so if we sort the given strings then we'll get the same word from each
           anagram. for e.g. "eat", "ate", "eta" will give the word "aet" when 
           sorted.
           Hence we can simply create map and map all the anagrams to a single
           identifier obtained by sorting them and thus group them together. 
        */
        for(auto word: strs){
            string identifier = word;
            sort(identifier.begin(), identifier.end());
            anagrams[identifier].push_back(word);
        }

        for(auto item: anagrams){
            ans.push_back(item.second);
        }
        
        return ans;
    }

int main(){
    
    return 0;
}