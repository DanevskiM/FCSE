#include <stdio.h>
int main()
{
    int poeni;
    scanf("%d", &poeni);
    if(poeni<=50) printf("5");
    else if(poeni>50 && poeni <=60) printf("6");
    else if(poeni>60 && poeni <=70) printf("7");
    else if(poeni>70 && poeni <=80) printf("8");
    else if(poeni>80 && poeni <=90) printf("9");
    else if(poeni>90 && poeni <=100) printf("10");
    else printf("Nevalidni");
    char znak = ' ';
    int posledna = poeni%10;
    if(posledna >= 1 && posledna<=3) znak='-';
    else if(posledna==8 || posledna==9 || posledna==0) znak='+';
    printf("%c", znak);
    return 0;
}