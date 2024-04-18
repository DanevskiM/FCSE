#include <stdio.h>
int main() {
    long datum;
    int den, mesec;
    printf("Vnesete datum na ragjanje:\n");
    scanf("%ld", &datum);
    den = datum / 1000000;
    mesec = (datum / 10000) % 100;
    printf("Denot i mesecot na ragjanje se %02d.%02d\n", den, mesec);
    return 0;
}
/*
#include <stdio.h>
int main()
{
    float broj;
    scanf("%f", &broj);
    float pom1=broj/10000;
    float pom2=pom1/100;
    printf("%.2f", pom2);
    return 0;
}
*/
