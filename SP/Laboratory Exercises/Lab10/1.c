#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char array1[100];
    scanf("%s",array1);
    int n=strlen(array1)/2; //Ako se site primeri paren broj znaci
    int length=strlen(array1);
    for (i=n;i<length;i++)
    {
        printf("%c",array1[i]);
    }
    for (i=0;i<n;i++)
    {
        printf("%c",array1[i]);
    }
    return 0;
}
