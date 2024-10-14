#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n1,n2,lcm,amount,num1,num2;
    printf("請輸入長方形的長(公分)為...");
    scanf("%d",&n1);
    printf("請輸入長方形的寬(公分)為...");
    scanf("%d",&n2);
    num1=n1;
    num2=n2;
    while (n1 !=0 && n2!=0)
    {
        if(n1>n2)
        n1%=n2;
        else
        n2%=n1;
    }
    //printf("GCD is %d\n",n1+n2);
    lcm=num1*num2/(n1+n2);
    printf("%d %d %d",lcm,num1,num2);
    amount=(lcm/num1)*(lcm/num2);
    printf("最少需要 %d 個相同的長方形，排成邊長為 %d 公分的正方形",amount,lcm);
    getchar();
    return 0;
    
}