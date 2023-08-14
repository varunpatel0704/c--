#include <iostream>
#include <vector>
using namespace std;

void display(vector<char> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
        //cout<<v[i]<<" ";
    }
    cout<<endl;
}

void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
        //cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    //Ways to create a vector.
    vector<int> vec1;
    vector <char> vec2;
   
    vec2.push_back('0');
    vec2.push_back('1');
    vec2.push_back('2');

    vec2.pop_back();

    cout<<"displaying vec2 "<<endl;
    display(vec2);
    vector <char> vec3(vec2);//initialize vec3 with vec2.
    
    vector <int> vec4(6,4);// will initialize vec4 of size 6 with elements equal to 4.

    cout<<"\nSize of vec4 is "<<vec4.size()<<endl;
    cout<<"first element->"<<vec4.front()<<endl;
    cout<<"last element->"<<vec4.back()<<endl;

    display(vec4);

    int element, size;
    cout<<"Enter the size of the vector ";
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cin>>element;
        vec1.push_back(element);
    }

    //vec1.pop_back(); <-- delete the last element.
    
    cout<<"Before insert\n"<<endl;
    display(vec1);
    
    
    vector<int>:: iterator iter = vec1.begin();
    vec1.insert(iter+1, 5, 69);//<--- inserts 69 to 2nd position or 1st index.
    
    cout<<"After insert\n"<<endl;
    display(vec1);
    
    return 0;
}