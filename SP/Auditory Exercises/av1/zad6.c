#include <stdio.h>
int main()
{
    float PI=3.14;
    float r;
    scanf("%f", &r);
    float L = 2*r*PI;
    float P = r*r*PI;
    printf("Plostina: %.2f\nPerimetar: %.2f", P, L);
    return 0;
}