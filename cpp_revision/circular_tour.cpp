#include <iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump arr[], int n)
{
    // Your code here
    //  brute force. check circular tour for each index

    for (int i = 0; i < n; i++)
    {
        int j = i;
        int dte = arr[i].petrol, dist;
        bool found = 1;
        do
        {
            cout << "currently at petrol pump " << j;
            cout << " current dte -> " <<dte;
            dist = arr[i].distance;
            cout << " distance to cover -> " << dist <<endl;
            
            if (dte < dist)
            {   found = 0;
                break;
            }
            dte = dte - dist;
            j = (j + 1) % n;
            dte = dte + arr[j].petrol;

        } while (j != i);
        if (j == i && found)
            return i;
    }
    return -1;
}

int main()
{
    petrolPump arr[4];
    arr[0].petrol = 4; arr[0].distance = 6; 
    arr[1].petrol = 6; arr[1].distance = 5;
    arr[2].petrol = 7; arr[2].distance = 3;
    arr[3].petrol = 4; arr[3].distance = 5;

    tour(arr, 4);
    return 0;
}