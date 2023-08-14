#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
    // ordered map operations take O(log(n)) time for insertion, deletion and searching.
    
    map<string, int> m1;
    // this is how elements can be inserted
    // map[key] = val;
    
    m1["varun"] = 99;
    m1["hello"] = 1;
    m1["I'm "] = 11;

    pair<string,int> p1 = make_pair("hi", 0);
    m1.insert(p1);

    pair<string, int> p2("ok", 7);
    m1.insert(p2);


    // traversing the map and accessing its elements
    for(auto i: m1){
        cout << i.first << " " << i.second <<endl;
    }cout<<endl;

    // or

    map<string, int>:: iterator it = m1.begin();
    while(it != m1.end()){
        cout << it->first << " " << it->second <<endl;
        it++;
    }cout<<endl;

    // searching/accessing.
    cout << m1.at("varun") << endl;
    cout << m1["varun"] << endl;

    // searching elements not present in the map.
    // cout << m1.at("bro") << endl; <-- will throw error whenever we search for items not in map. 
    cout << m1["bro"] << endl; // <-- creates a key with value 0 whenever we search a key which is not present in map.
    cout << m1.at("bro") << endl; // won't throw error now since key is created in previous step.

    // to check the size of map
    cout << "\nsize of map --> " << m1.size() << endl;

    // to check for presence of a key in the map
    cout << "varun present in map? --> " << m1.count("varun") << endl;
    cout << "tilak present in map? --> " << m1.count("tilak") << endl;

    // remove a key, value pair from map.
    m1.erase("bro");
    cout << "\nsize of map after erasing 'bro'--> " << m1.size() << endl;
    cout << "'bro' present in map? --> " << m1.count("bro") << endl;
    return 0;
}