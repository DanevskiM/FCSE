#include<stdio.h>
int main()
{
    int m,n,simetricna=0;
    scanf("%d%d",&m,&n);
    int matrix[100][100];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==matrix[j][i])
            {
                simetricna=1;
            }
            if(matrix[i][j]!=matrix[j][i])
            {
                simetricna=-1;
                break;
            }
            
        }
    }
    printf("%d\n", simetricna);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}