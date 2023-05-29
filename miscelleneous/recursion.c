#include <stdio.h>

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int sum(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return n + sum(n - 1);
}

void printpattern(int n)
{
    if (n == 1)
    {  
        printf("*\n");
        return;
    }

    printpattern(n - 1);

    for (int i = 0; i < (2 * n - 1); i++)
    {
        printf("*");
    }
    printf("\n");
}

int main()
{
    int element1, element2;

    printf("Enter the element: ");
    scanf("%d", &element1);
    
    printf("%dth element of fibonacci series is: %d\n", element1, fib(element1));

    printf("Enter the number of terms: ");
    scanf("%d", &element2);
    printf("The sum of first %d natural numbers is: %d", element2, sum(element2));

    printf("\n\n****This is pattern****\n\n");
    printpattern(3);

    return 0;
}
