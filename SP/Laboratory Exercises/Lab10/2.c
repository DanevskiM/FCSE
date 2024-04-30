#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maximum 100
int contain(char *niza,int K,char bukva)
{
    int i;
    int counter=0;
    for(i=0;i<strlen(niza);++i)
    {
        if(tolower(niza[i]) == tolower(bukva))
            counter++;
    }
    if(counter==K)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int N,K;
    int counter=0;
    char C;
    scanf("%d",&N);
    scanf("%d",&K);
    scanf(" %c\n",&C);
    char array1[maximum];
    for(int i=0;i<N;++i)
    {
        fgets(array1,maximum,stdin);
        if(contain(array1,K,C))
        {
            printf("%s",array1);
            counter++;
        }
    }
    if(counter==0)
    {
        printf("NONE");
    }
    return 0;
}
