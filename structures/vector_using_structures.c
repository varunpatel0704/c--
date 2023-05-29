#include <stdio.h>
struct vector{
    int x;
    int y;
}typedef vec;


struct vector sumvector(vec v1, vec v2){
    vec sum;
    sum.x= v1.x+v2.x;
    sum.y= v1.y+v2.y;
    return sum;
}

int main(){
    vec v1,v2;
    v1.x=100;
    v1.y=68;
    v2.x=93;
    v2.y=49;
    printf("x dimension= %d and y dimension= %d\n",v1.x,v1.y);
    printf("x dimension= %d and y dimension= %d\n",v2.x,v2.y);
    vec sum;
    sum=sumvector(v1,v2);
    printf("The sum of  x and y dimensions of v1 + v2 = %d,%d\n",sum.x,sum.y);

    return 0;
}