//Да се напише програма која за петцифрен број внесен од стандарден влез ќе ја пресмета сумата на цифрите на парните и непарните позиции соодветно.
//Напомена: Последната цифра во бројот се наоѓа на 0-та позиција. 
//Појаснување: За бројот 54321 цифрата на 0-та позиција е 1, додека цифрата на 4-та позиција е 5.
#include<stdio.h>
int main()
{
    int broj,s,s1;
    s=broj%10;
    s=(broj%1000)/100;
    s=broj/10000;
    s1=(broj%100)/10;
    s1=(broj%10000)/1000;
    scanf("%d", &broj );
    printf("Sumata na cifrite na parnite pozicii e %d\nSumata na cifrite na neparnite pozicii e %d",s=(broj%10)+((broj%1000)/100)+(broj/10000),s1=((broj%100)/10)+((broj%10000)/1000));
    return 0;
}