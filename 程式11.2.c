#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n1,n2;
    printf("Please input two integers: ");
    scanf("%d %d",&n1,&n2);
    while (n1 !=0 && n2!=0)
    {
        if(n1>n2)
        n1%=n2;
        else
        n2%=n1;
    }
    printf("GCD is %d\n",n1+n2);
    system("pause");
    return 0;
}