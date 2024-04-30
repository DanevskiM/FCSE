#include <stdio.h>
void print(int n) {
    if (n == 1)
        printf("1 ");
    else {
        print(n - 1);
        printf("%d ", n);
    }
}
void triangle(int n) {
    print(n);
    printf("\n");
    if (n > 1)
        triangle(n - 1);
}
int main() {
    int n;
    scanf("%d", &n);
    triangle(n);
    return 0;
}