#include <stdio.h>
void matematickaOperacija (int a, int b, char operation, int *rezultat){
    switch (operation)
    {
    case '+':
        *rezultat = a+b;
        break;
    case '-':
        *rezultat = a-b;
        break;
    case '*':
        *rezultat = a*b;
        break;
    case '/':
        *rezultat = a/b;
        break;
    case '%':
        *rezultat = a%b;
        break;
    }
}
int main(){
    int a,b,*rezultat,r;
    rezultat=&r;
    char op[]={'+','-','*','/','%'};
    scanf("%d %d",&a,&b);
    for(int i=0;i<5;i++){
        matematickaOperacija(a,b,op[i],rezultat);
        printf("%d %c %d -> %d\n",a,op[i],b,*rezultat);
    }
    return 0;
}