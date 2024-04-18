/* Да се дефинира структура RabotnaNedela во која се чуваат бројот на работни часови за секој работен ден во неделата (5 дена) и број на неделата. Потоа да се дефинира структура Rabotnik за кој се чува име (низа од 50 знаци) и низа од работни недели (макс 4).

Да се имплементираат следните функции:

int maxNedela(Rabotnik *r) која за проследениот работник ќе го врати бројот на неделата со најмногу работни часови
void table(Rabotnik *r, int n) која за низата од работници ќе отпечати приказ во следниот формат:
Пример

Rab     1   2   3   4   Vkupno
Brianna 192 238 226 225 881
Ava     236 231 184 212 863
Matthew 236 235 219 243 933
Alyssa  240 254 217 228 939
Emma    247 205 204 242 898 
каде во секој ред се печати името на работникот и вкупниот број на работни часови за секоја работна недела, како и вкупниот број на часови за сите недели. Во рамките на редот податоците се разделени со знак за табулатор \t.
*/
#include<stdio.h>
#include<string.h>
typedef struct RabotnaNedela
{
    int rabotniCasovi[5];
    int broj;
}RabotnaNedela;

typedef struct Rabotnik
{
    char ime[50];
    RabotnaNedela niza[4];
}Rabotnik;

int maxNedela(Rabotnik *r)
{
    int i,j,broj;
    int vkupno=0,max=0;
    for(i=0;i<4;i++)
    {
        vkupno=0;
        for(j=0;j<5;j++)
        {
            vkupno+=r->niza[i].rabotniCasovi[j];
        }
        if(vkupno>max)
        {
            max=vkupno;
            broj=i+1;
        }
    }
    return broj;
}
void table(Rabotnik *r,int n)
{
    int i,j,m,vkupno=0,temp=0;
    printf("Rab\t");
    for(int i=0;i<4;i++)
    {
        printf("%d\t",i+1);
    }
    printf("Vkupno\n");
    for(i=0;i<n;i++)
    {
        vkupno=0;
        temp=0;
        printf("%s\t",r[i].ime);
        for(j=0;j<4;j++)
        {
            vkupno=0;
            for(m=0;m<5;m++)
            {
              vkupno+=r[i].niza[j].rabotniCasovi[m];
            }
            printf("%d\t",vkupno);
            temp+=vkupno;
        }
        printf("%d\n",temp);
    }
}
int main ()
{
    int i,j,n,m;
    scanf("%d",&n);
    Rabotnik r[n];
    for(i=0;i<n;i++)
    {
        scanf("%s",r[i].ime);
        for(j=0;j<4;j++)
        {
            for(m=0;m<5;m++)
            {
                scanf("%d",&r[i].niza[j].rabotniCasovi[m]);
            }
        }
    }
    printf("TABLE\n");
    table(r,n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", r[n / 2].ime);
    printf("%d\n", maxNedela(&r[n / 2]));
}
