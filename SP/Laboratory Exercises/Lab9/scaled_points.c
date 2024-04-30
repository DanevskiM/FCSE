#include <stdio.h>
float max(float *array, int n)
{
    float max = *array;
    for (int i = 1; i < n; i++)
    {
        if (*(array + i) > max)
            max = *(array + i);
    }
    return max;
}
void scale(float *array, int n)
{
    float result = 100 / max(array, n);
    for (int i = 0; i < n; i++)
    {
        *(array + i) *= result;
    }
}
int main()
{
    int n, i;
    float array[100];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%f", &array[i]);
    }
    scale(array,n);
    for (i = 0; i < n; i++)
    {
        printf("%.2f ", array[i]);
    }
    return 0;
}