#include <stdio.h>

void printable(int multable[], int num, int n ){//<--- Array and pointer are same 
                                                // things in a function argument.
    for (int i = 0; i < n; i++)
    {
        *(multable+i)=num*(i+1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",multable[i]);
    }
    
    
}
int main()
{   int m,n;
    printf("Enter the number of numbers whose table is to be found: ");
    scanf("%d",&m);
   
    printf("Till where do you want to find the table?");
    scanf("%d",&n);
    int multable[m][n], num;
    for (int c = 0; c < m; c++)
    {   
        printf("Enter the number to find table : ");
        scanf("%d",&num);
        printable(multable[c],num,n);
    }
    
    return 0;
}