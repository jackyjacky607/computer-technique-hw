#include <stdio.h>

int main(){
    int nums[10]={0};int a,b,i,temp;
    printf("½Ð¿é¤J A:B.....");
    scanf("%d:%d",&a,&b);
    for(i=a;i<=b;i++){
        temp=i;
        while (temp!=0)
        {
            nums[temp%10]+=1;
            temp/=10;
        }
        
    }
    for (i=0;i<10;i++)
        {
            printf("%d ",nums[i]);
        }
}