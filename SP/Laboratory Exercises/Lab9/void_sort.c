#include<stdio.h>
void sort(int *a, int *b, int *c)
{
    int tmp;
    if (*a < *b){
        tmp = *a;
        *a = *b;
        *b = tmp;}
    if (*a < *c){
        tmp = *a;
        *a = *c;
        *c = tmp;}
    if (*b < *c){
        tmp = *b;
        *b = *c;
        *c = tmp;}
}
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    sort(&a, &b, &c);
    printf("%d %d %d", a, b, c);
    return 0;
}