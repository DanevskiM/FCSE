#include <stdio.h>
void form(int number)
{
  if (number == 0)
    return 0;
  int i;
  for(i=0;i<number;i++)
  {
    printf("*");
  }
  printf("\n");
  form(number-1);
}
int main()
{
  int N;
  scanf("%d",&N);
  form(N);
  return 0;
}
