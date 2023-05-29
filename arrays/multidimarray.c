#include <stdio.h>
int main(){
    int n_students=3, n_subjects=5;
    int marks[3][5];
    for (int i = 0; i < n_students; i++)
    {
        for (int j= 0; j < n_subjects; j++)
        {
            printf("Enter the marks of student %d in subject %d: ",i+1,j+1);
            scanf("%d",&marks[i][j]);
        }
    }
    for (int i = 0; i < n_students; i++)
    {
        for (int j= 0; j < n_subjects; j++)
        {
            printf("The marks of student %d are: %d \n",i+1,marks[i][j]);
            
        }
    }

    

    return 0;
}