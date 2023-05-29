#include <stdio.h>
int main()
{
    int row, coloumn;
    printf("Enter the number of rows and coloumns: ");
    scanf("%d %d", &row, &coloumn);

    int matrix1[row][coloumn];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
            printf("\nEnter the element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("\nYou entered the following matrix");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
            printf("%d", matrix1[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    
    printf("\nTaking transpose of the matrix....");
    int row2=coloumn;
    int coloumn2=row;
    
    int matrix2[row2][coloumn2];
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < coloumn2; j++)
        {
            matrix2[i][j]=matrix1[j][i];
        }
    }

    printf("\n\nNew matrix is\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < coloumn2; j++)
        {
            printf("%d", matrix2[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}