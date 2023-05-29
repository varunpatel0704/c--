#include <stdio.h>
int main()
{

    int row1, coloumn1;
    printf("Enter the number of rows and coloumns: ");
    scanf("%d %d", &row1, &coloumn1);

    int matrix1[row1][coloumn1];
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < coloumn1; j++)
        {
            printf("\nEnter the element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    int row2, coloumn2;
    printf("\nEnter the number of rows and coloumns: ");
    scanf("%d %d", &row2, &coloumn2);
    
    if(coloumn1==row2){
        printf("\n\nYou can go ahead with multiplication:");
    }
    
    int matrix2[row2][coloumn2];
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < coloumn2; j++)
        {
            printf("\nEnter element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

   

    printf("\n\nMultipying both matrices.....");
    int element, matrix3[row1][coloumn2];
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < coloumn2; j++)
        {
            element = 0;
            for (int k = 0; k < row2; k++)
            {
                element += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = element;
        }
    }
    printf("\n\nNew matrix is\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < coloumn2; j++)
        {
            printf("%d", matrix3[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}