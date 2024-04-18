#include <stdio.h>
int main()
{
    int broj;
    scanf("%d", &broj);
    int najznacajna=broj/100;
    int najmalkuznacajna=broj%10;
    printf("Najznacajna cifra:%d\n",najznacajna);
    printf("Najmalkuznacajna cifra:%d\n",najmalkuznacajna);
    return 0;
}