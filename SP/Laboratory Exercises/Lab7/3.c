#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n%2==1)
    {
        printf("GRESKA");
        return 0;
    }
    int matrix[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            matrix[i][j]+=matrix[i][n-1-j];
            matrix[i][j]+=matrix[n-1-i][j];
            matrix[i][j]+=matrix[n-1-i][n-1-j];
            printf("%d ",matrix[i][j]);
            
        }
        printf("\n");
    }
return 0;
}