#include <iostream>
using namespace std;

int main(){
    int arr[10]={2,4,7};
    // cout<<arr;
    // cout<<endl<<arr[0];
    // cout<<endl<<*arr;
    // cout<<endl<<&arr[0];
    // cout << endl << *arr + 1;
    // cout << endl << 2[arr];// arr[2]; 

    cout << endl << sizeof(arr);
    cout << endl << sizeof(*arr);

    // int *ptr = arr;
    // cout << endl << *ptr;

    char a = 'c';
    char* ptr = &a;
    cout << endl << &arr;
    cout << endl << arr;

    cout << endl << sizeof(ptr);
    cout << endl << sizeof(*ptr);
    return 0;
}