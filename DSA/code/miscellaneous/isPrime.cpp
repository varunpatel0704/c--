#include <iostream>
using namespace std;
// 0-->not prime
// 1-->prime
bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int num;
    cin >> num;
    if (isPrime(num))
    {
        cout << "number is prime" << endl;
    }
    else
    cout << "number is not prime" << endl;
    return 0;
}