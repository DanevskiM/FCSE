#include <stdio.h>
int main()
{
    float x,y;
    scanf("%f%f", &x, &y);
    if(x>0 && y>0) printf("I Kvadrant");
    else if(x<0 && y>0) printf("II Kvadrant");
    else if(x<0 && y<0) printf("III Kvadrant");
    else if(x>0 && y<0) printf("IV Kvadrant");
    return 0;
}