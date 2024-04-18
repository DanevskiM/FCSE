#include <stdio.h>
int main()
{
    int x = 1;
    int y = 2;
    int z = 3;
    int r;
    r = (x<y || y<z++);
    printf("r = %d, z = %d\n", r, z);

    r = (x>y && y<z++);
    printf("r = %d, z = %d\n", r, z);
    return 0;
}