#include <stdio.h>

struct complex{
    float real;
    float imag;
};
void display(struct complex cmplx[]){
    for(int i=0;i<5;i++){
        printf("The complex no is: %.2f + i%.2f\n",
        cmplx[i].real,cmplx[i].imag);

    }
}



int main(){
    struct complex cmplxno[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the real part for complex no %d: ",i+1);
        scanf("%f",&cmplxno[i].real);
        printf("Enter the imag part for complex no %d: ",i+1);
        scanf("%f",&(cmplxno[i]).imag);
        
    }
    display(cmplxno);
    
    
    return 0;
}