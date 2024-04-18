//Да се прочитаат два цели броеви од тастатура и на екран да се испечатат нивните сума и производ.
#include<stdio.h>
int main()
{
    int a,b,s,p;
    scanf("%d%d", &a, &b);
    s=a+b;
    p=a*b;
    printf("%d\n%d", s=a+b, p=a*b);
    return 0;
}