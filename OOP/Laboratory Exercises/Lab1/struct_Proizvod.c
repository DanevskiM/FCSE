/* Да се креира структура Proizvod во која се чуваат податоци за кодот напрозиводот (низа од 20 знаци), единична цена на производ (цел број), бројот на достапни производи кои ги има во еден магацин (цел број) .

Потоа да се креирa структура Narachka во која се чуваат податоци за името лицето кое ја прави нарачката (низи од 15 знаци), низа од Proizvodi (максимум 10) кои ги има во нарачката, низа од бројот на нарачани производи за секоја производ посебно (максимум10) и бројот на производи во нарачката .

Треба да се направи функција со потпис

void pecatiFaktura(Narachka n)

која што ќе ги отпечати една фактура за една нарачка (n) .

Во фактурата во првиот ред се печати: Faktura za XXXXX, каде XXXXX е името на лицето кое ја прави нарачката.

Ако сите производи може да се нарачаат печатат нарачаните производи, подредени по азбучен ред според кодот на производот. Во следните редови, во секој ред посебно се печати кодот на производот, единична цена на производот, број на нарачани производи и вкупната цена на производот (сите се одделени со едно празно место) . Исто така бројот на достапни производи од тој производ да се ажурира (да се намали за бројот на нарачани производи од тој производ). Во последниот ред да се отпечати: Vkupnata suma na fakturata e XXX, каде XXX е вкупната сума за цените за сите нарачани производи.

Ако постои производ кој не може да биде нарачан затоа што во магацинот не се достапни нарачаниот број производи тогаш не може да се изготви фактура за нарачката. На екранот да се отпечати: Fakturata ne moze da se izgotvi.
*/
#include<stdio.h>
#include<string.h>

typedef struct Proizvod
{
    char kod[20];
    int cena;
    int dostapni;
}Proizvod;

typedef struct Narachka
{
    char ime[15];
    Proizvod niza[10];
    int naracani[10];
    int broj;
}Narachka;
void pecatiFaktura(Narachka narachka)
{
    int i,j,vkupno=0;
    Proizvod temp;
    printf("Faktura za %s\n",narachka.ime);

    for(i=0;i<narachka.broj;i++)
    {
        if(narachka.naracani[i] > narachka.niza[i].dostapni)
        {
            printf("Fakturata ne moze da se izgotvi");
            return;
        }
    }
    for(i=0;i<narachka.broj-1;i++)
    {
        for(j=i+1;j<narachka.broj;j++)
        {
            if(strcmp(narachka.niza[i].kod,narachka.niza[j].kod)>0)
            {
                temp=narachka.niza[i];
                narachka.niza[i]=narachka.niza[j];
                narachka.niza[j]=temp;
            }

        }
    }
    for(i=0;i<narachka.broj;i++)
    {
        printf("%s %d %d %d\n",narachka.niza[i].kod,narachka.niza[i].cena,narachka.naracani[i],(narachka.niza[i].cena*narachka.naracani[i]));
        vkupno+=narachka.niza[i].cena*narachka.naracani[i];
    }
    printf("Vkupnata suma na fakturata e %d",vkupno);
}
int main ()
{
    int i,j,n;
    Narachka narachka;
    scanf("%s",narachka.ime);
    scanf("%d",&narachka.broj);
    for(i=0;i<narachka.broj;i++)
    {
        scanf("%s",narachka.niza[i].kod);
        scanf("%d",&narachka.niza[i].cena);
        scanf("%d",&narachka.niza[i].dostapni);
    }
    for(j=0;j<narachka.broj;j++)
    {
        scanf("%d",&narachka.naracani[j]);
    }
    pecatiFaktura(narachka);
}
