/* Да се креира структура SkiLift во која се чуваат податоци за името на ски лифтот (низа од 15 знаци), максимален број на корисници што може да опслужи на едно возење, дали е пуштен во функција.

Потоа да се креирa структура SkiCenter во која се чуваат податоци за името на скијачкиот центар, држава во која се наоѓа (низи од 20 знаци), низа од ски лифтови (макс 20) што ги има и број на ски лифтови.

Треба да се направи функција со потпис

void najgolemKapacitet(SkiCenter *sc, int n)
која што ќе го отпечати ски центарот што има најголем капацитет за опслужување скијачи (вкупниот број на скијачи кои може да се опслужуваат во еден момент вкупно на сите ски лифтови во центарот). Доколку два ски центри имаат ист капацитет, тогаш се печати оној кој има поголем број на ски лифтови. Притоа треба да се испечатат во посебен ред името, државата и капацитетот на ски центарот. Кога се пресметува капацитет на еден ски центар во предвид се земаат само ски лифтовите кои се поставени дека се во функција.
*/
#include<stdio.h>
#include<string.h>
typedef struct SkyLift
{
    char ime[15];
    int maksimalenBroj;
    int upotreba;
}SkyLift;

typedef struct SkiCenter
{
    char ime[20];
    char drzava[20];
    SkyLift niza[20];
    int broj;
}SkiCenter;
int kapacitet(SkiCenter sc)
{
    int i,vkupno=0;
    for(i=0;i<sc.broj;i++)
    {
        if(sc.niza[i].upotreba == 1)
        {
            vkupno+=sc.niza[i].maksimalenBroj;
        }
    }
    return vkupno;
}
void najgolemKapacitet(SkiCenter *sc, int n)
{
    int i,j;
    int temp,max=0,temp2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<sc[i].broj;j++)
        {
            temp=kapacitet(sc[i]);
            if(temp>max)
            {
                max=temp;
                temp2=i;
            }
            else if(temp==max)
            {
                if(sc[i-1].broj>sc[i].broj)
                {
                    continue;
                }
                else
                {
                    max=temp;
                    temp2=i;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(i==temp2)
        {
            printf("%s\n",sc[i].ime);
            printf("%s\n",sc[i].drzava);
            printf("%d",max);
        }
    }
}
int main ()
{
    int i,j,n;
    SkiCenter sc[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",sc[i].ime);
        scanf("%s",sc[i].drzava);
        scanf("%d",&sc[i].broj);
        for(j=0;j<sc[i].broj;j++)
        {
            scanf("%s",sc[i].niza[j].ime);
            scanf("%d",&sc[i].niza[j].maksimalenBroj);
            scanf("%d",&sc[i].niza[j].upotreba);
        }
    }
    najgolemKapacitet(sc,n);
}
