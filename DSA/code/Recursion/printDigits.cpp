#include <iostream>
#include <string>
using namespace std;

void printDigits(int num, string arr[]){
    
    if (num == 0)
        return;

    int digit = num % 10;
    
    printDigits(num / 10, arr);
    
    cout << arr[digit] << " ";
    
}

int main(){
    string arr[10] = {"zero","one","two","three",
                            "four","five",
                    "six","seven","eight","nine"};
    
    int num;
    cin >> num;
    
    printDigits(num, arr);
    
    return 0;
}