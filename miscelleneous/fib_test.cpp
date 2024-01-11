#include <iostream>
using namespace std;

//define a random class
class Test{
    public:
        int a;
        int b;
        Test(){}
        Test(int a, int b){
            this->a = a;
            this->b = b;
        }
};

int main(){
    // int n=8;
    // int prev = 0, curr = 1, next;
    // for (int i = 0; i < n; i++)
    // {
    //     if(i==0 || i==1){
    //         cout << i << ", ";
    //     }
    //     else{
    //         next = prev + curr;
    //         prev = curr;
    //         curr = next;
    //         cout << next << ", ";
    //     }

    // }
    Test *a = new Test();
    return 0;
}