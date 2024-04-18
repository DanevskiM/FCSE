#include <stdio.h>
int main()
{
    char bukva;
    scanf("%c", &bukva);
    int rez = bukva>='a' && bukva<='z';
    int rez2 = bukva>='0' && bukva<='9';
    printf("%d\n", rez);
    printf("%d", rez2);
    return 0;
}