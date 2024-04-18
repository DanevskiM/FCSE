#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c;
    scanf("%f%f%f", &a, &b, &c);
    if(a+b<=c || a+c<=b || b+c<=a) printf("Nemoze da se konstruira traigolnik");
    else
    {
        if(a==b && b==c) printf("Triagolnikot e ramnostran");
        else if(a==b || b==c || a==c) printf("Triagolnikot e ramnokrak");
        else printf("Triagolnikot e raznostran");
    }
    float s = (a+b+c)/2.0;
    float plostina = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Plostina: %f", plostina);
    return 0;
}