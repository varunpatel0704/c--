#include <iostream>
using namespace std;

int factorial(int n){
    if (n == 0)
    {
        return 1;
    }
    
    return n*factorial(n-1);
}
void print(int n){
    if( n == 0){
        return;
    }
    cout<<n<<endl;
    print(n-1);

}
void revprint(int n){
    if( n == 0){
        return;
    }
    
    revprint(n-1);
    
    cout<<n<<endl;

}
int main(){
    int n;
    
    cout << "Enter n ";
    cin >> n;
    //cout<<factorial(n);
    cout << endl;
    revprint(n);
   
    cout <<endl;
    print(n);
    return 0;
}