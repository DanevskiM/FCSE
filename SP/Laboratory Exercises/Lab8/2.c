#include <stdio.h>
int reverseNumber(int number)
{
    int reverse=0;
    while (number!=0)
    {
        int remainder=number%10;
        reverse=reverse*10+remainder;
        number/=10;
    }
    return reverse;
}
int isPalindrome(int number)
{
    if(number<10)
        return 0;
    if(number==reverseNumber(number))
        return 1;
    else
        return 0;
}
int containsDigits(int number)
{
    if(number<=0)
        return 1;
    if(number%10>4)
        return 0;
    return containsDigits(number/10);
}
int main()
{
    int A,B;
    scanf("%d %d", &A,&B);
    for(int number=A;number<=B;number++)
    {
        if (isPalindrome(number) && containsDigits(number))
        {
            printf("%d\n",number);
        }
    }
    return 0;
}
