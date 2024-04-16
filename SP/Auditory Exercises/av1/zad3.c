#include <stdio.h>
int main()
{
    float a = 5;
    float b = 7.5;
    float c = 10.2;
    float L = a+b+c;
    float s = L/2;
    float P = s*(s-a)*(s-b)*(s-c);
    printf("Perimetar: %.2f\nPlostina: %.2f",L,P);
    return 0;
}