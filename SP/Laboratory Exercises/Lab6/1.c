// Од стандарден влез да се вчита број N и потоа да се вчитаат N елементи во една низа.
// Внесената низа да се трансформира на начин што парните елементи ќе се
//зголемат за 1, а непарните ќе се намалат за 1.
// Трансформираната низа да се испечати на стандарден излез, така што
//елементите ќе се одвоени со празно место меѓу нив.
#include<stdio.h>
int main()
{
    int N;
    //N-broj na elementi
    scanf("%d",&N);
    //Vnesuvanje broevi vo array
    int array[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&array[i]);
    }
    //Parni i neparni, zgolemuvanje i namaluvanje
    for(int i=0;i<N;i++)
    {
        if(array[i]%2==0)
        array[i]++;
        else if(array[i]%2)
        array[i]--;
    }
    //Pecatenje na array
    for(int i=0;i<N;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}
