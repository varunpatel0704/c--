#include <iostream>
using namespace std;

int main(){
    int arr[10] = {1,23,45,5};
    char ch[6] = "abcde";

    cout << arr <<endl; // prints address of frist index.
    cout << ch <<endl;  // prints entire string.

    char *st = ch;
    cout << st << endl; // prints whole string
    
    char *ptr = ch+3;
    cout << ptr << endl; //prints string after 3rd index. 
    
    char *p = &ch[0];
    cout << *p << endl; // prints first character.
    cout << p << endl;  // prints whole string.
   
    char temp = 'x';
    char *tmp = &temp;

    cout << temp << endl;
    cout << tmp << endl; // prints value of temp then keeps printing till '\0' is not encountered.
    cout << *tmp << endl;// just prints value of temp.

    char *str = "hello";    //BAD PRACTICE.
    cout << str << endl;    
    cout << *str << endl;
    return 0;
}