#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int matrix[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                matrix[i][j]*=-1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%3d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}