#include <stdio.h>
int main()
{
    int godina;
    scanf("%d", &godina);
    if((godina%4==0 && godina%100!=0) || godina%400==0)
        printf("Prestapna godina");
    else
        printf("Ne e prestapna godina");
    return 0;
}