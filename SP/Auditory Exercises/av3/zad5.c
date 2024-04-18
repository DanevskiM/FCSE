#include <stdio.h>
int main()
{
    float a,b,c;
    scanf("%f%f%f", &a, &b, &c);
    if(a+b<=c || a+c<=b || b+c<=a) printf("Nemoze da se konstruira traigolnik");
    else {
        if(a>b)
        {
            float tmp = a;
            a=b;
            b=tmp;
        }
        if(a>c)
        {
            float tmp = a;
            a=c;
            c=tmp;
        }
        if(b>c)
        {
            float tmp = b;
            b=c;
            c=tmp;
        }
        if (c * c == a * a + b * b) printf("Pravoagolen");
        else printf("Ne e pravoagolen");
    }
}