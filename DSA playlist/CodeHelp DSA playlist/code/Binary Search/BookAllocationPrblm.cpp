#include <iostream>
using namespace std;

bool isPossible(int arr[], int len, int mid, int students)
{
    int pagesum = 0, stud_count = 1;

    for (int i = 0; i < len; i++)
    {
        if (pagesum + arr[i] <= mid)
        {
            pagesum += arr[i];
        }

        else
        {

            stud_count++;
            pagesum = 0;
            pagesum += arr[i];

            if (stud_count > students || pagesum > arr[i])
            {
                return false;
            }
        }
    }

    return true;
};

int bookAlloc(int arr[], int len, int students)
{

    // this function applies binary search.
    int start = 0, end = 0, ans = -1;

    for (int i = 0; i < len; i++)
    {
        end += arr[i]; // this loop finds the max value of our search space i.e. sum of array.
    }

    int mid = start + (end - start) / 2; // mid here represents no of pages that we get from out search space.

    while (start <= end)
    {
        if (isPossible(arr, len, mid, students))
        {
            ans = mid;
            end = mid -1;
        }

        else
        {

            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    int books[4]={10,20,30,40};
    int pages=bookAlloc(books,4,2);
    cout<<"no of pages allocated to student is "<<pages;
    return 0;
}