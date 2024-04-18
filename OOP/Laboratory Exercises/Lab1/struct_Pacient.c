/* Во програмскиот јазик C да се креира структура Pacient и истата треба да содржи: (5 поени)

Име и презиме на пациентот ( низа од макс. 100 знаци)
Дали е здраствено осигуран (1-да, 0-не)
Број на прегледи во текот на последниот месец (цел број)
Да се креира структура MaticenDoktor, која во себе содржи: (5 поени)

Име на докторот (низа од 100 знаци)
Број на пациенти (цел број)
Листа од пациенти (низа од максимум 200 елементи од структурата Pacient)
Цена на преглед (децимален број)
Да се креираат метода najuspesen_doktor, која прима низа од променливи од типот MaticenDoktor и нивниот број; и го печати името, заработената сума и бројот на прегледи на оној доктор кој заработил најголема сума од пациенти кои ги прегледувал приватно (не се здраствено осигурани) (10 поени). Доколку два или повеќе доктори имаат иста сума, тогаш се печати оној доктор кој има направено најголем број на прегледи вкупно во текот на последниот месец. (20 поени)
*/
#include<stdio.h>
#include<string.h>
#define MAX 100
#define MAX2 200
typedef struct Pacient
{
    char ime[MAX];
    int osiguran;
    int brojNaPregledi;
}Pacient;

typedef struct MaticenDoktor
{
    char ime[MAX];
    int broj;
    float cena;
    Pacient niza[MAX2];
}MaticenDoktor;

void najuspesen_doktor(MaticenDoktor *md, int n)
{
    int i,j,pregled=0,temp2,temp3;
    float vkupno=0;
    float temp;
    for(i=0;i<n;i++)
    {
        pregled=0;
        temp=0;
        for(j=0;j<md[i].broj;j++)
        {
            if(md[i].niza[j].osiguran == 0)
            {
                temp+=md[i].cena*(md[i].niza[j].brojNaPregledi);
            }
            pregled+=md[i].niza[j].brojNaPregledi;
            if(temp>vkupno)
            {
                temp3=pregled;
                vkupno=temp;
                temp2=i;
            }
            else if(temp==vkupno)
            {
                if(pregled>temp3)
                {
                    temp3=pregled;
                    vkupno=temp;
                    temp2=i;
                }
            }
        }
    }
    printf("%s %.2f %d",md[temp2].ime,vkupno,temp3);

}
int main ()
{
    int i,j,n;
    scanf("%d",&n);
    MaticenDoktor md[n];
    for(i=0;i<n;i++)
    {
        scanf("%s",md[i].ime);
        scanf("%d",&md[i].broj);
        scanf("%f",&md[i].cena);
        for(j=0;j<md[i].broj;j++)
        {
            scanf("%s",md[i].niza[j].ime);
            scanf("%d",&md[i].niza[j].osiguran);
            scanf("%d",&md[i].niza[j].brojNaPregledi);
        }
    }
    najuspesen_doktor(md,n);
}
