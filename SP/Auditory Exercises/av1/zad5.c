#include <stdio.h>
int main()
{
    int br = 19;
    int a = 2;
    int b = 3;
    int c = 5;
    int d = 8;
    printf("Ostatok pri delenje na %d so %d e %d\n", br,a,br%a);
    printf("Ostatok pri delenje na %d so %d e %d\n", br,b,br%b);
    printf("Ostatok pri delenje na %d so %d e %d\n", br,c,br%c);
    printf("Ostatok pri delenje na %d so %d e %d", br,d,br%d);
    return 0;
}