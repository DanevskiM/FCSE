#include <stdio.h>
int main()
{
    int cena;
    scanf("%d", &cena);
    float novaCena = (cena*0.18)+cena;
    printf("%.2f", novaCena);
    return 0;
}