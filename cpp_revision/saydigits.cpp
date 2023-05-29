#include <iostream>
#include <vector>
using namespace std;

void saydigits(vector <string> &arr, int n){
    if(n == 0){
        return;
    }

    int digit = n%10;
    saydigits(arr, n/10);
    cout << arr[digit] << " ";
}

int main(){
    vector <string> arr = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    saydigits(arr, 420);
    return 0;
}