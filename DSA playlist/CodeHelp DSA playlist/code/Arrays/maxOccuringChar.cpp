#include <iostream>
#include <string>
using namespace std;

char getMaxOccuringChar(string str)
{
    int arr[26] = {0}, index;
    
    for (int i = 0; i < str.size(); i++)
    {
        index = str[i] - 'a';
        arr[index]++;
    }

    int max = -1, ans;
    
    for (int j = 0; j < 26; j++)
    {

        if (max < arr[j])
        {
            ans = j;
            max = arr[j];
        }
    }

    return ans + 'a';

}

int main()
{

    return 0;
}