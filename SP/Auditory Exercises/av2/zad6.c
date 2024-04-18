#include <stdio.h>
int main()
{
    int cena;
    int brojRati;
    int kamata;
    scanf("%d%d%d", &cena, &brojRati, &kamata);
    float iznos = (((float)cena*kamata)/100+cena)/brojRati;
    float suma = ((float)cena*kamata)/100+cena;
    printf("Ratata iznesuva:%.2f\n", iznos);
    printf("Vkupnata suma iznesuva:%.2f",suma);
    return 0;
}