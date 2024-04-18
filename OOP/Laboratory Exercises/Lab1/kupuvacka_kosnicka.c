/*Da se napise programa vo koja od standarden vlez se vcituva N(brojot na
proizvodi), a potoa se vcituvaat podatocite za N proizvodi(ime,cena,
kolicina). Programata treba na standarden izlez da ja otpecati listata
na kupeni proizvodi i vkupnata suma koja treba da se plati vo sledniot oblik:
1. Flips        10.00 x 3  = 30.00
2. CocaCola     75.00 x 2  = 150.00
3. ChokoBanana  5.00  x 10 = 50.00
Total:230.00
*/
#include<stdio.h>
typedef struct Proizvod
{
    char name[15];
    float price;
    float quantity;
}Proizvod;

void printProizvod(int i, Proizvod p)
{
    printf("%d. %s\t%.2f x %.1f = %.2f\n", i, p.name, p.price, p.quantity,
           p.price * p.quantity);
}
int main()
{
    float total = 0;
    int i, n;
    scanf("%d", &n);
    Proizvod p[n];
    for(int i=1;i<=n; i++)
    {
        scanf("%s%f%f",&p[i].name, &p[i].price, &p[i].quantity);
        total +=(p[i].price * p[i].quantity);
        printProizvod(i ,p[i]);
    }
    printf("Total: %.2f", total);
    return 0;
}
