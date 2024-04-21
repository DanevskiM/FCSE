/*Од тастатура се внесуваат цели броеви се додека не се внесе нешто што не е цел број.
Да се испечати на екран сумата на броевите во кои цифрите се подредени во опаѓачки редослед. Доколку нема такви броеви, да се испечати порака NEMA.
Објаснување на примерот:
Во првиот пример, нема ниту еден број во кој цифрите се подредени во опаѓачки редослед, па се печати NEMA.
Во вториот пример, во 4321, 21 и 81, цифрите се подредени во опаѓачки редослед, па се печати нивната сума 4423.*/
#include<stdio.h>
int main(){
    int n,sum=0;
    
    while(scanf("%d",&n)){
        int tmp=n;
        int cifra1=0, cifra2=0;
        
        while(tmp>0){
            ++cifra1;
            tmp/=10;
        }
        tmp=n;
        while(tmp%10<tmp/10%10){
            tmp/=10;
            ++cifra2;
        }
        if(cifra1-cifra2==1){
            sum+=n;}
    }
    if(sum==0){
        printf("NEMA");
        return 0;
    }
    
    printf("%d",sum);
    return 0;
}