#include <stdio.h>
int divisibleByK(int number, int k)
{
  return number%k==0;
}
int nextDivisibleByK(int number, int k)
{
  int nareden=number+1;
  while(nareden%k!=0)
  {
    nareden++;
  }
  return nareden;
}
int main() {

    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);

    for (int i = a; i <= b; i++) {
        printf("%d -> %d\n", i, nextDivisibleByK(i, k));
    }

    return 0;
}
