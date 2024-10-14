#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define true 1
int main(){
    int n1,n2,n3,n4,a,b,c,d,a1,b1,n=0;
    srand(time(NULL));
    n1=rand()%10;
    n2=rand()%10;
    while (n1==n2)
    n2=rand()%10;
    n3=rand()%10;
    while (n1==n3||n2==n3)
    n3=rand()%10;
    n4=rand()%10;
    while (n1==n4||n2==n4||n3==n4)
    n4=rand()%10;
    /*n1=1;
    n2=2;
    n3=3;
    n4=4;*/
    printf("%d%d%d%d\n",n1,n2,n3,n4);
    while(true)
    {
        a1=0;
        b1=0;
        printf("Please input four digits (0~9): ");
        scanf("%1d%1d%1d%1d",&a,&b,&c,&d);
        if(n1==a){
            a1+=1;
        }
        if(n2==b){
            a1+=1;
        }
        if(n3==c){
            a1+=1;
        }
        if(n4==d){
            a1+=1;
        }
        if ((n1==b||n1==c||n1==d)&&(n1!=a)){
            b1+=1;
        }
        if ((n2==a||n2==c||n4==d)&&(n2!=b)){
            b1+=1;
        }
        if ((n3==a||n3==b||n3==d)&&(n3!=c)){
            b1+=1;
        }
        if ((n4==a||n4==b||n4==c)&&(n4!=d)){
            b1+=1;
        }
        if(a1==4){
            n+=1;
            printf("You got it!!%d times!!",n);
            break;
        }
        printf("The result is %dA %dB\n",a1,b1);
        n+=1;
    }
    getchar();
    return 0;
}