/*Да се напише програма во која од стандарден влез се внесува бројот N (бројот на трансакции), а
потоа N трансакциски сметки и како резултат ги печати идентификацискиот број и вкупната
сума (со провизија) на сите трансакции платени со кредитна картичка. Во случај да нема
трансакција платена со кредитна картичка да се испечати "No credit card transaction".

Во структурата Трансакција (Transaction) треба да се чуваат следните информации:
- Идентификациски број (int)
- Платена сума (int)
- Провизија (int)
- Дали е платено со дебитна или кредитна картичка (0 - дебитна, 1 - кредитна)

Ограничување: 0 < N < 100

Структура на влезните податоци:
N
id1 sum1 commission1 type1
...
idn sumn Commissionn typen*/
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
typedef struct Transaction
{
    int id;
    int comission;
    int sum;
    int type;
}Transaction;

int main()
{
    int n, f=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        Transaction t;
        scanf("%d %d %d %d", &t.id, &t.sum, &t.comission, &t.type);
        if(t.type==1)
        {
            printf("%d %d\n", t.id, t.comission+t.sum);
            f = 1;
        }
    }
    if(f==0)
    {
        printf("No credit card transaction");
    }
    return 0;
}
